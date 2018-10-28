/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:50:01 by okupin            #+#    #+#             */
/*   Updated: 2017/10/30 15:50:24 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_spaces(int i, const char *str)
{
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	scope_i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	scope_i = ft_strlen(s) - 1;
	i = skip_spaces(0, s);
	if (s[i] == '\0')
	{
		return (ft_strdup(""));
	}
	while (s[scope_i] == ' ' || s[scope_i] == '\n' || s[scope_i] == '\t')
		scope_i--;
	scope_i = scope_i - i;
	new = ft_strsub(s, i, scope_i + 1);
	return (new);
}
