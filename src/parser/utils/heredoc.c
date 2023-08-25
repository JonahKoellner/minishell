/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:49:24 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/24 21:26:13 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_heredoc(char *delimiter_full, int *fd, const char **env)
{
	char	*input;
	char	*delimiter_cut;
	size_t	heredoc_size;

	heredoc_size = 0;
	delimiter_cut = quote(delimiter_full, &(int){0});
	*delimiter_cut = NULL;
	while (1)
	{
		input = readline("heredoc> ");
		if (!input)
			break ;
		if (!ft_strncmp(input, delimiter_cut, ft_strlen(delimiter_cut) + 1))
			break ;
		if (ft_strlen(delimiter_full) != ft_strlen(delimiter_cut))
			ft_putendl_fd(input, fd[1]);
		else
			ft_putendl_fd(var_expander(input, env), fd[1]);
		free(input);
	}
	free(input);
	free(delimiter_full);
}

