/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/09/01 14:16:32 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main2(int argc, char **argv, char **envp)
{
	char				*inp;
	t_Command			cmd;
	int					child_pid;
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
				head_cmd = cmd;
				while (cmd.next)
				{
					child_pid = fork();
					if (child_pid == 0)
					{
						executer(cmd);
						close(((t_Command *)cmd.next)->in_fd);
						exit(0);
					}
					close(cmd.out_fd);
					cmd = *(t_Command *)cmd.next;
					waitpid(child_pid, NULL, 0);
				}
				child_pid = fork();
				if (child_pid == 0)
				{
					executer(cmd);
					exit(0);
				}
				waitpid(child_pid, NULL, 0);
				free_command(head_cmd);
			}
		}
		// else
			// write(1, "\n", 1);
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
