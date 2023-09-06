/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonah <jonah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:44:18 by jkollner          #+#    #+#             */
/*   Updated: 2023/01/17 17:19:01 by jonah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *string)
{
	int	counter;

	if (string == NULL)
		return (0);
	counter = 0;
	while (string[counter] != '\0')
		counter++;
	return (counter);
}

void	ft_bzero(char *buffer, int n)
{
	int	counter;

	counter = 0;
	while (counter < n)
	{
		buffer[counter] = 0;
		counter++;
	}
}

/*
Mix of realloc and join methode.
It joins the given string with another string and frees both of the string.
The last parameter defines if the second stirng will be freeed aswell
Usage:
str = ft_realloc_join(str, string2, 1);
*/
void	*ft_realloc_j(char *first, char *last)
{
	char	*ret;
	int		counter;
	int		counter_last;

	counter = 0;
	counter_last = 0;
	if (ft_strlen(first) == 0 && ft_strlen(last) == 0)
		return (free(first), NULL);
	ret = ft_calloc((ft_strlen((char *)first) + ft_strlen(last) + 1), 1);
	if (ret == NULL)
		return (NULL);
	while (first[counter] != '\0')
	{
		ret[counter] = first[counter];
		counter++;
	}
	while (last[counter_last] != '\0')
	{
		ret[counter + counter_last] = last[counter_last];
		counter_last++;
	}
	return (free(first), ret);
}

int	clean_up_buffer(char *buffer)
{
	int	until_n;
	int	set_new;

	set_new = 0;
	until_n = 0;
	while (buffer[until_n] != '\0')
	{
		if (buffer[until_n] == '\n')
		{
			buffer[until_n++] = '\0';
			break ;
		}
		buffer[until_n] = 0;
		until_n++;
	}
	while (buffer[until_n] != '\0')
	{
		buffer[set_new++] = buffer[until_n];
		buffer[until_n] = '\0';
		until_n++;
	}
	buffer[until_n] = 0;
	return (until_n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret_mem;

	if (count != 0)
	{
		if (!count || (count * size) / count != size)
			return (NULL);
	}
	ret_mem = (void *)malloc(count * size);
	if (ret_mem == NULL)
		return (NULL);
	ft_bzero(ret_mem, count * size);
	return (ret_mem);
}
