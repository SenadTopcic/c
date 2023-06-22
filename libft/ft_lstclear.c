/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopcic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:43:39 by stopcic           #+#    #+#             */
/*   Updated: 2022/10/28 19:38:52 by stopcic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temporaly_list;

	if (lst)
	{
		while (*lst != NULL)
		{
			temporaly_list = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = temporaly_list;
		}
	}
}
