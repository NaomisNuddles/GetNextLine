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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 4096
# endif

typedef struct s_rem
{
	char		*buff;
}	t_rem;

typedef struct s_buffer
{
	t_rem			rem[MAX_FD];
	char			lag[BUFFER_SIZE + 1];
	ssize_t			size;
}	t_buffer;

//get_next_line_utils.c
size_t			ft_strlen(const char *src);
void			*ft_memset(void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_calloc(size_t bit, size_t n);

//get_next_line.c
char			*line_pull(char *buff, size_t len);
size_t			line_check(char *buff);
char			*buff_save(char *buff, char *lag);
char			*get_next_line(int fd);

#endif //GET_NEXT_LINE_BONUS_H