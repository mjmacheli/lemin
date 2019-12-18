/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:51:34 by mmacheli          #+#    #+#             */
/*   Updated: 2018/07/16 10:36:14 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *ret;

	ret = f(lst);
	temp = ret;
	while ((lst = lst->next))
	{
		temp->next = f(lst);
		temp = temp->next;
	}
	temp->next = NULL;
	return (ret);
}
