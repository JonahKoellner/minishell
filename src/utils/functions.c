/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:58:19 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/02 13:01:12 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo(char *string, int n_flag)
{
	printf("\n%s", string);
	if (n_flag)
	{
		printf("\n");
	}
	return (0);
}
