/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:20:39 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/28 15:25:52 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../lib/42-libft/libft.h"

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char				*inp;
	char				**env;
	t_Command			cmd;

	signal(SIGINT, sig_decide);
	signal(SIGQUIT, sig_decide);
	// signal(EOF, sig_decide);
	(void)argc;
	(void)argv;
	env = ft_vecdup((const char **)envp);
	while (1)
	{
		inp = input();
		cmd = input_to_lex(inp, env);
		// if (cmd.type.lexeme == NULL)
		// 	printf("\n");
		if (cmd.err == 0 && cmd.type.lexeme != NULL)
			executer(cmd, env);
	}

}
