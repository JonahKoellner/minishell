/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:18:23 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/02 12:57:52 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sig_ctrl_c(int signo, siginfo_t *client_info, void *param)
{
	(void)signo;
	(void)client_info;
	(void)param;
	new_line("");
}

void	sig_ctrl_d(int signo, siginfo_t *client_info, void *param)
{
	(void)signo;
	(void)client_info;
	(void)param;
	exit(0);
}
