/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:46 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/22 14:35:05 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Copies up to dstsize characters from string src to dst
// NUL-terminates the result if dstsize isn't 0

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ds;
	size_t	i;
	char	*d;
	char	*s;

	ds = dstsize - 1;
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	while (i < ds && src[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen((char *)src));
}
