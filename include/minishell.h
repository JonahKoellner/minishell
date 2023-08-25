/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:35:46 by jonahkollne       #+#    #+#             */
/*   Updated: 2023/08/25 13:34:56 by jkollner         ###   ########.fr       */
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
# include "../src/parser/parser.h"
# include "../src/utils/utils.h"
# include <fcntl.h>
# include <errno.h>

# define ERROR -1
# define SUCCESS 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <libft.h>

//#--------- Structs ----------#//

typedef struct sys_val
{
	char	*dir;
}	t_sys_val;

//#--------- visual_prompt ----------#//

int		new_line(char *string);

//#--------- signal_handler ----------#//

void	sig_decide(int sig);
// void	sig_ctrl_c(siginfo_t *client_info, void *param);
void	sig_ctrl_c(void);
// void	sig_ctrl_d(siginfo_t *client_info, void *param);
void	sig_ctrl_d(void);

//#--------- Buildin Functions ----------#//

void	custom_exit(void *to_clean);
int		env(void);
int		echo(char *string, int n_flag);

//#--------- Directory Handling ----------#//

int		cd(char *path);
int		pwd(void);


#endif
