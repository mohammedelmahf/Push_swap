/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:09:48 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/07 17:37:55 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digits_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*digit_str;
	long int	nb;
	size_t		len;

	if (n < 0)
		nb = -(long int)n;
	else
		nb = (long int)n;
	len = digits_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	digit_str = malloc((len + 1) * sizeof(char));
	if (digit_str == NULL)
		return (NULL);
	digit_str[len] = '\0';
	while (len--)
	{
		digit_str[len] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (n < 0)
		digit_str[0] = '-';
	return (digit_str);
}
