/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:03 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 12:52:53 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is printable

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
