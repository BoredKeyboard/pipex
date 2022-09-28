/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 14:25:33 by mforstho      #+#    #+#                 */
/*   Updated: 2022/05/24 11:47:18 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	var;
	int		isneg;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	isneg = 0;
	if (n < 0)
	{
		isneg = 1;
		if (write(fd, "-", 1) < 0)
			return (-1);
		n *= -1;
	}
	var = 0;
	if (n / 10 != 0)
		var = ft_putnbr_fd(n / 10, fd);
	if (var < 0)
		return (-1);
	if (ft_putchar_fd((n % 10) + '0', fd) < 0)
		return (-1);
	return (var + 1 + isneg);
}
