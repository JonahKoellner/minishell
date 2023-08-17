/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:23 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/17 12:21:55 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_decide(int sig, siginfo_t *client_info, void *param)
{
	if (sig == SIGINT)
		sig_ctrl_c(client_info, param);
	else if (sig == SIGQUIT)
		sig_ctrl_quit(client_info, param);
}

/**
 * Signal Handler function for ctrl_c.
 * Function prints a new line.
 * @param signo (int).
 * @param client_info (siginfo_t *).
 * @param param (void *).
 * @return No return value.
 */
void	sig_ctrl_c(siginfo_t *client_info, void *param)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
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
void	sig_ctrl_d(siginfo_t *client_info, void *param)
{
	(void)client_info;
	(void)param;
	custom_exit(param);
}


void	sig_ctrl_quit(siginfo_t *client_info, void *param)
{
	(void)client_info;
	(void)param;
	custom_exit(param);
}