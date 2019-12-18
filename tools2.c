/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:29:52 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 10:30:24 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clean_up(t_farm **farm, t_room **end, char **rooms, int n)
{
	t_link	*e_link;
	t_room	*tmp;
	int		index;
	int		found;

	e_link = (*end)->linked;
	while (e_link)
	{
		index = 0;
		found = 0;
		tmp = get_room(*farm, e_link->name);
		e_link = e_link->next;
		while (index < n)
		{
			if (rooms[index])
			{
				if (ft_strequ(rooms[index], tmp->name))
					found = 1;
			}
			index++;
		}
		if (!found)
			destroy_tunnel(&tmp, end);
	}
	free(rooms);
}

void		remove_from_linked(t_farm **farm, t_room *tmp_r, t_queue *head)
{
	if (!ft_strequ(tmp_r->name, (*farm)->end))
	{
		if (!ft_strequ(head->room->name, (*farm)->end))
		{
			if (!ft_strequ(tmp_r->name, head->room->visitedby))
				destroy_tunnel(&head->room, &tmp_r);
		}
	}
}

int			linked_to_same_room(char *name, t_link *link, char *end)
{
	if (ft_strequ(name, end))
		return (1);
	while (link)
	{
		if (ft_strequ(name, link->name))
			return (1);
		link = link->next;
	}
	return (0);
}

int			check_ancestry(t_room *tmp, t_link *s_link, int min_lvl)
{
	if (ft_strequ(tmp->parent, s_link->name))
	{
		if (tmp->level < min_lvl)
		{
			min_lvl = tmp->level;
			return (1);
		}
	}
	return (0);
}
