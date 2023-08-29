/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:09:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/29 14:01:36 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//#--------- visual_prompt ----------#//

char	*new_line(void);

//#--------- signal_handler ----------#//

void	sig_decide(int sig);
void	sig_ctrl_c(void);
void	sig_ctrl_d(void);

//#--------- Buildin Functions ----------#//

void	custom_exit(void *to_clean);
int		env(void);
int		pwd(void);
int		export(t_Token *input, int c_arg);
int		echo(t_Token *arguments, int arg_count);
int		unset(char *var, char **envp);

//#--------- Directory Handling ----------#//

int		cd(char *path, char **envp);
int		pwd(void);

//#--------- Execution ----------#//

int		executer(t_Command command, char **envp);
int		execute_path(t_Command cmd, char **env_var, char *args[]);

//#--------- Enviroment ----------#//

char	**enviroment(char	**envp);
int	add_environ(char	*var);

#endif
