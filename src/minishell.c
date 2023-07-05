/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/05 18:53:16 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"


int	main(void)
{
	char	*command;

	while (1)
	{
		command = malloc(sizeof(char) * 1000);
		new_line();
		fgets(command, 1000, stdin);
		printf("\n exec %s\n", command);
		if (strncmp(command, "exit", 4) == 0)
			break ;
	}
	return (1);
}
