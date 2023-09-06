/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/09/06 13:12:33 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//// int	*ft_realloc(int *old, int size)
//// {
//	// int	*arr;
//	// int	index;

//	// if (!old)
//		// return (NULL);
//	// arr = ft_calloc(size, sizeof(int));
//	// if (!arr)
//		// return (NULL);
//	// index = 0;
//	// while (index < size - 1)
//	// {
//		// arr[index] = old[index];
//		printf("%i \n", old[index]);
//		// index++;
//	// }
//	// free(old);
//	// return (arr);
//// }

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
	//reset_std(0
	while (num_child < head_cmd.count && cmd.err == 0)
	{
		pip_in = child_pipe(cmd, pip_in, &child_pid[num_child++]);
		if (cmd.next)
			cmd = *(t_Command *)cmd.next;
		//reset_std(cmd.count);
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
		if (cmd.err == 0 && cmd.type.lexeme != NULL)
		{
			if (!cmd.next)
				executer(cmd, NULL);
			else
			{
				multi_executor(cmd);
			}
			free_command(cmd);
		}
		if (cmd.err != 0)
		{
			add_environ(ft_strjoin_free(ft_strdup("?="), ft_itoa(cmd.err)));
		}
	}
}

//int	main2(int argc, char **argv, char **envp)
//{
//	char				*inp;
//	t_Command			cmd;
//	int					*child_pid;
//	int					num_child;
//	int					index;
//	t_Command			head_cmd;

//	signal(SIGINT, sig_decide);
//	signal(SIGQUIT, sig_decide);
//	(void)argc;
//	(void)argv;
//	enviroment(ft_vecdup(envp));
//	add_environ("?=0");
//	while (1)
//	{
//		inp = input();
//		cmd = input_to_lex(inp);
//		if (cmd.err == 0 && cmd.type.lexeme != NULL)
//		{
//			if (!cmd.next)
//			{
//				executer(cmd);
//				free_command(cmd);
//			}
//			else
//			{
//				num_child = 0;
//				child_pid = ft_calloc(1, sizeof(int));
//				head_cmd = cmd;
//				while (cmd.next)
//				{
//				//	num_child++;
//					child_pid = ft_realloc(child_pid, ++num_child);
//					child_pid[num_child - 1] = fork();
//					if (child_pid[num_child - 1] == 0)
//					{
//						executer(cmd);
//						close(((t_Command *)cmd.next)->in_fd);
//						free_command(cmd);
//						exit(0);
//					}
//					close(cmd.out_fd);
//					cmd = *(t_Command *)cmd.next;
//				}
//				//num_child++;
//				child_pid = ft_realloc(child_pid, ++num_child);
//				child_pid[num_child - 1] = fork();
//				if (child_pid[num_child - 1] == 0)
//				{
//					executer(cmd);
//					free_command(cmd);
//					exit(0);
//				}
//				index = 0;
//				while (index < num_child)
//					waitpid(child_pid[index++], NULL, 0);
//				free(child_pid);
//				free_command(head_cmd);
//			}
//		}
//	}
//}

//void cleanup() {
//	char command[100];
//	pid_t pid = getpid();
//	sprintf(command, "leaks %d", pid);
//	system(command);
//}

int	main(int argc, char **argv, char **envp)
{
	// atexit(cleanup);
	main2(argc, argv, envp);
}
