/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/29 22:27:07 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../lib/42-libft/libft.h"

#include "minishell.h"

int	main2(int argc, char **argv, char **envp)
{
	char				*inp;
	t_Command			cmd;

	signal(SIGINT, sig_decide);
	signal(SIGQUIT, sig_decide);
	// signal(EOF, sig_decide);
	(void)argc;
	(void)argv;
	enviroment(ft_vecdup(envp));
	while (1)
	{
		inp = input();
		cmd = input_to_lex(inp);
		// if (cmd.type.lexeme == NULL)
		// 	printf("\n");
		if (cmd.err == 0 && cmd.type.lexeme != NULL)
			executer(cmd);
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
