/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/21 13:28:51 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../lib/42-libft/libft.h"

#include "minishell.h"

// void	signal_setup(struct sigaction s_sigaction, struct sigaction *s_sigquit)
// {

// }

int	main(int argc, char **argv, char **envp)
{
	char				*inp;
	char				**env;
	// struct sigaction	s_sigaction;

	// s_sigaction.sa_sigaction = sig_decide;
	// s_sigaction.sa_flags = SA_SIGINFO;
	(void)argc;
	(void)argv;
	env = ft_vecdup((const char **)envp);
	while (1)
	{
		// sigaction(SIGINT, &s_sigaction, 0);
		// sigaction(SIGQUIT, &s_sigaction, 0);
		inp = input();
		executer(input_to_lex(inp, env), envp);
		// t_Command com = (t_Command){.type.lexeme = inp};
		// executer(com, envp);


	}

}


// int	main(void)
// {
// 	//char	*command;
// 	char	*start_dir;

// 	t_sys_val *sys = malloc(sizeof(t_sys_val));
// 	start_dir = malloc(sizeof(char) * 16);
// 	ft_strlcpy(start_dir, "Dev/42/minishell", 16);
// 	cd_arg(sys, start_dir);
// 	new_line(sys);
// 	cd_back(sys);
// 	new_line(sys);
// 	return (1);
// }
