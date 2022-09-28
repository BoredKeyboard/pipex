/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:25:41 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:46:51 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Converts a lowercase character to uppercase

#include "libft.h"

int	ft_toupper(int c)
{
	int	i;

	i = c;
	if (c >= 'a' && c <= 'z')
	{
		i = i - 32;
		return (i);
	}
	return (c);
}

// i = i - 'a' + 'A'
// i = i + ('A' - 'a')
