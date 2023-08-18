/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:23 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/18 18:04:45 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_Command	bad_quote(char *input)
{
	ft_printf_fd(STDERR, "minishell: Quote Error (try closing them ;-) )");
	add_history(input);
	free(input);
	return ((t_Command){.err = -1});
}

t_Command	empty_input(char *input)
{
	free(input);
	return ((t_Command){.err = 0});
}
