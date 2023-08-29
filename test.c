
#include <fcntl.h>
#include <stddef.h> // For size_t
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/42-libft/libft.h"
#include <ctype.h>

//#include "src/minishell.h"

// int	main2(int argc, char **argv, char **envp)
// {
// 	char **env = ft_vecdup(envp);
// 	ft_vecfree(env);
// }

// void cleanup() {
// 	char command[100];
// 	pid_t pid = getpid();
// 	sprintf(command, "leaks %d", pid);
// 	system(command);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	atexit(cleanup);
// 	main2(argc, argv, envp);
// }

int main(void)
{
	char c = 0;
	while (c < 127)
	{
		if (isspace(c))
			printf("%d \n", c);
		c++;
	}
}

// t_Command	check_parsed(t_Command cmds, t_Token *tokens)
// {
// 	t_Command	cmd;
// 	int			i;
// 	int			n;

// 	i = 0;
// 	n = cmd_count(tokens);
// 	free(tokens);
// 	cmd = cmds;
// 	while (i < n)
// 	{
// 		if (cmd.type.type == ERR)
// 			return (free_command(cmds), unclosed_pipe());
// 		if (cmd.arg_i != cmd.arg_count)
// 			return (free_command(cmds), (t_Command){.err = -7});
// 		if (cmd.in_fd < 0 || cmd.out_fd < 0)
// 			return (free_command(cmds), open_error(cmd.in_fd, cmd.out_fd));
// 		i++;
// 		cmd = *(t_Command *)cmds.next;
// 	}
// 	return (cmds);
// }