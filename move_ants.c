/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 05:04:41 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 10:16:48 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		max_moves(int *dist, int num, int ants)
{
	int	max;
	int	index;

	index = 0;
	max = -2147483648;
	while (index < num)
	{
		if ((ants / num) + (dist[index] - 1) > max)
			max = (ants / num) + (dist[index] - 1);
		index++;
	}
	return (max);
}

static int		num_of_paths_to_use(t_path *paths, int num, int ants, int ret)
{
	int		dist[num];
	int		moves[num];
	int		index;
	int		min;
	t_path	*tmp_path;

	index = 0;
	min = 2147483647;
	tmp_path = paths;
	while (tmp_path)
	{
		dist[index++] = tmp_path->n_rooms - 1;
		tmp_path = tmp_path->next;
	}
	index = 0;
	while (++index <= num)
		moves[index - 1] = max_moves(dist, index, ants);
	index = 0;
	while (index < num)
	{
		ret = (moves[index] < min ? index : ret);
		min = (moves[index] < min ? moves[index] : min);
		index++;
	}
	return (ret + 1);
}

static void		print_ant(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->num);
	ft_putchar('-');
	ft_putstr(ant->path->rooms[ant->dist]);
	ft_putchar(' ');
}

void			init_ants(t_farm **farm, t_path *paths, int ind)
{
	int		num_paths;
	int		paths_2u;
	int		p_num;
	t_path	*tmp;
	t_ant	*ant;

	num_paths = count_neighbours(get_room(*farm, (*farm)->end));
	paths_2u = num_of_paths_to_use(paths, num_paths, (*farm)->num_ants, 0);
	while (ind++ < (*farm)->num_ants)
	{
		tmp = paths;
		p_num = ind % paths_2u;
		ant = create_ant(ind, p_num ? p_num : paths_2u);
		while (ant->p_num-- > 1)
			tmp = tmp->next;
		ant->path = tmp;
		ant->move = (ind / paths_2u) + (ind % paths_2u ? 1 : 0);
		add_ant(&(*farm)->ants, ant);
	}
}

void			move_ants(t_farm **farm)
{
	int		round;
	int		moved;
	t_ant	*ants;

	round = 1;
	while ((*farm)->num_ants)
	{
		ants = (*farm)->ants;
		moved = 0;
		while (ants)
		{
			if (ants->move <= round && ants->dist < ants->path->n_rooms)
			{
				print_ant(ants);
				ants->dist++;
				moved++;
			}
			ants = ants->next;
		}
		if (!moved)
			break ;
		ft_putchar('\n');
		round++;
	}
}
