/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:27:40 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/31 23:33:06 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static t_buffer	dat;
	char			*res;

	if (fd < 0 || fd > MAX_FD - 1 || BUFFER_SIZE <= 0)
		return (0);
	dat.size = read(fd, dat.lag, BUFFER_SIZE);
	res = NULL;
	while (dat.size > 0 || (!dat.size && dat.rem[fd].buff && *dat.rem[fd].buff))
	{
		if (dat.size)
			dat.rem[fd].buff = buff_save(dat.rem[fd].buff, dat.lag);
		if (!dat.rem[fd].buff && dat.size)
			return (NULL);
		if (line_check(dat.rem[fd].buff) || !dat.size)
		{
			res = line_pull(dat.rem[fd].buff, line_check(dat.rem[fd].buff));
			if (!res)
				break ;
			return (res);
		}
		dat.size = read(fd, dat.lag, BUFFER_SIZE);
	}
	free(dat.rem[fd].buff);
	dat.rem[fd].buff = NULL;
	return (NULL);
}
