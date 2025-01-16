/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:54:24 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/16 13:52:06 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	ssize_t	result;

	result = write(1, &c, 1);
	if (result == -1)
	{
		*count = -1;
	}
	else
	{
		*count += 1;
	}
}
