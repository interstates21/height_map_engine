/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:50:46 by okupin            #+#    #+#             */
/*   Updated: 2017/10/28 19:51:08 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char*)malloc(size + 1);
	i = 0;
	if (ptr != NULL)
	{
		while (i <= size)
		{
			ptr[i] = '\0';
			i++;
		}
		return (ptr);
	}
	return (NULL);
}
