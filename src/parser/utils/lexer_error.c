/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:23 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/01 14:18:22 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	bad_quote(char *input)
{
	ft_printf_fd(STDERR, "minishell: Quote Error (try closing them ;-) )\n");
	add_history(input);
	free(input);
	return ((t_Command){.err = -1});
}

t_Command	empty_input(char *input)
{
	free(input);
	return ((t_Command){.err = 0});
}
