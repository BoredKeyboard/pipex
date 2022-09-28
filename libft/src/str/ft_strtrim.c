/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 14:17:55 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:42:44 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Returns a copy of string s1
// Removes the set of characters from the beginning and start of s1

#include "libft.h"
#include <stdlib.h>

// Locates the start of s1 (without the characters in set) using ft_strchr
static size_t	index_start(char const *string, char const *start_set)
{
	size_t	start;

	start = 0;
	while (string[start] != '\0' && ft_strchr(start_set, string[start]) != NULL)
		start++;
	return (start);
}

// Locates the end of s1 (without the characters in set) using ft_strchr
static size_t	index_end(char const *string, char const *end_set)
{
	size_t	end;

	end = ft_strlen(string) - 1;
	while (end > 0 && ft_strchr(end_set, string[end]) != NULL)
		end--;
	return (end);
}

// Creates a substr using the start and end from the two above functions
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = index_start(s1, set);
	if (s1[start] == '\0')
		return (ft_strdup(""));
	end = index_end(s1, set);
	len = end - start + 1;
	return (ft_substr(s1, (unsigned int)start, len));
}
