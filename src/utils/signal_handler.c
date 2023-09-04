/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:23 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/09/03 02:49:47 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

///  Signal Handler function for ctrl_c.
///  Function prints a new line.
///  @param void (void)
///  @return No return value.
void	sig_ctrl_c(void)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

///  Signal Handler function for ctrl_d.
///  Exits shell, by sendin EOF
///  @param void (void)
///  @return No return value.
void	sig_ctrl_d(void)
{
	custom_exit(NULL);
}

/// Signal Handler function for ctrl_\.
/// Exits shell by sending SIGQUIT singal.
/// @param void (void)
/// @return No return value.
void	sig_ctrl_quit(void)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/// Signal Handler function for ctrl_d.
/// Function exits the Shell.
///  @param signo (int).
///  @param client_info (siginfo_t *).
///  @param param (void *).
///  @return No return value.
void	sig_decide(int sig)
{
	if (sig == SIGINT)
		sig_ctrl_c();
	else if (sig == SIGQUIT)
		sig_ctrl_quit();
}
