/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:25:17 by okupin            #+#    #+#             */
/*   Updated: 2017/10/27 19:25:30 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*tmp;

	i = 0;
	j = 0;
	count = 0;
	if (find[0] == '\0')
		return ((char*)str);
	while (find[count] != '\0')
		count++;
	while (str[i] != '\0')
	{
		j = 0;
		tmp = (char*)&str[i];
		while (tmp[j] == find[j])
		{
			j++;
			if (j == count)
				return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}
