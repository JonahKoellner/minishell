/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:19:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/03 22:43:29 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_command(t_Command cmd)
{
	if (cmd.type.lexeme != NULL)
		free(cmd.type.lexeme);
	while (--cmd.arg_i >= 0)
		if (cmd.arguments[cmd.arg_i].lexeme != NULL)
			free(cmd.arguments[cmd.arg_i].lexeme);
	if (cmd.arguments != NULL)
		free(cmd.arguments);
	if (cmd.next != NULL)
	{
		free_command(*(t_Command *)cmd.next);
		free(cmd.next);
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
		if (!is_allowed_token(tokens[i]))
			i += 2;
		else
			i++;
	}
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
		if (tokens[i].type == TOKEN_PIPE)
			n++;
		i++;
	}
	return (n);
}

t_Command	std_command(t_Token *tokens)
{
	t_Command	command;
	int			i;

	i = 0;
	command.type.type = ERR;
	command.type.lexeme = NULL;
	command.arg_count = cmd_arg_count(tokens);
	command.arguments = ft_calloc((command.arg_count + 1), sizeof(t_Token));
	while (i <= command.arg_count)
	{
		command.arguments[i].lexeme = NULL;
		command.arguments[i++].type = ERR;
	}
	command.arg_i = 0;
	command.in_fd = STDIN;
	command.out_fd = STDOUT;
	command.err = 0;
	command.next = NULL;
	command.count = cmd_count(tokens);
	return (command);
}

int	is_allowed_token(t_Token token)
{
	if (token.type == TOKEN_WORD
		|| token.type == TOKEN_VARIABLE
		|| token.type == TOKEN_CHARS
		|| token.type == TOKEN_STRING
		|| token.type == TOKEN_COMMAND_NAME)
		return (1);
	else
		return (0);
}
