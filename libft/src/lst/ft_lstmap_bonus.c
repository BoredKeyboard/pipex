/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 14:37:09 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/15 11:40:34 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Iterates through the list, aplies function f to the content of each element
// Creates a new list resulting of the successive applications of function f
// Uses function del to delete the content of an element if needed

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	**current;

	if (!lst || !f)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	lst = lst->next;
	current = &(newlst->next);
	while (lst)
	{
		*current = ft_lstnew(f(lst->content));
		if (current == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		lst = lst->next;
		current = &((*current)->next);
	}
	return (newlst);
}
