/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:26:06 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/16 13:43:31 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, unsigned int baselen, char *base, int *count)
{
	unsigned int	n;

	n = nbr;
	if (n >= baselen)
	{
		ft_putnbr_base(n / baselen, baselen, base, count);
		ft_putchar(base[n % baselen], count);
	}
	else
		ft_putchar(base[n % baselen], count);
}
