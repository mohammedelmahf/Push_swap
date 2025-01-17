/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:44:11 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/17 10:41:13 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*ss1;
	unsigned char	*ss2;

	index = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (*ss1 && *ss2 && *ss1 == *ss2 && index < n)
	{
		ss1++;
		ss2++;
		index++;
	}
	if (index == n)
		return (0);
	return (*ss1 - *ss2);
}
