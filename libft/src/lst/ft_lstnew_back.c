/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/09 16:24:04 by mforstho      #+#    #+#                 */
/*   Updated: 2022/08/09 16:30:02 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_back(t_list **lst, void *data)
{
	t_list	*new_lst;

	new_lst = ft_lstnew(data);
	if (new_lst == NULL)
		return (NULL);
	ft_lstadd_back(lst, new_lst);
	return (new_lst);
}
