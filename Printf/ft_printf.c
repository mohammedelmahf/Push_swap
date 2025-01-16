/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:47:57 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/16 13:50:02 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_format(char f, va_list arg, int *count)
{
	if (f == 'c')
		ft_putchar(va_arg(arg, int), count);
	else if (f == '%')
		ft_putchar('%', count);
	else if (f == 's')
		ft_putstr(va_arg(arg, char *), count);
	else if (f == 'd' || f == 'i')
		ft_putnbr(va_arg(arg, int), count);
	else if (f == 'u')
		ft_unsinbr(va_arg(arg, unsigned int), count);
	else if (f == 'x')
		ft_putnbr_base(va_arg(arg, int), 16, "0123456789abcdef", count);
	else if (f == 'X')
		ft_putnbr_base(va_arg(arg, int), 16, "0123456789ABCDEF", count);
	else if (f == 'p')
		ft_putvoid(va_arg(arg, void *), count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	if (!s || write(1, "", 0) == -1)
		return (-1);
	va_start(arg, s);
	while (*s)
	{
		if (*s == '%')
			ft_print_format(*(++s), arg, &count);
		else
			ft_putchar(*s, &count);
		if (count == -1)
			return (-1);
		s++;
	}
	va_end(arg);
	return (count);
}
