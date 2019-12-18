/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:17:27 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 10:18:20 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*pop(t_path **paths)
{
	t_path	*tmp;

	tmp = *paths;
	*paths = (*paths)->next;
	tmp->next = NULL;
	return (tmp);
}

void			sort_paths(t_path **paths)
{
	t_path	*tmp;
	t_path	*hold;

	tmp = NULL;
	hold = NULL;
	while (*paths)
	{
		tmp = pop(paths);
		if (!hold)
			hold = tmp;
		else if (tmp->n_rooms >= hold->n_rooms)
			add_to_paths(&hold, tmp);
		else
		{
			while (tmp->n_rooms < hold->n_rooms)
				add_to_paths(paths, pop(&hold));
			if (!hold)
				hold = tmp;
			else
				add_to_paths(&hold, tmp);
		}
	}
	while (hold)
		add_to_paths(paths, pop(&hold));
}
