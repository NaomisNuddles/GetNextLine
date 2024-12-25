/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:40 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/25 01:22:40 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[MAX_FD][BUFFER_SIZE + 1];
	char		*res;
	ssize_t		size;

	if (fd < 0 || fd > MAX_FD - 1 || BUFFER_SIZE <= 0)
		return (0);
	size = 1;
	res = NULL;
	while (size > 0)
	{
		if (buff[fd][0])
		{
			res = line_construct(res, buff[fd]);
			if (!res)
				return (NULL);
			if (res[ft_strlen(res) - 1] == '\n')
				return (res);
		}
		size = read(fd, buff[fd], BUFFER_SIZE);
		if (size == 0)
			return (res);
	}
	ft_memset(buff[fd], 0, BUFFER_SIZE);
	return (free(res), NULL);
}
