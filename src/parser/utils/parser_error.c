/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:26 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/10 19:45:55 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unexpected_token(t_Token err_token)
{
	if (err_token.type != TOKEN_END)
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `%s",
			err_token.lexeme);
	else
		ft_printf_fd(STDERR, "minishell: Parser Error Near unexp. Token `\\n");
	free(err_token.lexeme);
	return (-3);
}

int	unclosed_pipe(void)
{
	ft_printf_fd(STDERR, "minishell: Parser Error, unclosed Pipe");
	return (-4);
}
