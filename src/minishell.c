/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/18 13:43:06 by jkollner         ###   ########.fr       */
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
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = sig_decide;
	s_sigaction.sa_flags = SA_SIGINFO;
	(void)argc;
	(void)argv;
	env = ft_vecdup((const char**)envp);
	while (1)
	{
		sigaction(SIGINT, &s_sigaction, 0);
		sigaction(SIGQUIT, &s_sigaction, 0);
		inp = input();
		if (inp == 0x00)
			printf("0x00\n");
		if (strcmp(inp, ""))
			printf("''\n");
		if (input_to_lex(inp, env) < 0)
			break ;

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
