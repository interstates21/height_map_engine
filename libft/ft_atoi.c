/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:25:01 by okupin            #+#    #+#             */
/*   Updated: 2017/10/27 18:25:17 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	str += ft_skip_tab(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9' && i++ <= 19)
		result = (result * 10) + (*str++ - '0');
	if (result <= 9223372036854775807 && i <= 19)
		return ((int)result * sign);
	else if (sign == -1)
		return (0);
	else
		return (-1);
}
