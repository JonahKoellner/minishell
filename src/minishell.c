/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/25 13:33:28 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../lib/42-libft/libft.h"

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char				*inp;
	char				**env;
	t_Command			cmd;
	// struct sigaction	s_sigaction;

	// s_sigaction.sa_sigaction = sig_decide;
	// s_sigaction.sa_flags = SA_SIGINFO;
	signal(SIGINT, sig_decide);
	(void)argc;
	(void)argv;
	env = ft_vecdup((const char **)envp);
	while (1)
	{
		// sigaction(SIGINT, &s_sigaction, 0);
		// sigaction(SIGQUIT, &s_sigaction, 0);
		inp = input();
		cmd = input_to_lex(inp, env);
		if (cmd.type.lexeme == NULL)
			printf("\n");
		if (cmd.err == 0 && cmd.type.lexeme != NULL)
			executer(cmd, envp);
		// t_Command com = (t_Command){.type.lexeme = inp};
		// executer(com, envp);


	}

}
