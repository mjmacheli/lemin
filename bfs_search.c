/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:08:38 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 09:52:33 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		bfs(t_farm **farm, t_room *start)
{
	t_room	*tmp_room;
	t_queue	*queue;
	t_queue	*head;
	t_link	*link;

	queue = create_queue(start);
	while (queue)
	{
		head = queue;
		link = head->room->linked;
		while (link)
		{
			tmp_room = get_room(*farm, link->name);
			link = link->next;
			if (!tmp_room->visited)
			{
				set_room(&tmp_room, head->room->level + 1, head->room);
				add_to_queue(&queue, create_queue(tmp_room));
			}
			else
				remove_from_linked(farm, tmp_room, head);
		}
		remove_from_queue(&queue);
	}
}

static void		clean_end(t_farm **farm, t_room **e, t_link *s, int n)
{
	t_link	*e_link;
	t_room	*tmp;
	int		min;
	char	**r;
	int		i;

	r = ft_alloc_grid(n);
	i = -1;
	while (++i >= 0 && s)
	{
		e_link = (*e)->linked;
		if (linked_to_same_room(s->name, e_link, (*e)->name))
			r[i] = (ft_strequ(s->name, (*e)->name) ? (*farm)->start : s->name);
		else
		{
			min = n;
			while (e_link && (tmp = get_room(*farm, e_link->name)))
			{
				r[i] = check_ancestry(tmp, s, min) ? tmp->name : r[i];
				e_link = e_link->next;
			}
		}
		s = s->next;
	}
	clean_up(farm, e, r, i);
}

void			transverse_farm(t_farm **farm)
{
	t_room	*start_room;
	t_room	*end_room;
	t_link	*s_link;

	if ((*farm)->g_cmd && (*farm)->g_room && (*farm)->g_links)
	{
		start_room = get_room(*farm, (*farm)->start);
		set_room(&start_room, 0, start_room);
		bfs(farm, start_room);
		end_room = get_room(*farm, (*farm)->end);
		if (!end_room->visited)
		{
			ft_putendl("Error");
			destroy_farm(farm);
			exit(0);
		}
		s_link = start_room->linked;
		clean_end(farm, &end_room, s_link, get_room_nbr(*farm));
	}
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}
