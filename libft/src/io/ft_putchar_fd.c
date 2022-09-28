/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 14:11:59 by mforstho      #+#    #+#                 */
/*   Updated: 2022/03/08 11:35:51 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Writes a character

#include "libft.h"
#include <unistd.h>

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
