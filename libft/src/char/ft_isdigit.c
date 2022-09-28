/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:01 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 12:52:47 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is a digit

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
