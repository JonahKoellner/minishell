/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:23:21 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/31 13:48:03 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*open_redirect(int in_fd, int out_fd)
{
	int	og_in;
	int	og_out;
	int	*ogs;

	og_in = dup(0);
	og_out = dup(1);
	dup2(out_fd, STDOUT);
	dup2(in_fd, STDIN);
	if (in_fd > 2)
		close(in_fd);
	if (out_fd > 2)
		close(out_fd);
	ogs = ft_calloc(2, sizeof(int));
	return (ogs[0] = og_in, ogs[1] = og_out, ogs);
}

int	close_redirect(int og_in, int og_out)
{
	dup2(og_out, STDOUT);
	dup2(og_in, STDIN);
	close(og_in);
	close(og_out);
	return (0);
}
