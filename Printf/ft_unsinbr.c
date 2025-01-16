/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsinbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:12:14 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/15 14:47:32 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsinbr(int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_unsinbr(nbr / 10, count);
		ft_putchar((nbr % 10) + 48, count);
	}
	else
		ft_putchar(nbr + 48, count);
}
