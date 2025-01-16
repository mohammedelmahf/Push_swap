/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:04:28 by maelmahf          #+#    #+#             */
/*   Updated: 2024/11/24 18:19:42 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list[FD_MAX];
	char			*next_line;
	size_t			index;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0 || read(fd, &next_line,
			0) < 0)
		return (NULL);
	create_list(&list[fd], fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_line(list[fd]);
	index = 0;
	del_nodes(&list[fd], index);
	return (next_line);
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_line(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		add_node(list, buf);
	}
}

void	add_node(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*current;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->buff = buf;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
	{
		current = *list;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	copy_str(t_list *list, char *next_str)
{
	int	i;
	int	j;

	j = 0;
	if (!list || !next_str)
		return ;
	while (list)
	{
		i = 0;
		while (list->buff[i])
		{
			if (list->buff[i] == '\n')
			{
				next_str[j++] = '\n';
				break ;
			}
			else
			{
				next_str[j++] = list->buff[i];
			}
			i++;
		}
		list = list->next;
	}
	next_str[j] = '\0';
}
