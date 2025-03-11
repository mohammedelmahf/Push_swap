/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:04:58 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/11 17:08:58 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_data	*findlastnode(t_data *listt)
{
	if (!listt)
		return (NULL);
	while (listt->next)
		listt = listt->next;
	return (listt);
}

int	new_line(t_data *listt)
{
	int	i;

	while (listt)
	{
		i = 0;
		while (listt->save[i] && i < BUFFER_SIZE)
		{
			if (listt->save[i] == '\n')
				return (1);
			i++;
		}
		listt = listt->next;
	}
	return (0);
}

size_t	length_to_newline(t_data *listt)
{
	int		i;
	size_t	len;

	len = 0;
	while (listt)
	{
		i = 0;
		while (listt->save[i] && i < BUFFER_SIZE)
		{
			if (listt->save[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		listt = listt->next;
	}
	return (len);
}

void	copy_the_line(char *line, t_data *listt)
{
	int	i;
	int	j;

	j = 0;
	while (listt)
	{
		i = 0;
		while (listt->save[i] && listt->save[i] != '\n')
		{
			line[j] = listt->save[i];
			i++;
			j++;
		}
		if (listt->save[i] == '\n')
		{
			line[j] = listt->save[i];
			break ;
		}
		listt = listt->next;
	}
}

void	free_malloc(t_data **listt, t_data *newnode, char *buff)
{
	t_data	*tmp;

	if (!(*listt))
		return ;
	while (*listt)
	{
		tmp = (*listt)->next;
		free((*listt)->save);
		free(*listt);
		*listt = tmp;
	}
	*listt = NULL;
	if (newnode->save[0])
		*listt = newnode;
	else
	{
		free(buff);
		free(newnode);
	}
}
