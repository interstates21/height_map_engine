/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:55:50 by okupin            #+#    #+#             */
/*   Updated: 2017/10/31 16:56:20 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char *str, char delim)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i = skip_delim(i, str, delim);
		while (str[i] != delim && str[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static void		*space_clean(char **str, int n)
{
	while (n >= 0)
	{
		free(str[n]);
		n--;
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**space;
	size_t	j;
	size_t	i;
	size_t	n;

	if (s == NULL)
		return (NULL);
	space = (char**)malloc(sizeof(char*) * count_words((char*)s, c) + 1);
	i = 0;
	n = 0;
	if (space == NULL)
		return (NULL);
	while (s[skip_delim(i, (char*)s, c)] != '\0')
	{
		i = skip_delim(i, (char*)s, c);
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		space[n] = ft_strsub(s, i, j);
		if (space[n++] == NULL)
			return (space_clean(space, n));
		i += j;
	}
	space[n] = NULL;
	return (space);
}
