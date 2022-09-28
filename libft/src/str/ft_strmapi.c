/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 13:43:38 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 15:05:37 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Applies function f to each character of string s
// Puts the results from successive applications of f
// to each character of s in a new string

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*newstr;

	if (s == NULL)
		return (NULL);
	newstr = malloc(ft_strlen(s) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
