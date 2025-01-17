/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:26:06 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/17 10:42:24 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
