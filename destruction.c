/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:21:11 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 09:59:44 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			destroy_link(t_link **link)
{
	t_link	*tmp;

	if (*link)
	{
		tmp = *link;
		*link = (*link)->next;
		ft_strdel(&tmp->name);
		free(tmp);
	}
}

static void		destroy_a_link(t_link **link, char *name)
{
	t_link	*tmp;
	t_link	*tmp2;

	if (*link)
	{
		if ((ft_strequ(name, (*link)->name)))
			destroy_link(link);
		else
		{
			tmp = *link;
			tmp2 = tmp;
			while (tmp)
			{
				if (ft_strequ(name, tmp->name))
				{
					destroy_link(&tmp);
					tmp2->next = tmp;
					break ;
				}
				tmp2 = tmp;
				tmp = tmp->next;
			}
		}
	}
}

void			destroy_tunnel(t_room **r1, t_room **r2)
{
	destroy_a_link(&(*r1)->linked, (*r2)->name);
	destroy_a_link(&(*r2)->linked, (*r1)->name);
}

void			remove_from_queue(t_queue **que)
{
	t_queue	*tmp;

	tmp = *que;
	*que = (*que)->next;
	tmp->room = NULL;
	free(tmp);
}
