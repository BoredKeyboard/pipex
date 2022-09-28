/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_digits_u_base.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:22:22 by mforstho      #+#    #+#                 */
/*   Updated: 2022/02/03 11:47:48 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits_u_base(unsigned long n, int base)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
