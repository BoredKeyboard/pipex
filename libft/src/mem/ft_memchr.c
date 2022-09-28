/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:06 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 13:47:35 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Locates the first occurance of c in s if it exists within n bytes

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	c2;

	i = 0;
	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (i < n)
	{
		if (s2[i] == c2)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
