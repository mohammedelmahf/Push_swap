/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:10:18 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/24 13:49:44 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	len_to_newline(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buff[i])
		{
			if (list->buff[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

int	found_line(t_list *list)
{
	long	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->buff[i] && i < BUFFER_SIZE)
		{
			if (list->buff[i] == '\n')
			{
				return (1);
			}
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	trim_word(char *dst, const char *src, size_t index)
{
	size_t	i;
	size_t	len;
	size_t	size;

	len = 0;
	while (dst[len])
		len++;
	size = len - index;
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	check_node(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	del_nodes(t_list **lst, size_t i)
{
	t_list	*tmp;

	while (*lst)
	{
		if (!check_node((*lst)->buff))
		{
			free((*lst)->buff);
			tmp = (*lst)->next;
			free((*lst));
			*lst = tmp;
		}
		else
		{
			i = 0;
			while ((*lst)->buff[i])
			{
				if ((*lst)->buff[i] == '\n')
				{
					trim_word((*lst)->buff, ((*lst)->buff) + i + 1, i + 1);
					return ;
				}
				i++;
			}
		}
	}
}
