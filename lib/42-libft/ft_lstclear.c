/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 06:41:48 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/24 22:24:51 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*newlst;
	t_list	*free_lst;

	if (!*lst)
		return ;
	newlst = *lst;
	while (newlst)
	{
		if (newlst->content)
			del(newlst->content);
		free_lst = newlst;
		newlst = newlst->next;
		free(free_lst);
	}
	*lst = NULL;
}
