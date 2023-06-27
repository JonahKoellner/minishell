/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 05:52:25 by mreidenb          #+#    #+#             */
/*   Updated: 2022/10/18 05:58:40 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*list;
	int		c;

	if (!lst)
		return (0);
	c = 1;
	list = lst;
	while (list->next)
	{
		list = list->next;
		c++;
	}
	return (c);
}
