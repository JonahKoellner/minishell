/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:23 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/08 09:09:13 by jonahkollne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_ctrl_c(int signo, siginfo_t *client_info, void *param)
{
	(void)signo;
	(void)client_info;
	(void)param;
	new_line();
}

void	sig_ctrl_d(int signo, siginfo_t *client_info, void *param)
{
	(void)signo;
	(void)client_info;
	(void)param;
	exit(0);
}
