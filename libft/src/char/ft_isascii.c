/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:23:58 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 12:52:35 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is part of the ascii table

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
