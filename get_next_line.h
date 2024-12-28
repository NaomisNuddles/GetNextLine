/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:31 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/25 10:27:31 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 512
# endif

typedef struct s_buffer
{
	int				fd;
	char			buff_read[BUFFER_SIZE + 1];
	char			*lines;
	struct s_buffer	*next;
}	t_buffer;

size_t		ft_strlen(const char *src);
void		*ft_memset(void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_calloc(size_t bit, size_t n);
char		*line_construct(char *src, char *buff);

//get next line
char		*get_next_line(int fd);

//utils
#endif //GET_NEXT_LINE_H