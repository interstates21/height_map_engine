/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:06:26 by okupin            #+#    #+#             */
/*   Updated: 2017/10/27 17:06:41 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	i;
	size_t	count_src;
	char	*place;

	count_dst = 0;
	count_src = 0;
	while (dst[count_dst] != '\0')
		count_dst++;
	while (src[count_src] != '\0')
		count_src++;
	if (dstsize < count_dst && (int)dstsize >= 0)
		return (dstsize + count_src);
	place = &dst[count_dst];
	i = 0;
	while (i < count_src && i + count_dst < (dstsize - 1))
	{
		place[i] = src[i];
		i++;
	}
	place[i] = '\0';
	return (count_dst + count_src);
}
