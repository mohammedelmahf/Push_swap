/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:14:37 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/17 10:42:30 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	if (!s)
		ft_putstr("(null)", count);
	else
	{
		while (*s)
		{
			ft_putchar(*s, count);
			s++;
		}
	}
}
