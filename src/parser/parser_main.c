/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:01:12 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/20 20:22:10 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Token	redirect_decide(t_Token token, int *i)
{
	if (token.lexeme[0] == '>' && token.lexeme[1] == ' ')
		token.type = TOKEN_GREAT;
	else if (token.lexeme[0] == '>' && token.lexeme[1] == '>')
		token.type = TOKEN_GREAT_GREAT;
	else if (token.lexeme[0] == '<' && token.lexeme[1] == ' ')
		token.type = TOKEN_LESS;
	else if (token.lexeme[0] == '<' && token.lexeme[1] == '<')
		token.type = TOKEN_LESS_LESS;
	else if (token.lexeme[0] == '|' && token.lexeme[1] == ' ')
		token.type = TOKEN_PIPE;
	if (token.type == TOKEN_GREAT_GREAT || TOKEN_LESS_LESS)
		*i++;
	free(token.lexeme);
	return (token);
}

t_Token	command_decide(char c, int *i, int l)
{
	t_Token		token;

	token.type = TOKEN_COMMAND_NAME;
	*i += l;
	if (c == 'e')
		token.lexeme = fillstr("echo", 0, l - 1);
	else if (c == 'c')
		token.lexeme = fillstr("cd", 0, l - 1);
	else if (c == 'p')
		token.lexeme = fillstr("pwd", 0, l - 1);
	else if (c == 'x')
		token.lexeme = fillstr("export", 0, l - 1);
	else if (c == 'u')
		token.lexeme = fillstr("unset", 0, l - 1);
	else if (c == 'v')
		token.lexeme = fillstr("env", 0, l - 1);
	else if (c == 'q')
		token.lexeme = fillstr("exit", 0, l - 1);
	return (token);
}

t_Token	get_next_token(char *command)
{
	t_Token		token;
	static int	i = 0;

	if (!command)
		i = 0;
	while (command[i] == ' ', command[i] == '\t', command[i] == '\n')
		i++;
	if (command[i] == NULL)
		return ((t_Token){NULL, TOKEN_END});
	if (!strncmp(&command[i], "echo", 4))
		return (command_decide('e', &i, 4));
	else if (!strncmp(&command[i], "cd", 2))
		return (command_decide('c', &i, 2));
	else if (!strncmp(&command[i], "pwd", 3))
		return (command_decide('p', &i, 3));
	else if (!strncmp(&command[i], "export", 6))
		return (command_decide('x', &i, 6));
	else if (!strncmp(&command[i], "unset", 5))
		return (command_decide('u', &i, 5));
	else if (!strncmp(&command[i], "env", 3))
		return (command_decide('v', &i, 3));
	else if (!strncmp(&command[i], "exit", 4))
		return (command_decide('q', &i, 4));
	return (get_next_token_qte(command, &i));

}

t_Token	get_next_token_qte(char *command, int *i)
{
	t_Token	token;

	if(command[*i] == '\'')
	{
		token.type = TOKEN_LITERAL_CHARS;
		token.lexeme = quote(command, &i);
		return (token);
	}
	else if(command[*i] == '\"')
	{
		token.type = TOKEN_LITERAL_STRING;
		token.lexeme = quote(command, &i);
		return (token);
	}
	return (get_next_token_rst(command, &i));
}
//gets the next token, after complete command call with command = NULL to reset
t_Token	get_next_token_rst(char *command, int *i)
{
	t_Token	token;
	int		j;

	if (command[*i] == '$')
	{
		token.type = TOKEN_DOLLAR;
		return (token);
	}
	if (ft_isalnum(command[*i]))
	{
		j = i;
		while (ft_isalnum(command[*i]))
			*i++;
		token.lexeme = fillstr(command, j, *i);
		token.type = TOKEN_WORD;
		return (token);
	}
	if (command[*i] == '>' || command[*i] != '<' || command[*i] != '|')
	{
		token.type = TOKEN_REDIRECT;
		token.lexeme = fillstr(command, *i, *i + 1);
		*i++;
		return (redirect_decide(token, &i));
	}
	return (token);
}
