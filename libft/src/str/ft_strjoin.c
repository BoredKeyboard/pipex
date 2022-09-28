/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/20 13:21:52 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/16 11:54:08 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Allocates sufficient memory to new string
// Adds s1 and s2 together in the new string

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*comb;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	comb = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (comb == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		comb[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		comb[i] = s2[j];
		i++;
		j++;
	}
	comb[i] = '\0';
	return (comb);
}
