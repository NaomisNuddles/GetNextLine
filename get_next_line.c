/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:40 by nleandro          #+#    #+#             */
/*   Updated: 2025/01/07 11:06:01 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_pull(char *buff, size_t len)
{
	char	*str;

	if (!len)
		len = ft_strlen(buff);
	str = ft_calloc(1, len + 1);
	if (!str)
		return (NULL);
	ft_memmove(str, buff, len);
	ft_memmove(buff, &buff[len], ft_strlen(buff) - len);
	ft_memset(&buff[ft_strlen(buff) - len], 0, len);
	return (str);
}

size_t	line_check(char *buff)
{
	size_t	n;

	n = 0;
	if (!buff || !*buff)
		return (0);
	while (buff[n] && buff[n] != '\n')
		n++;
	if (buff[n] != '\n')
		return (0);
	return (n + 1);
}

char	*buff_save(char *buff, char *lag)
{
	char	*str;

	str = ft_calloc(1, ft_strlen(buff) + ft_strlen(lag) + 1);
	if (!str)
		return (free(buff), NULL);
	ft_memmove(str, buff, ft_strlen(buff));
	ft_memmove(&str[ft_strlen(buff)], lag, ft_strlen(lag));
	ft_memset(lag, 0, BUFFER_SIZE);
	return (free(buff), str);
}

char	*get_next_line(int fd)
{
	static t_buffer	data;
	char			*res;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (0);
	data.size = read(fd, data.lag, BUFFER_SIZE);
	res = NULL;
	while (data.size > 0 || (!data.size && data.buff[fd] && *data.buff[fd]))
	{
		if (data.size)
			data.buff[fd] = buff_save(data.buff[fd], data.lag);
		if (!data.buff[fd] && data.size)
			return (NULL);
		if (line_check(data.buff[fd]) || !data.size)
		{
			res = line_pull(data.buff[fd], line_check(data.buff[fd]));
			if (!res)
				break ;
			return (res);
		}
		data.size = read(fd, data.lag, BUFFER_SIZE);
	}
	free(data.buff[fd]);
	data.buff[fd] = NULL;
	return (NULL);
}
