#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "src/minishell.h"

int	main(void)
{
	//int	fd;

	//fd = open("WoW", O_WRONLY | O_CREAT | O_TRUNC);
	//printf("Hey %i", fd);
	//write(fd, "Hey wassup", 12);
	char *input = {"echo $(cat burger) >>burger"};
	printf("%i \n", input_to_lex(input));
}
