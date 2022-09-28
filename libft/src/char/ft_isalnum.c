/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:23:36 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 12:52:13 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Checks if the given character is alphabetical or a digit

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
