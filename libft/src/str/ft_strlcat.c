/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:23:08 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:15:14 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Appends string src to the end of dst and NUL-terminates the string

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	if (i == dstsize)
		return (dstsize + ft_strlen(src));
	len = i;
	while (i < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}
