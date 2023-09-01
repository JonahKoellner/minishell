/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/01 14:18:03 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	unexpected_token(t_Token err_token)
{
	if (err_token.type != TOKEN_END)
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `%s\n",
			err_token.lexeme);
	else
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `\\n\n");
	free(err_token.lexeme);
	ft_printf_fd(STDERR, "\n");
	return ((t_Command){.err = -3});
}

t_Command	unclosed_pipe(void)
{
	ft_printf_fd(STDERR, "minishell: Parser Error, unclosed Pipe\n");
	return ((t_Command){.err = -4});
}

t_Command	open_error(int in_f, int out_f)
{
	if (in_f < 0)
		ft_printf_fd(STDERR, "minishell: Error Opening Input File\n");
	if (out_f < 0)
		ft_printf_fd(STDERR, "minishell: Error Opening Output File\n");
	return ((t_Command){.err = -8});
}
