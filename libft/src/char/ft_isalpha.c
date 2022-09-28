/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:23:39 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 12:52:22 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is alphabetical

#include "libft.h"

int	ft_isalpha(int s)
{
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
		return (1);
	return (0);
}
