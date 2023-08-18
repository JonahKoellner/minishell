/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/18 15:21:16 by mreidenb         ###   ########.fr       */
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
		input_to_lex(inp, env);


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
