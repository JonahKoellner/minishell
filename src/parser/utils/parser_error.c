/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/22 14:05:37 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	unexpected_token(t_Token err_token)
{
	if (err_token.type != TOKEN_END)
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `%s",
			err_token.lexeme);
	else
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `\\n");
	free(err_token.lexeme);
	ft_printf_fd(STDERR, "\n");
	return ((t_Command){.err = -3});
}

t_Command	unclosed_pipe(void)
{
	ft_printf_fd(STDERR, "minishell: Parser Error, unclosed Pipe");
	return ((t_Command){.err = -4});
}

t_Command	open_error(int in_f, int out_f)
{
	if (in_f < 0)
		ft_printf_fd(STDERR, "minishell: Error Opening Input File");
	if (out_f < 0)
		ft_printf_fd(STDERR, "minishell: Error Opening Output File");
	return ((t_Command){.err = -8});
}
