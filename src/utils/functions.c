/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:58:19 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/08 00:13:28 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char *string, int n_flag)
{
	printf("\n%s", string);
	if (n_flag)
	{
		printf("\n");
	}
	return (0);
}
