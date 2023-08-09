/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:23 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/09 09:31:19 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Signal Handler function for ctrl_c.
 * Function prints a new line.
 * @param signo (int).
 * @param client_info (siginfo_t *).
 * @param param (void *).
 * @return No return value.
 */
void	sig_ctrl_c(int signo, siginfo_t *client_info, void *param)
{
	(void)signo;
	(void)client_info;
	(void)param;
	new_line("");
}

/**
 * Signal Handler function for ctrl_d.
 * Function exits the Shell.
 *
 * @param signo (int).
 * @param client_info (siginfo_t *).
 * @param param (void *).
 * @return No return value.
 */
void	sig_ctrl_d(int signo, siginfo_t *client_info, void *param)
{
	(void)signo;
	(void)client_info;
	(void)param;
	exit(0);
}
