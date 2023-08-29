
#include <fcntl.h>
#include <stddef.h> // For size_t
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/42-libft/libft.h"
//#include "src/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	//t_Command	*i;

	//i = malloc(sizeof(t_Command));
	//i->arg_i = 5;
	int fd = open("test.txt", O_RDWR);
	int dupp = dup(STDOUT_FILENO);
	int dupp2 = dup2(fd, STDOUT_FILENO);
	ft_printf_fd(STDOUT_FILENO, "BABABboy dup %d dup2 %d fd %d\n", dupp, dupp2, fd);
	dup2(STDOUT_FILENO, fd);
	printf("second print\n");
	//*i = is(*i);
}
