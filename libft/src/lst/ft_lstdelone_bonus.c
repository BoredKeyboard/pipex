/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:38:19 by mforstho      #+#    #+#                 */
/*   Updated: 2021/11/11 14:54:01 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Free's the memory of the given elements content using the function del

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del != NULL && lst != NULL)
		del(lst->content);
	free(lst);
}
