/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:09:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/28 11:14:30 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

//------------------ Functions ------------------//

int	env(void);
int	execute_path(t_Command cmd, char **env_var, char *args[]);
int	pwd(void);
int	executer(t_Command command, char **envp);
int	print_history(void);
int	export(t_Token *input, int c_arg, char **envp);

#endif
