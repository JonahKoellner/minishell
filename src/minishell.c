/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/30 18:58:54 by jkollner         ###   ########.fr       */
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
	add_environ("?=0");
	while (1)
	{
		inp = input();
		cmd = input_to_lex(inp);
		// if (cmd.type.lexeme == NULL)
		// 	printf("\n");
		if (cmd.type.lexeme != NULL)
			add_environ(ft_strjoin_free(ft_strdup("?="), ft_itoa(cmd.err)));
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
