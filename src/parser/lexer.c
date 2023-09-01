/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:01:12 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/01 14:32:46 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Token	redirect_decide(t_Token token, int *i)
{
	if (token.lexeme[0] == '>' && token.lexeme[1] != '>')
		token.type = TOKEN_GREAT;
	else if (token.lexeme[0] == '>' && token.lexeme[1] == '>')
		token.type = TOKEN_GREAT_GREAT;
	else if (token.lexeme[0] == '<' && token.lexeme[1] != '<')
		token.type = TOKEN_LESS;
	else if (token.lexeme[0] == '<' && token.lexeme[1] == '<')
		token.type = TOKEN_LESS_LESS;
	else if (token.lexeme[0] == '|' && token.lexeme[1] != '|')
		token.type = TOKEN_PIPE;
	if (token.type == TOKEN_GREAT_GREAT || token.type == TOKEN_LESS_LESS)
		*i += 1;
	free(token.lexeme);
	return (token);
}

t_Token	command_decide(char c, int *i, int l)
{
	t_Token		token;

	token.type = TOKEN_COMMAND_NAME;
	*i += l;
	if (c == 'e')
		token.lexeme = ft_strdup("echo");
	else if (c == 'c')
		token.lexeme = ft_strdup("cd");
	else if (c == 'p')
		token.lexeme = ft_strdup("pwd");
	else if (c == 'x')
		token.lexeme = ft_strdup("export");
	else if (c == 'u')
		token.lexeme = ft_strdup("unset");
	else if (c == 'v')
		token.lexeme = ft_strdup("env");
	else if (c == 'q')
		token.lexeme = ft_strdup("exit");
	return (token);
}

t_Token	get_next_token(char *input)
{
	static int	i = 0;

	if (!input || input[i] == '\0')
		return (i = 0, (t_Token){TOKEN_END, NULL});
	while (input[i] == ' ' || input[i] == '\t' || input[i] == '\\')
		i++;
	if (!strncmp(&input[i], "echo ", 5))
		return (command_decide('e', &i, 4));
	else if (!strncmp(&input[i], "cd ", 3))
		return (command_decide('c', &i, 2));
	else if (!strncmp(&input[i], "pwd ", 4))
		return (command_decide('p', &i, 3));
	else if (!strncmp(&input[i], "export ", 7))
		return (command_decide('x', &i, 6));
	else if (!strncmp(&input[i], "unset ", 6))
		return (command_decide('u', &i, 5));
	else if (!strncmp(&input[i], "env ", 4))
		return (command_decide('v', &i, 3));
	else if (!strncmp(&input[i], "exit ", 5))
		return (command_decide('q', &i, 4));
	return (get_next_token_qte(input, &i));
}

t_Token	get_next_token_qte(char *input, int *i)
{
	t_Token	token;

	if (input[*i] == '\'')
	{
		token.type = TOKEN_CHARS;
		token.lexeme = quote(input, i);
		return (token);
	}
	else if (input[*i] == '\"')
	{
		token.type = TOKEN_STRING;
		token.lexeme = quote(input, i);
		return (token);
	}
	return (get_next_token_rst(input, i));
}

t_Token	get_next_token_rst(char *input, int *i)
{
	t_Token	token;
	int		j;

	if (input[*i] == '$')
		return (lex_dollar(input, i));
	else if (!is_unquotable(input[*i]))
	{
		j = *i;
		while (!is_unquotable(input[*i]))
			*i += 1;
		token.lexeme = fillstr(input, j, *i);
		token.type = TOKEN_WORD;
		return (token);
	}
	else if (input[*i] == '>' || input[*i] != '<' || input[*i] != '|')
	{
		token.type = TOKEN_REDIRECT;
		token.lexeme = ft_substr(input, *i, 2);
		*i += 1;
		return (redirect_decide(token, i));
	}
	else if (input[*i] == '\n' || input[*i] == '\0')
		return ((t_Token){TOKEN_END, ft_substr(input, *i, 1)});
	return ((t_Token){ERR, NULL});
}
