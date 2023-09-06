/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:23:21 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 15:11:20 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*open_redirect(int in_fd, int out_fd, int *pip)
{
	int	*og;

	og = NULL;
	if (!pip)
	{
		og = ft_calloc(2, sizeof(int));
		og[0] = dup(STDIN);
		og[1] = dup(STDOUT);
	}
	dup2(in_fd, STDIN);
	dup2(out_fd, STDOUT);
	if (in_fd > 2)
		close(in_fd);
	if (out_fd > 2)
		close(out_fd);
	return (og);
}

void	close_redirect(int *pip_og, t_Command cmd, int pip_in)
{
	if (pip_og)
	{
		if (pip_in < 0)
		{
			close(STDIN);
			close(STDOUT);
			dup2(pip_og[0], STDIN);
			dup2(pip_og[1], STDOUT);
		}
		if (pip_og[0] > 2 || pip_in < 0)
			close(pip_og[0]);
		if (pip_og[1] > 2 || pip_in < 0)
			close(pip_og[1]);
	}
	if (cmd.in_fd != STDIN)
		close(cmd.in_fd);
	if (cmd.out_fd != STDOUT)
		close(cmd.out_fd);
	if (pip_in > 2)
		close(pip_in);
}

int	*close_pipe_rst(int *pip, int in_fd, int out_fd, int pip_in)
{
	if (pip != NULL)
	{
		close(pip[0]);
		close(pip[1]);
		pip[0] = pip_in;
		if (in_fd > 2)
			pip[0] = in_fd;
		pip[1] = out_fd;
	}
	return (pip);
}

void	reset_std(int count)
{
	static int	std[2];

	if (count == 0)
	{
		std[0] = dup(0);
		std[1] = dup(1);
	}
	dup2(std[0], STDIN);
	dup2(std[1], STDOUT);
	if (count == 1)
	{
		close(std[0]);
		close(std[1]);
	}
}
