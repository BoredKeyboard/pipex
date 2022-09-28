/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 11:40:33 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/23 12:43:24 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Creates a substring from string s starting at start and
// up to len amount of characters

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strnlen(const char *c, size_t n)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0' && i < n)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = start;
	j = 0;
	sub = malloc(ft_strnlen(s, len) + 1);
	if (s == NULL || sub == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	while (s[i] != '\0' && j < len)
	{
		sub[j] = (char)s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
