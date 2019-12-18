/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:10:04 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 10:10:53 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*init_path(int n_rooms)
{
	t_path	*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path->n_rooms = n_rooms;
	path->rooms = ft_alloc_grid(n_rooms);
	path->next = NULL;
	return (path);
}

void		add_to_paths(t_path **allpaths, t_path *a_path)
{
	a_path->next = *allpaths;
	*allpaths = a_path;
}

void		get_paths(t_farm *farm, t_path **all_paths)
{
	t_room	*room;
	t_path	*a_path;
	t_link	*link;
	int		index;

	link = get_room(farm, farm->end)->linked;
	while (link)
	{
		room = get_room(farm, link->name);
		a_path = init_path(room->level + 2);
		index = room->level + 1;
		a_path->rooms[index--] = ft_strdup(farm->end);
		a_path->rooms[0] = ft_strdup(farm->start);
		while (index > 0)
		{
			a_path->rooms[index--] = room->name;
			room = get_room(farm, room->visitedby);
		}
		if (!*all_paths)
			*all_paths = a_path;
		else
			add_to_paths(all_paths, a_path);
		link = link->next;
	}
}
