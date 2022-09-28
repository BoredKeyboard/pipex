/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 13:51:23 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:51:28 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Adds the element new to the front of the list

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
