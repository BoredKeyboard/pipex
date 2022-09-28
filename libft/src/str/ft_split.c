/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/26 13:03:42 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/23 12:42:28 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Splits the string s into an array of strings
// Splits using the delimiting character c

#include "libft.h"
#include <stdlib.h>

// Does the opposite of ft_strchr
// Finds the first character that isn't c
static char	*ft_str_not_chr(const char *s, int c)
{
	size_t	i;
	char	c2;
	char	*s2;

	if (s == NULL)
		return (NULL);
	i = 0;
	c2 = (char)c;
	s2 = (char *)s;
	if (c2 == '\0')
	{
		if (s2[0] == '\0')
			return (NULL);
		return (s2);
	}
	while (s2[i] != '\0')
	{
		if (s2[i] != c2)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}

// Uses ft_str_not_chr to determine the start and ft_strchr to determine the end
// of a word
// Increments count to track the amount of words
static size_t	word_count(char const *s, char c)
{
	size_t	count;
	char	*start;
	char	*end;
	char	*tmp;

	count = 0;
	tmp = (char *)s;
	while (tmp != NULL && tmp[0] != '\0')
	{
		start = ft_str_not_chr(tmp, c);
		if (start == NULL)
			break ;
		end = ft_strchr(start, c);
		count++;
		tmp = end;
	}
	return (count);
}

// Frees each string in the array and then frees the array itself
static char	**free_split_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	char	*start;
	char	*end;

	if (s == NULL)
		return (NULL);
	array = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	start = ft_str_not_chr(s, c);
	while (start != NULL && (c != '\0' || i == 0))
	{
		end = ft_strchr(start, c);
		if (end == NULL)
			array[i] = ft_strdup(start);
		else
			array[i] = ft_substr(start, 0, (size_t)(end - start));
		if (array[i] == NULL)
			return (free_split_array(array));
		i++;
		start = ft_str_not_chr(end, c);
	}
	return (array);
}
