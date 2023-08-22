/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:19:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/22 13:16:57 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_unused_tokens(t_Token *tokens)
{
	int	i;

	i = 0;
	while (tokens[i].type != TOKEN_END)
	{
		if (!is_allowed_token(tokens[i]) && tokens[i].lexeme)
			free(tokens[i].lexeme);
		i++;
	}
}

int	cmd_arg_count(t_Token *tokens)
{
	int	i;
	int	n;

	i = 0;
	n = -1;
	while (tokens[i].type != TOKEN_PIPE && tokens[i].type != TOKEN_END)
	{
		if (is_allowed_token(tokens[i]))
			n++;
		i++;
	}
	//ft_printf("arg count %i \n", n);
	return (n);
}

int	cmd_count(t_Token *tokens)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (tokens[i].type != TOKEN_END)
	{
		if (tokens[i].type != TOKEN_PIPE)
			n++;
		i++;
	}
	return (n);
}

t_Command	std_command(t_Command command, t_Token *tokens)
{
	int	i;

	i = 0;
	command.type.type = ERR;
	command.type.lexeme = NULL;
	command.arg_count = cmd_arg_count(tokens);
	command.arguments = malloc((command.arg_count + 1) * sizeof(t_Token));
	while (i <= command.arg_count)
		command.arguments[i++].type = ERR;
	command.arg_i = 0;
	command.in_file = NULL;
	command.out_file = NULL;
	return (command);
}

int	is_unquotable(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '<' || c == '>'
		|| c == '(' || c == ')' || c == '$' || c == '`' || c == '\\'
		|| c == '"' || c == '\'')
		return (2);
	else if (c == ' ' || c == '\n' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int	tokencount(const char *s)
{
	int		i;
	int		wrd;
	char	qte;

	qte = 0;
	wrd = 0;
	i = 0;
	while (*s)
	{
		if ((*s == '\'' || *s == '"') && qte == 0)
		{
			qte = *s;
			i++;
		}
		if (!(*s == ' ' || *s == '\n' || *s == '\t') && wrd == 0 && qte == 0)
			wrd = ++i;
		if (*s == ' ' || *s == '\n' || *s == '\t')
			wrd = 0;
		s++;
		if (*s == qte)
			qte = 0;
	}
	ft_printf("%i\n", i);
	return (i * ((qte - 1) * -1));
}

t_Token	lex_dollar(char *input, int *i)
{
	int		j;
	t_Token	token;

	i = 0;
	token.type = TOKEN_WORD;
	if (is_unquotable(input[*i + 1]) == 1)
		token.lexeme = ft_strdup("$");
	else
	{
		j = *i;
		token.type = TOKEN_VARIABLE;
		while (is_unquotable(input[*i]) == 0 || is_unquotable(input[*i]) == 2)
		{
			if (is_unquotable(input[*i] == 2))
			{
				unexpected_token((t_Token){ERR, ft_substr(input, *i, 1)});
				token.type = ERR;
				break ;
			}
			*i += 1;
		}
		token.lexeme = fillstr(input, j, *i);
	}
	return (token);
}

int	is_allowed_token(t_Token token)
{
	if (token.type == TOKEN_WORD
		|| token.type == TOKEN_VARIABLE
		|| token.type == TOKEN_LITERAL_CHARS
		|| token.type == TOKEN_LITERAL_STRING
		|| token.type == TOKEN_COMMAND_NAME)
		return (1);
	else
		return (0);
}
