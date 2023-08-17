/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:01:12 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/17 04:31:55 by mreidenb         ###   ########.fr       */
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
	else if (token.lexeme[0] == '|' && token.lexeme[1] == ' ')
		token.type = TOKEN_PIPE;
	if (token.type == TOKEN_GREAT_GREAT || TOKEN_LESS_LESS)
		*i++;
	else
		token.lexeme[1] = 0;
	return (token);
}

t_Token	command_decide(char c, int *i, int l)
{
	t_Token		token;

	token.type = TOKEN_COMMAND_NAME;
	*i += l;
	if (c == 'n')
		token.lexeme = ft_strdup("echo -n");
	else if (c == 'e')
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

t_Token	get_next_token(char *input, t_Token token)
{
	static int	i = 0;

	if (!input)
		i = -1;
	while (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
		i++;
	if (input[i] == NULL || i++ == -1)
		return ((t_Token){NULL, TOKEN_END});
	if (!strncmp(&input[i], "echo -n", 7))
		return (command_decide('n', &i, 7));
	if (!strncmp(&input[i], "echo", 4))
		return (command_decide('e', &i, 4));
	else if (!strncmp(&input[i], "cd", 2))
		return (command_decide('c', &i, 2));
	else if (!strncmp(&input[i], "pwd", 3))
		return (command_decide('p', &i, 3));
	else if (!strncmp(&input[i], "export", 6))
		return (command_decide('x', &i, 6));
	else if (!strncmp(&input[i], "unset", 5))
		return (command_decide('u', &i, 5));
	else if (!strncmp(&input[i], "env", 3))
		return (command_decide('v', &i, 3));
	else if (!strncmp(&input[i], "exit", 4))
		return (command_decide('q', &i, 4));
	return (get_next_token_qte(input, &i));
}

t_Token	get_next_token_qte(char *input, int *i)
{
	t_Token	token;

	if (input[*i] == '\'')
	{
		token.type = TOKEN_LITERAL_CHARS;
		token.lexeme = quote(input, &i);
		return (token);
	}
	else if (input[*i] == '\"')
	{
		token.type = TOKEN_LITERAL_STRING;
		token.lexeme = quote(input, &i);
		return (token);
	}
	return (get_next_token_rst(input, &i));
}

t_Token	get_next_token_rst(char *input, int *i)
{
	t_Token	token;
	int		j;

	if (input[*i] == '$')
		return (lex_dollar(input, &i));
	if (!is_unquotable(input[*i]))
	{
		j = i;
		while (!is_unquotable(input[*i]))
			*i++;
		token.lexeme = fillstr(input, j, *i);
		token.type = TOKEN_WORD;
		return (token);
	}
	if (input[*i] == '>' || input[*i] != '<' || input[*i] != '|')
	{
		token.type = TOKEN_REDIRECT;
		token.lexeme = fillstr(input, *i, *i + 1);
		*i++;
		return (redirect_decide(token, &i));
	}
	return (token);
ft_substr();
}
