/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 12:43:24 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:55:05 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Returns the last element of the list

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
