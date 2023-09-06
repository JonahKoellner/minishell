/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/06 19:14:22 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	unexpected_token(t_Token err_token, t_Command cmd)
{
	if (err_token.type != TOKEN_END)
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `%s\n",
			err_token.lexeme);
	else
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `\\n\n");
	free(err_token.lexeme);
	// ft_printf_fd(STDERR, "\n");
	free_command(cmd);
	return ((t_Command){.err = -3});
}

t_Command	unclosed_pipe(t_Command cmd)
{
	free_command(cmd);
	ft_printf_fd(STDERR, "minishell: Parser Error, unclosed Pipe\n");
	return ((t_Command){.err = -4});
}

t_Command	open_error(int in_f, int out_f, t_Command cmd)
{
	if (in_f < 0)
		ft_printf_fd(STDERR, "minishell: Error Opening Input File\n");
	if (out_f < 0)
		ft_printf_fd(STDERR, "minishell: Error Opening Output File\n");
	free_command(cmd);
	return ((t_Command){.err = -8});
}
