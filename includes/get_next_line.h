/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:51:46 by maelmahf          #+#    #+#             */
/*   Updated: 2025/03/10 16:05:25 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_listt
{
	long			value;
	struct s_listt	*next;
}					t_listt;

typedef struct v_listt
{
	char			*save;
	struct v_listt	*next;
}					t_data;

t_data	*findlastnode(t_data *listt);
int	new_line(t_data *listt);
size_t	length_to_newline(t_data *listt);
void	copy_the_line(char *line, t_data *listt);
void	free_malloc(t_data **listt, t_data *newnode, char *buff);
char	*get_next_line(int fd);
void	trimlistt(t_data **listt);
char	*get_line(t_data **listt);
void	create_listt(t_data **listt, int fd);
void	append_to_listt(t_data **listt, char *buff);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif