/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_power_u_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:23:59 by mforstho      #+#    #+#                 */
/*   Updated: 2022/02/03 11:48:04 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	calc_power_u_base(int count, int base)
{
	int				i;
	unsigned long	power;

	i = 1;
	power = 1;
	while (i < count)
	{
		power *= base;
		i++;
	}
	return (power);
}
