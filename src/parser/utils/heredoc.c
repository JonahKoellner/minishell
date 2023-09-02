/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:49:24 by mreidenb          #+#    #+#             */
/*   Updated: 2023/09/02 14:14:04 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end_heredoc(char *delimiter_full, int *fd)
{
	free(delimiter_full);
	if (fd[0] > 2)
		close(fd[0]);
	if (fd[1] > 2)
		close(fd[1]);
	exit(0);
}

void	handle_heredoc(char *delimiter_full, int *fd)
{
	char	*input;
	char	*delimiter_cut;

	delimiter_cut = quote(delimiter_full, &(int){0});
	signal(SIGINT, SIG_DFL);
	while (1)
	{
		input = readline("heredoc> ");
		if (!input)
			break ;
		if (!ft_strncmp(input, delimiter_cut, ft_strlen(delimiter_cut) + 1))
			break ;
		if (ft_strlen(delimiter_full) != ft_strlen(delimiter_cut))
		{
			ft_putendl_fd(input, fd[1]);
			free(input);
		}
		else
			ft_putendl_fd(var_expander(input), fd[1]);
	}
	free(input);
	if (ft_strlen(delimiter_full) != ft_strlen(delimiter_cut))
		free(delimiter_cut);
	end_heredoc(delimiter_full, fd);
}

int	end_heredoc_parent(int status, int *fd)
{
	if (WIFSIGNALED(status))
	{
		signal(SIGINT, sig_decide);
		write(STDOUT, "\n", 1);
		return (-1);
	}
	else
	{
		signal(SIGINT, sig_decide);
		close(fd[1]);
		return (fd[0]);
	}
}

int	make_heredoc(char *delimiter)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		handle_heredoc(delimiter, fd);
	waitpid(pid, &status, 0);
	free(delimiter);
	return (end_heredoc_parent(status, fd));
}
