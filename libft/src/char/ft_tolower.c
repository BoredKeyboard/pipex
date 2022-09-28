/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:25:36 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:46:29 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Converts an uppercase character to lowercase

#include "libft.h"

int	ft_tolower(int c)
{
	int	i;

	i = c;
	if (c >= 'A' && c <= 'Z')
	{
		i = i + 32;
		return (i);
	}
	return (c);
}

// i = i - 'A' + 'a'
// i = i + ('a' - 'A')
