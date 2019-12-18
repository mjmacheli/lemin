/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:59:47 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 10:31:48 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_room_nbr(t_farm *farm)
{
	t_room	*tmp;
	int		rooms;

	rooms = 0;
	tmp = farm->rooms;
	while (tmp)
	{
		rooms++;
		tmp = tmp->next;
	}
	return (rooms);
}

void		add_to_links(t_link **linked, t_link *link)
{
	if (!*linked)
		*linked = link;
	else
	{
		link->next = *linked;
		*linked = link;
	}
}

t_room		*get_room(t_farm *farm, char *name)
{
	t_room *tmp;

	tmp = farm->rooms;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

int			count_neighbours(t_room *room)
{
	int		neighbours;
	t_link	*tmp;

	neighbours = 0;
	tmp = room->linked;
	while (tmp)
	{
		neighbours++;
		tmp = tmp->next;
	}
	return (neighbours);
}

void		set_room(t_room **r1, int level, t_room *r2)
{
	(*r1)->level = level;
	(*r1)->visitedby = ft_strdup(r2->name);
	(*r1)->visited = 1;
	if (level == 0 || level == 2)
		(*r1)->parent = ft_strdup(r2->name);
	else
		(*r1)->parent = ft_strdup(r2->parent);
}
