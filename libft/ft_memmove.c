/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:21:32 by okupin            #+#    #+#             */
/*   Updated: 2017/10/26 20:21:56 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_s;
	unsigned char	*src_s;

	i = 0;
	dst_s = (unsigned char*)dst;
	src_s = (unsigned char*)src;
	if (src_s < dst_s)
	{
		n--;
		while ((int)(n) >= 0)
		{
			dst_s[n] = src_s[n];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			dst_s[i] = src_s[i];
			i++;
		}
	}
	return (dst_s);
}
