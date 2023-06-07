/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:35:46 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/06/07 12:41:31 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_history
{
	struct s_history *previous;
	char *command;
}t_history;
