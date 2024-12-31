/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleandro <nleandro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:22:34 by nleandro          #+#    #+#             */
/*   Updated: 2024/12/31 23:31:39 by nleandro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (src && dst && src < dst && n <= ((size_t)1 << 63) - 1 && n-- > 0)
		*((char *)dst + n) = *((char *)src + n);
	while (src && dst && src > dst && n <= ((size_t)1 << 63) - 1 && n-- > 0)
		*((char *)dst + i - n) = *((char *)src + i - n);
	return (dst);
}

void	*ft_memset(void *src, int c, size_t n)
{
	while (src && n <= ((size_t)1 << 63) - 1 && n-- > 0)
		*((char *)src + n) = c;
	return (src);
}

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src && src[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t bit, size_t n)
{
	void	*res;

	res = 0;
	if (bit <= ((size_t)1 << 63) - 1 && n <= ((size_t)1 << 63) - 1)
		res = malloc(bit * n);
	if (!res)
		return (0);
	if (bit != 0 && n != 0)
		ft_memset(res, 0, bit * n);
	return (res);
}
