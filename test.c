
#include <fcntl.h>
#include <stddef.h> // For size_t
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/42-libft/libft.h"
//#include "src/minishell.h"

// int	main(void)
// {
// 	//int	fd;

// 	//fd = open("WoW", O_WRONLY | O_CREAT | O_TRUNC);
// 	//printf("Hey %i", fd);
// 	//write(fd, "Hey wassup", 12);
// 	char *input = {"echo $(cat burger) >>burger"};
// 	printf("%i \n", input_to_lex(input));
// }


// void	ft_vecfree(char **vec)
// {
// 	size_t	i;

// 	i = 0;
// 	if (vec == NULL)
// 		return ;
// 	while (vec[i] != NULL)
// 		free(vec[i++]);
// 	free(vec);
// }

// size_t	ft_veclen(const char **vec)
// {
// 	size_t	len;

// 	len = 0;
// 	while (vec && vec[len])
// 		len++;
// 	return (len);
// }

void *map_length(void *s)
{
	char *str = malloc(30);
	if (str != NULL)
		sprintf(str, "__%lX", strlen((char *)s));
	return str;
}

void delete(void *content)
{
	char *str = (char *)content;
	if (str == NULL)
		return;
	if (str[0] != '_' || str[1] != '_')
		printf("Hamburger \n");
	free(content);
}

int	main(void)
{
	memcpy(((void *)0), "segfaulter tu dois", 17);
	ft_memcpy(((void *)0), ((void *)0), 3);
	return (0);
}
