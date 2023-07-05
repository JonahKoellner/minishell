/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/07 17:56:18 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/42-libft/libft.h"

#include "minishell.h"


int	main(void)
{
	char	*command;

	while (1)
	{
		command = readline("minishell>:$");
		add_history(command);
		printf("exec %s\n", command);
		if (strncmp(command, "exit", 4) == 0)
			break ;
	}
	return (1);
}
