/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:08 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/23 12:40:26 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Compares two strings
// Assumes both strings are n size long

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	n = n - 1;
	while (s11[i] == s22[i] && i < n)
	{
		i++;
	}
	return (s11[i] - s22[i]);
}
