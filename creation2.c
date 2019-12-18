/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 09:53:17 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 09:57:53 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue		*create_queue(t_room *room)
{
	t_queue *que;

	if (!(que = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	que->room = room;
	que->next = NULL;
	return (que);
}

void		add_to_queue(t_queue **que, t_queue *cue)
{
	t_queue	*tmp;

	tmp = *que;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = cue;
}

t_ant		*create_ant(int num, int p_num)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ant->num = num;
	ant->p_num = p_num;
	ant->path = NULL;
	ant->move = 0;
	ant->dist = 1;
	ant->next = NULL;
	return (ant);
}

void		add_ant(t_ant **colony, t_ant *ant)
{
	t_ant	*tmp;

	if (!*colony)
		*colony = ant;
	else
	{
		tmp = *colony;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ant;
	}
}
