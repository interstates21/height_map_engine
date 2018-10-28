/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:06:18 by okupin            #+#    #+#             */
/*   Updated: 2017/11/02 21:29:17 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*list;

	if (*alst != NULL && alst != NULL && del != NULL)
	{
		list = *alst;
		while (list != NULL)
		{
			tmp = list->next;
			del(list->content, list->content_size);
			free(list);
			list = tmp;
		}
		(*alst) = NULL;
	}
}
