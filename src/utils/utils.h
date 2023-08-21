/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:09:08 by jkollner          #+#    #+#             */
/*   Updated: 2023/08/21 09:56:34 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

//------------------ Functions ------------------//

int	env(void);
int	execute_path(char *path, char *args, char **env_var);
int	pwd(void);
int	executer(t_Command command, char **envp);
#endif
