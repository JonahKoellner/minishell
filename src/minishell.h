/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:35:46 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/02 12:57:44 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include "parser/parser.h"

# define ERROR -1
# define SUCCESS 0

# define STDOUT 1
# define STDIN 0
# define STDERR 2

# include "../lib/42-libft/libft.h"

//#--------- Structs ----------#//
typedef struct sys_val
{
	char	*dir;
}	t_sys_val;

//#--------- visual_prompt ----------#//
int		new_line(char *string);

//#--------- signal_handler ----------#//
void	sig_ctrl_c(int signo, siginfo_t *client_info, void *param);
void	sig_ctrl_d(int signo, siginfo_t *client_info, void *param);
int		cd(char	*path);

#endif
