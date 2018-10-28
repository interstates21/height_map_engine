/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okupin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:12:07 by okupin            #+#    #+#             */
/*   Updated: 2017/11/11 15:12:41 by okupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int search;

	search = 1;
	if (nb <= 0)
		return (0);
	while (search * search < nb)
		search++;
	if (search * search == nb)
		return (search);
	else
		return (0);
}
