/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:23 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/27 17:50:06 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bad_quote(char *input)
{
	ft_printf_fd(STDERR, "minishell: Quote Error (try closing them ;-) )");
	add_history(input);
	free(input);
	return (-1);
}

int	empty_input(char *input)
{
	free(input);
	return (0);
}
