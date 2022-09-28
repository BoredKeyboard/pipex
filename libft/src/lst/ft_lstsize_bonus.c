/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:09:19 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:57:49 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Iterates through the list to determine the size of the list

#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
