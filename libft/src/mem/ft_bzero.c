/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/07 17:03:25 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 13:11:14 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Writes maximum n zero's to string s

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
