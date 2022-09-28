/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/01 13:07:17 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:51:30 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Adds the element new to the end of the list

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
