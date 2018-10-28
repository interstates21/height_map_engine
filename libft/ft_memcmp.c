/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:19:36 by okupin            #+#    #+#             */
/*   Updated: 2017/10/26 21:19:53 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*sm1;
	unsigned char		*sm2;

	sm1 = (unsigned char*)s1;
	sm2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (sm1[i] != sm2[i])
			return (sm1[i] - sm2[i]);
		i++;
	}
	return (0);
}
