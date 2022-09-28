/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 16:24:21 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/16 11:52:10 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Copies len bytes from src to dst

#include "libft.h"
#include <stddef.h>

// write_forward is called whens src is greater than dst which means that
// all characters in dst will be overwritten, including the '\0'
static void	write_forward(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (i < (int)len)
	{
		d[i] = s[i];
		i++;
	}
}

// write_backward is called when src is smaller than dst which means that one
// or more characters at the end of dst won't be overwritten
// This functions iterates from the end of src to the start excluding the
// '\0' at the end of src so that the string won't be NUL-terminated too early
static void	write_backward(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = (int)len - 1;
	d = (char *)dst;
	s = (char *)src;
	while (i >= 0)
	{
		d[i] = s[i];
		i--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src == NULL && dst == NULL)
		return (NULL);
	else if (src > dst)
		write_forward(dst, src, len);
	else
		write_backward(dst, src, len);
	return (dst);
}
