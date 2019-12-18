/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 14:44:05 by mmacheli          #+#    #+#             */
/*   Updated: 2018/08/04 13:41:30 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		destroy_1(t_fd **list)
{
	t_fd *hold;

	if (*list)
	{
		hold = (*list)->next;
		if ((*list)->store)
		{
			free((*list)->store);
			(*list)->store = NULL;
		}
		free(*list);
		*list = NULL;
		*list = hold;
	}
}

void			destroy_fd(const int fd, t_fd **list)
{
	t_fd	*hold1;
	t_fd	*hold2;

	if (*list)
	{
		if ((*list)->fd == fd)
			destroy_1(list);
		else
		{
			hold1 = *list;
			hold2 = *list;
			while (*list)
			{
				if ((*list)->fd == fd)
				{
					destroy_1(list);
					hold2->next = *list;
					break ;
				}
				hold2 = *list;
				*list = (*list)->next;
			}
			*list = hold1;
		}
	}
}
