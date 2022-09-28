/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 14:31:23 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/15 11:39:54 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Iterates through the list, applies function f to the content of each element

#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
