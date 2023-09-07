/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:09:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/07 10:18:54 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//#--------- visual_prompt ----------#//

char	*new_line(void);
int		etb(int err);
int		check_customs(t_Command command);

//#--------- signal_handler ----------#//

void	sig_decide(int sig);
void	sig_ctrl_c(void);
void	sig_ctrl_d(void);

//#--------- Buildin Functions ----------#//

int		custom_exit(t_Command *command);
int		env(void);
int		pwd(void);
int		export(t_Token *input, int c_arg);
int		echo(t_Token *arguments, int arg_count);
int		unset(t_Token *arguments, int arg_count);
int		is_number(char *str);
int	check_char(char *str, char c);
int	check_export(char *str);


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
char	*get_environ_item(char *item);

//#--------- Redirect ------------#//
void	close_redirect(int *pip, t_Command cmd, int pip_in);
int		*open_redirect(int in_fd, int out_fd, int *pip);
int		*close_pipe_rst(int *pip, int in_fd, int out_fd, int pip_in);
void	reset_std(int count);

#endif
