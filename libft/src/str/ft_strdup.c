/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:41 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 13:59:57 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Allocates sufficient memory for a copy of s1 and does the copy

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s2;

	i = 0;
	len = ft_strlen((char *)s1) + 1;
	s2 = malloc(len);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
