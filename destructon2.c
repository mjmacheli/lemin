/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:08:38 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 09:52:33 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		destroy_path(t_path **path)
{
	t_path	*tmp;

	if (*path)
	{
		while (*path)
		{
			tmp = *path;
			*path = (*path)->next;
			ft_destroy_2d((void**)tmp->rooms);
			free(tmp);
		}
	}
}

static void		destroy_ants(t_ant **ants)
{
	t_ant	*tmp;

	if (*ants)
	{
		while (*ants)
		{
			tmp = *ants;
			*ants = (*ants)->next;
			if (tmp->path)
				destroy_path(&tmp->path);
			free(tmp);
		}
	}
}

static void		destroy_rooms(t_room **rooms)
{
	t_room	*tmp;

	if (*rooms)
	{
		while (*rooms)
		{
			tmp = *rooms;
			*rooms = (*rooms)->next;
			ft_strdel(&tmp->name);
			ft_strdel(&tmp->parent);
			ft_strdel(&tmp->visitedby);
			while (tmp->linked)
				destroy_link(&tmp->linked);
			free(tmp);
		}
	}
}

void		destroy_farm(t_farm **farm)
{
	if (*farm)
	{
		ft_strdel(&(*farm)->start);
		ft_strdel(&(*farm)->end);
		destroy_rooms(&(*farm)->rooms);
		destroy_ants(&(*farm)->ants);
		free(*farm);
		*farm = NULL;
	}
}