/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/06/08 21:06:53 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include <string.h>


int	main(void)
{
	char	*command;

	while (1)
	{
		command = malloc(sizeof(char) * 1000);
		printf("\nminishell>:$ ");
		fgets(command, 1000, stdin);
		printf("\n exec %s\n", command);
		if (strncmp(command, "exit", 4) == 0)
			break ;
	}
	return (1);
}
