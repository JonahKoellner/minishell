/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:49:24 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/18 17:17:22 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_heredoc(char *delimiter_full, int *fd)
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
			expand();
		free(input);
	}
	free(input);
	free(delimiter_full);
}
