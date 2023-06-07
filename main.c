/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/06/07 12:50:23 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include <string.h>


int	print_history(t_history *history)
{
	t_history *iter;

	iter = history;
	printf("print history:\n");
	while (iter != NULL)
	{
		printf("%s\n", iter->command);
		iter = iter->previous;
	}
	return (0);
}

int	main(void)
{
	char *command;
	t_history *current;
	t_history *previous;

	previous = NULL;

	while (1)
	{
		current = malloc(sizeof(t_history));
		command = malloc(sizeof(char) * 1000);
		printf("\nminishell>:$ ");
		fgets(command, 1000, stdin);
		printf("\n exec %s\n", command);
		current->command = command;
		current->previous = previous;
		previous = current;
		if (strncmp(current->command, "history", 8) == 0)
			print_history(current);
	}
	return (1);
}
