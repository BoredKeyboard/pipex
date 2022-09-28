/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:25 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 13:47:59 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Sets len amount of characters in s to c

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*g;

	g = (unsigned char *)s;
	while (len > 0)
	{
		len--;
		g[len] = (unsigned char)c;
	}
	return (s);
}
