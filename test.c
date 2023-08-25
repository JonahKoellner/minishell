
#include <fcntl.h>
#include <stddef.h> // For size_t
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/42-libft/libft.h"
//#include "src/minishell.h"

int	is_unquotable(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '<' || c == '>'
		|| c == '(' || c == ')' || c == '$' || c == '`' || c == '\\'
		|| c == '"' || c == '\'')
		return (2);
	else if (c == ' ' || c == '\n' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	else
		return (0);
}

char	*var_search(char *var, const char **env)
{
	int	i;
	int	env_len;
	int	var_len;

	i = 0;
	var_len = ft_strlen(var);
	env_len = ft_veclen(env);
	while (i < env_len)
	{
		if (ft_memcmp(env[i], var, var_len + 1) == '=')
		{
			free(var);
			return (ft_substr(env[i], var_len + 1,
					ft_strlen(env[i]) - (var_len + 1)));
		}
		i++;
	}
	return (free(var), ft_strdup(""));
}

char	*expander(char *input, const char **env)
{
	char	*result;
	char	*tmp;
	size_t	e;
	size_t	i;

	i = 0;
	e = 0;
	result = ft_strdup("");
	while (i < ft_strlen(input))
	{
		e = i;
		if (input[i++] == '$')
		{
			e = i;
			while (!is_unquotable(input[i]))
				i++;
			tmp = var_search(ft_substr(input, e, i - e), env);
			result = ft_strjoin(result, tmp);
			free(tmp);
		}
		else
			result = ft_strjoin_free(result, ft_substr(input, e, i - e));
	}
	return (result);
}

int	main(int argc, char **argv, char **envp)
{
	//t_Command	*i;

	//i = malloc(sizeof(t_Command));
	//i->arg_i = 5;
	char *str = expander("$$", (const char **)envp);
	printf("%s\n", str);
	printf("%s\n", getenv("$$"));
	//*i = is(*i);
}
