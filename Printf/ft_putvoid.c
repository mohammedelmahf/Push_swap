/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:53:16 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/17 10:42:32 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr_base_void(unsigned long n, unsigned long baselen,
		char *base, int *count)
{
	if (n >= baselen)
	{
		ft_putnbr_base_void(n / baselen, baselen, base, count);
		ft_putchar(base[n % baselen], count);
	}
	else
		ft_putchar(base[n % baselen], count);
}

void	ft_putvoid(void *s, int *count)
{
	unsigned long	n;

	n = (unsigned long)s;
	ft_putstr("0x", count);
	ft_putnbr_base_void(n, 16, "0123456789abcdef", count);
}
