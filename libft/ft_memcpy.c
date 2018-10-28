/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 22:40:08 by okupin            #+#    #+#             */
/*   Updated: 2017/10/25 22:40:45 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_s;
	char	*src_s;

	i = 0;
	dst_s = (char*)dst;
	src_s = (char*)src;
	while (i < n)
	{
		dst_s[i] = src_s[i];
		i++;
	}
	return (dst);
}
