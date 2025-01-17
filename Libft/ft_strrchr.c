/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:27:39 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/17 10:41:18 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_one;
	int		i;

	i = 0;
	last_one = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_one = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last_one);
}
