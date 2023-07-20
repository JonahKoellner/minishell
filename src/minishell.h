/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:35:46 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/07/20 17:10:24 by mreidenb         ###   ########.fr       */
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
int		new_line(t_sys_val *sys_val);

//#--------- signal_handler ----------#//
void	sig_ctrl_c(int signo, siginfo_t *client_info, void *param);
void	sig_ctrl_d(int signo, siginfo_t *client_info, void *param);
int		cd_back(t_sys_val *sys_val);
int		cd_arg(t_sys_val *sys_val, char *arg);

#endif
