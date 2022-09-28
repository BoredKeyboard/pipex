/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 14:22:59 by mforstho      #+#    #+#                 */
/*   Updated: 2022/03/08 11:49:49 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Writes a string ending with a newline

#include "libft.h"
#include <unistd.h>

ssize_t	ft_putendl_fd(char *s, int fd)
{
	ssize_t	var;

	var = ft_putstr_fd(s, fd);
	if (var < 0)
		return (-1);
	if (ft_putchar_fd('\n', fd) < 0)
		return (-1);
	return (var + 1);
}
