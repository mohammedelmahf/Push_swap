/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:04:54 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/10 16:05:47 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/get_next_line.h"



void	append_to_list(t_data **listt, char *buff)
{
	t_data	*new_node;
	t_data	*last_node;

	last_node = findlastnode(*listt);
	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return ;
	if (!last_node)
		*listt = new_node;
	else
		last_node->next = new_node;
	new_node->save = buff;
	new_node->next = NULL;
}

void	create_list(t_data **listt, int fd)
{
	char	*buffer;
	ssize_t	readbytes;

	while (!new_line(*listt))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[readbytes] = '\0';
		append_to_list(listt, buffer);
	}
}

char	*get_line(t_data **listt)
{
	size_t	line_length;
	char	*line;

	line_length = length_to_newline(*listt);
	line = malloc(sizeof(char) * (line_length + 1));
	if (!line)
		return (NULL);
	line[line_length] = '\0';
	copy_the_line(line, *listt);
	return (line);
}

void	trimlist(t_data **listt)
{
	t_data	*lastnode;
	t_data	*newnode;
	char	*buff;
	int		i;
	int		j;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	newnode = malloc(sizeof(t_data));
	if (!buff || !newnode)
		return ;
	lastnode = findlastnode(*listt);
	i = 0;
	j = 0;
	while (lastnode->save[i] && lastnode->save[i] != '\n')
		i++;
	i++;
	while (lastnode->save[i])
		buff[j++] = lastnode->save[i++];
	buff[j] = '\0';
	newnode->save = buff;
	newnode->next = NULL;
	free_malloc(listt, newnode, buff);
}

char	*get_next_line(int fd)
{
	static t_data	*listt;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&listt, fd);
	if (!listt)
		return (NULL);
	line = get_line(&listt);
	trimlist(&listt);
	return (line);
}
