/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:37:19 by okupin            #+#    #+#             */
/*   Updated: 2017/10/27 15:37:33 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	char	*place;

	i = 0;
	while (dst[i] != '\0')
		i++;
	place = &dst[i];
	i = 0;
	while (src[i] != '\0')
	{
		place[i] = src[i];
		i++;
	}
	place[i] = '\0';
	return (dst);
}
