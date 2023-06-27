/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:39:02 by mreidenb          #+#    #+#             */
/*   Updated: 2023/06/19 16:51:19 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_SimpleCommand {
	int		_num_av_args;
	int		_num_args;
	char	**_arguments;
}	t_SimpleCommand;

typedef struct s_Command {
	int					_num_av_simp_com;
	int					_num_simp_com;
	t_SimpleCommand		**_simp_com;
	char				*_out_file;
	char				*_input_file;
	char				*_err_file;
	int					_background;
}	t_Command;

#endif
