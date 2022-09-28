/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:52 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:19:39 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Compares up to n amount of characters from strings s1 and s2

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1 = (unsigned char *)s1;
	const unsigned char	*str2 = (unsigned char *)s2;

	i = 0;
	if (i == n)
		return (0);
	while (str1[i] == str2[i] && i < n && str1[i] != '\0')
	{
		i++;
		if (i == n)
			return (0);
	}
	return (str1[i] - str2[i]);
}
