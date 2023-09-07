/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/09/07 03:07:29 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	child_pipe(t_Command cmd, int pip_in, int *pid)
{
	int	pip[2];

	pipe(pip);
	if (!cmd.next)
		close_pipe_rst(pip, cmd.in_fd, cmd.out_fd, pip_in);
	*pid = fork();
	if (*pid == 0)
	{
		if (cmd.in_fd == STDIN && cmd.out_fd == STDOUT)
			open_redirect(pip_in, pip[1], pip);
		else if (cmd.in_fd != STDIN && cmd.out_fd == STDOUT)
			open_redirect(cmd.in_fd, pip[1], pip);
		else if (cmd.in_fd == STDIN && cmd.out_fd != STDOUT)
			open_redirect(pip_in, cmd.out_fd, pip);
		else if (cmd.in_fd != STDIN && cmd.out_fd != STDOUT)
			open_redirect(cmd.in_fd, cmd.out_fd, pip);
		close_redirect(pip, cmd, pip_in);
		cmd.arg_i = -13;
		exit(executer(cmd, pip));
	}
	close_redirect(NULL, cmd, pip_in);
	if (pip[1] > 2)
		close(pip[1]);
	return (pip[0]);
}

void	multi_executor(t_Command cmd)
{
	t_Command	head_cmd;
	int			pip_in;
	int			num_child;
	int			*child_pid;

	pip_in = cmd.in_fd;
	num_child = 0;
	child_pid = ft_calloc(cmd.count, sizeof(int));
	if (child_pid == NULL)
		return ;
	head_cmd = cmd;
	while (num_child < head_cmd.count && cmd.err >= 0)
	{
		pip_in = child_pipe(cmd, pip_in, &child_pid[num_child++]);
		if (cmd.next)
			cmd = *(t_Command *)cmd.next;
	}
	num_child = 0;
	while (num_child < head_cmd.count)
		waitpid(child_pid[num_child++], NULL, 0);
	if (pip_in > 2)
		close(pip_in);
	return (free(child_pid));
}

int	main2(int argc, char **argv, char **envp)
{
	char				*inp;
	t_Command			cmd;

	signal(SIGINT, sig_decide);
	signal(SIGQUIT, sig_decide);
	(void)argv;
	(void)argc;
	enviroment(ft_vecdup(envp));
	add_environ(ft_strdup("?=0"));
	while (1)
	{
		inp = input();
		cmd = input_to_lex(inp);
		if (cmd.err >= 0 && cmd.type.lexeme != NULL)
		{
			if (!cmd.next)
				executer(cmd, NULL);
			else
				multi_executor(cmd);
			free_command(cmd);
		}
		if (cmd.err != 0)
			add_environ(ft_strjoin_free(ft_strdup("?="), ft_itoa(cmd.err)));
	}
}

int	main(int argc, char **argv, char **envp)
{
	main2(argc, argv, envp);
}
