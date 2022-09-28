/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 18:08:24 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:57:30 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Returns a new element with the content data

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *data)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = data;
	lst->next = NULL;
	return (lst);
}
