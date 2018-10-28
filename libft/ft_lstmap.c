/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:03:41 by okupin            #+#    #+#             */
/*   Updated: 2017/11/02 22:07:56 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*del_ret(t_list **str)
{
	ft_lstdel(str, delforlist);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*begin;
	t_list	*som;

	if (lst == NULL || f == NULL)
		return (NULL);
	som = lst;
	som = f(som);
	if ((new = ft_lstnew(som->content, som->content_size)) == NULL)
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst != NULL)
	{
		som = lst;
		som = f(som);
		new->next = ft_lstnew(som->content, som->content_size);
		if (new->next == NULL)
			return (del_ret(&begin));
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
