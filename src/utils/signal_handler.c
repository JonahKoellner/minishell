/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:23 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/25 16:31:29 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Signal Handler function for ctrl_c.
 * Function prints a new line.
 * @param signo (int).
 * @param client_info (siginfo_t *).
 * @param param (void *).
 * @return No return value.
 */
void	sig_ctrl_c(void)
{
	// (void)client_info;
	// (void)param;
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
void	sig_ctrl_d(void)
{
	// (void)client_info;
	// (void)param;
	// custom_exit(param);
	custom_exit(NULL);
}

void	sig_ctrl_quit(void)
{
	// (void)client_info;
	// (void)param;
	custom_exit(NULL);
}

void	sig_decide(int sig)
{
	if (sig == SIGINT)
		sig_ctrl_c();
	else if (sig == SIGQUIT)
		sig_ctrl_quit();
}
