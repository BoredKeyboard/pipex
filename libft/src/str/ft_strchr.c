/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:37 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:24:13 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Locates the first occurance of character c in string s

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c2;
	char	*s2;

	i = 0;
	c2 = (char)c;
	s2 = (char *)s;
	if (c2 == '\0')
	{
		i = ft_strlen(s2);
		return (&s2[i]);
	}
	while (s2[i] != '\0')
	{
		if (s2[i] == c2)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
