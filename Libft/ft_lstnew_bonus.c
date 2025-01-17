/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:43:40 by maelmahf          #+#    #+#             */
/*   Updated: 2025/01/17 10:39:43 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rslt;

	rslt = malloc(sizeof(t_list));
	if (rslt == NULL)
		return (NULL);
	rslt->content = content;
	rslt->next = NULL;
	return (rslt);
}
