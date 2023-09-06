/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:44:10 by jkollner          #+#    #+#             */
/*   Updated: 2023/09/06 17:36:14 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// Includes

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
// Declarations

char	*get_next_line(int fd);
void	*ft_realloc_j(char *first, char *last);
int		clean_up_buffer(char *buffer);
void	*ft_calloc(size_t count, size_t size);
int		check_nl(char *buffer);
char	*copy_out(char *buffer, int amount);
// int		ft_strlen(char *string);
// void	ft_bzero(char *buffer, int n);
#endif /* GET_NEXT_LINE_H */
