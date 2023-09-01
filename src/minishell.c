/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/09/01 15:29:21 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	*ft_realloc(int *old, int size)
{
	int	*arr;
	int	index;

	if (!old)
		return (NULL);
	arr = ft_calloc(size, sizeof(int));
	index = 0;
	while (old[index] && index < size)
	{
		arr[index] = old[index];
		index++;
	}
	free(old);
	return (arr);
}

int	main2(int argc, char **argv, char **envp)
{
	char				*inp;
	t_Command			cmd;
	int					*child_pid;
	int					num_child;
	int					index;
	t_Command			head_cmd;

	signal(SIGINT, sig_decide);
	signal(SIGQUIT, sig_decide);
	(void)argc;
	(void)argv;
	enviroment(ft_vecdup(envp));
	add_environ("?=0");
	while (1)
	{
		inp = input();
		cmd = input_to_lex(inp);
		if (cmd.err == 0 && cmd.type.lexeme != NULL)
		{
			if (!cmd.next)
				executer(cmd);
			else
			{
				num_child = 0;
				child_pid = ft_calloc(1, sizeof(int));
				head_cmd = cmd;
				while (cmd.next)
				{
				//	num_child++;
					child_pid = ft_realloc(child_pid, ++num_child);
					child_pid[num_child - 1] = fork();
					if (child_pid[num_child - 1] == 0)
					{
						executer(cmd);
						close(((t_Command *)cmd.next)->in_fd);
						exit(0);
					}
					close(cmd.out_fd);
					cmd = *(t_Command *)cmd.next;
				}
				//num_child++;
				child_pid = ft_realloc(child_pid, ++num_child);
				child_pid[num_child - 1] = fork();
				if (child_pid[num_child - 1] == 0)
				{
					executer(cmd);
					exit(0);
				}
				index = 0;
				while (index < num_child)
					waitpid(child_pid[index++], NULL, 0);
				free(child_pid);
				free_command(head_cmd);
			}
		}
	}
}

void cleanup() {
	char command[100];
	pid_t pid = getpid();
	sprintf(command, "leaks %d", pid);
	system(command);
}

int	main(int argc, char **argv, char **envp)
{
	// atexit(cleanup);
	main2(argc, argv, envp);
}
