/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:39:42 by okupin            #+#    #+#             */
/*   Updated: 2017/10/27 15:39:54 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	j = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && i < n)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dst);
}
