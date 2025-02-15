/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maelmahf <maelmahf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:57:30 by maelmahf          #+#    #+#             */
/*   Updated: 2025/02/15 15:48:33 by maelmahf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
int		ft_strnl_gnl(char *s);
char	*get_line(char *buffer);
char	*get_rest(char *buffer, size_t line_size);
char	*get_read(int fd, char *buffer);
char	*get_next_line(int fd);

#endif // !GET_NEXT_LINE_H