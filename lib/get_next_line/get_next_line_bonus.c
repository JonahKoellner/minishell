/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:01 by jkollner          #+#    #+#             */
/*   Updated: 2023/01/24 10:21:13 by jkollner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#if !defined BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*ft_strchr(char *buffer, char c)
{
	int	counter;

	counter = 0;
	while (buffer[counter] != '\0')
	{
		if (buffer[counter] == (char)c)
			return ((char *)&buffer[counter]);
		counter++;
	}
	if ((char)c == '\0')
		return ((char *)&buffer[counter]);
	return (NULL);
}

char	*read_til_n(int fd, char *buffer)
{
	char	*read_buffer;
	int		read_return;

	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_return = 1;
	while (read_return >= 1)
	{
		read_return = read(fd, read_buffer, BUFFER_SIZE);
		if (read_return < 0)
			return (free(read_buffer), free(buffer), NULL);
		buffer = ft_realloc_j(buffer, read_buffer);
		if (!buffer)
			return (free(read_buffer), NULL);
		ft_bzero(read_buffer, BUFFER_SIZE);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (buffer);
}

char	*get_n_str(char *buffer)
{
	int		until_n;
	char	*return_string;
	int		fill;

	until_n = 0;
	fill = 0;
	while (buffer[until_n] != '\n' && buffer[until_n])
		until_n++;
	return_string = ft_calloc(until_n + 2, sizeof(char));
	if (!return_string)
		return (NULL);
	while (fill <= until_n)
	{
		return_string[fill] = buffer[fill];
		fill++;
	}
	if (return_string[fill - 1] != 0)
	{
		return_string[fill] = 0;
	}
	return (return_string);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*return_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_til_n(fd, buffer[fd]);
	if (!buffer[fd])
		return (free(buffer[fd]), NULL);
	return_string = get_n_str(buffer[fd]);
	if (!return_string)
		return (free(buffer[fd]), free(return_string), NULL);
	clean_up_buffer(buffer[fd]);
	return (return_string);
}
