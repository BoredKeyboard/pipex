/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 11:35:03 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/15 11:38:01 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Converts an integer to ascii

#include "libft.h"
#include <stdlib.h>

// Counts how many digits are in n
static int	count_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

// Iterates from end to start through the new string
// adding the digits as characters
char	*ft_itoa(int n)
{
	int		count;
	char	*a;
	int		is_neg;

	count = count_digits(n);
	a = malloc((size_t)count + 1);
	if (a == NULL)
		return (NULL);
	a[count] = '\0';
	count--;
	is_neg = (n < 0);
	if (!is_neg)
		n = -n;
	while (count >= 0)
	{
		a[count] = '0' - (n % 10);
		n /= 10;
		count--;
	}
	if (is_neg)
		a[0] = '-';
	return (a);
}

/*
2564 % 10 = 4
2564 / 10 = 256
256 % 10 = 5
256 / 10 = 25
25 & 10 = 5
25 / 10 = 2
*/
