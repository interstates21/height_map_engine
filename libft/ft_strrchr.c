/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:42:36 by okupin            #+#    #+#             */
/*   Updated: 2017/10/27 18:42:48 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != (char)c && i != 0)
		i--;
	if (str[i] == (char)c)
		return ((char*)&str[i]);
	return (NULL);
}
