/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:25:07 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:23:56 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Locates the last occurance of character c in string s

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c2;
	char	*s2;

	i = (int)ft_strlen((char *)s);
	c2 = (char)c;
	s2 = (char *)s;
	if (c == '\0')
	{
		while (i >= 0)
		{
			if (s2[i] == '\0')
				return (&s2[i]);
			i--;
		}
	}
	while (i >= 0)
	{
		if (s2[i] == c2)
			return (&s2[i]);
		i--;
	}
	return (NULL);
}
