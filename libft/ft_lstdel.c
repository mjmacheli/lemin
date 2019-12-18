/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 12:23:58 by mmacheli          #+#    #+#             */
/*   Updated: 2018/06/18 08:30:26 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = (*alst);
	while (temp)
	{
		del(temp->content, temp->content_size);
		free((*alst));
		(*alst) = NULL;
		temp = temp->next;
		(*alst) = temp;
	}
}
