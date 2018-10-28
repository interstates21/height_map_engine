/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:03:22 by okupin            #+#    #+#             */
/*   Updated: 2017/10/26 21:03:38 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_s;

	i = 0;
	src_s = (unsigned char*)src;
	while (n > 0)
	{
		if (src_s[i] == (unsigned char)c)
			return (src_s + i);
		n--;
		i++;
	}
	return (NULL);
}
