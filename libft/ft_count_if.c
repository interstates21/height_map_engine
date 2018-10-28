/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:10:42 by okupin            #+#    #+#             */
/*   Updated: 2017/11/03 17:11:07 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(char **tab, int (*f) (char*))
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (tab == NULL || f == NULL)
		return (0);
	while (tab[i] != NULL)
	{
		if ((f(tab[i])) == 1)
		{
			count++;
		}
		i++;
	}
	return (count);
}
