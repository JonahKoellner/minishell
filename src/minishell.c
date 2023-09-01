/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/31 19:14:17 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main2(int argc, char **argv, char **envp)
{
	char				*inp;
	t_Command			cmd;
	//t_Command			og;

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
			//og = cmd;
			while (cmd.next)
			{
				printf("\n");
				executer(cmd);
				cmd = *(t_Command *)cmd.next;
			}
			executer(cmd);
			free(&cmd);
		}
		else
			write(1, "\n", 1);
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
	atexit(cleanup);
	main2(argc, argv, envp);
}
