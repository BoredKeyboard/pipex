/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:57 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 15:04:58 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Searches up to len amount of characters in string haystack
// for the string needle

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			start;

	i = 0;
	start = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (start + i < len && haystack[start + i] != '\0')
	{
		if (needle[i] == haystack[start + i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack + start);
		}
		else
		{
			i = 0;
			start++;
		}
	}
	return (NULL);
}
