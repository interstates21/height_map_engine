/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:34:00 by okupin            #+#    #+#             */
/*   Updated: 2017/10/31 18:34:13 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_di(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		j;
	int		i;

	j = count_di(n);
	str = ft_strnew(j + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		str[i] = '-';
		i++;
	}
	while (n > 9)
	{
		str[j--] = n % 10 + '0';
		n /= 10;
	}
	str[i] = n + '0';
	return (str);
}
