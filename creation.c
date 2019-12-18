/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 06:05:38 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 09:56:45 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room				*create_room(char *line)
{
	t_room		*new_room;
	char		**split;

	split = ft_strsplit(line, ' ');
	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	new_room->name = ft_strdup(split[0]);
	new_room->level = 0;
	new_room->visited = 0;
	new_room->ants_inside = 0;
	new_room->parent = NULL;
	new_room->visitedby = NULL;
	new_room->linked = NULL;
	new_room->next = NULL;
	ft_destroy_2d((void**)split);
	return (new_room);
}

t_farm				*create_farm(void)
{
	t_farm	*farm;

	if (!(farm = (t_farm*)malloc(sizeof(t_farm))))
		return (NULL);
	farm->num_ants = 0;
	farm->g_ants = 0;
	farm->g_room = 0;
	farm->g_links = 0;
	farm->g_cmd = 0;
	farm->start = NULL;
	farm->end = NULL;
	farm->rooms = NULL;
	farm->ants = NULL;
	return (farm);
}

void				add_room_to_farm(t_farm **farm, t_room *room, char **cmd)
{
	(*farm)->g_room = 1;
	if (!(*farm)->rooms)
		(*farm)->rooms = room;
	else
	{
		room->next = (*farm)->rooms;
		(*farm)->rooms = room;
	}
	if (*cmd)
	{
		if (ft_strequ(*cmd, "##start"))
			(*farm)->start = ft_strdup(room->name);
		else if (ft_strequ(*cmd, "##end"))
			(*farm)->end = ft_strdup(room->name);
		free(*cmd);
		*cmd = NULL;
	}
}

static t_link		*create_link(char *name)
{
	t_link	*link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	link->name = ft_strdup(name);
	link->next = NULL;
	return (link);
}

void				create_tunnel(t_farm **farm, char *line)
{
	char	**split;
	t_room	*r1;
	t_room	*r2;
	t_link	*copy_link;

	(*farm)->g_links = 1;
	split = ft_strsplit(line, '-');
	r1 = get_room(*farm, split[0]);
	r2 = get_room(*farm, split[1]);
	copy_link = r1->linked;
	ft_destroy_2d((void**)split);
	while (copy_link)
	{
		if (ft_strequ(copy_link->name, r2->name))
			break ;
		copy_link = copy_link->next;
	}
	if (!copy_link)
	{
		add_to_links(&r1->linked, create_link(r2->name));
		add_to_links(&r2->linked, create_link(r1->name));
	}
}
