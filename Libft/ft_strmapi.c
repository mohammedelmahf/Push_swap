/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:52:34 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/07 17:40:45 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rslt;
	size_t	i;
	size_t	len;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	rslt = malloc((len + 1) * sizeof(char));
	if (rslt == NULL)
		return (NULL);
	while (s[i])
	{
		rslt[i] = f(i, s[i]);
		i++;
	}
	rslt[len] = '\0';
	return (rslt);
}
