/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:09:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/03 23:33:42 by mreidenb         ###   ########.fr       */
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
int		unset(t_Token *arguments, int arg_count);

//#--------- Directory Handling ----------#//

int		cd(char *path);
int		pwd(void);

//#--------- Execution ----------#//

int		executer(t_Command command, int *pip_og);
int		execute_path(t_Command cmd, char *args[]);

//#--------- Enviroment ----------#//

char	**enviroment(char	**envp);
int		add_environ(char	*var);
int		remove_environ(char	*var);

//#--------- Redirect ------------#//
//int		close_redirect(int og_in, int og_out);
void	close_redirect(int *pip, t_Command cmd, int pip_in);
//int		*open_redirect(int in_fd, int out_fd);
int		*open_redirect(int in_fd, int out_fd, int *pip);
int		*close_pipe_rst(int *pip, int in_fd, int out_fd, int pip_in);
void	reset_std(int count);

#endif
