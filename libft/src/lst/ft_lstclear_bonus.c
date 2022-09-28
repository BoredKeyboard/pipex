/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 12:19:58 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:52:55 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Deletes and frees the given element and every successor of that element
// Uses the function del and free

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
