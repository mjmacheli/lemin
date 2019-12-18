/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 00:05:08 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 10:00:45 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			valid_cmd(char *line)
{
	if (line && (ft_strequ(line, "##start") || ft_strequ(line, "##end")))
		return (1);
	return (0);
}

int			valid_room(char *line, t_farm *farm)
{
	char	**split;
	int		ret;
	t_room	*tmp;

	tmp = farm->rooms;
	split = ft_strsplit(line, ' ');
	ret = 1;
	while (tmp)
	{
		if (ft_strequ(tmp->name, split[0]))
			ret = 0;
		tmp = tmp->next;
	}
	if (ft_items_in_grid((void**)split) != 3)
		ret = 0;
	else if (!(ft_is_number(split[1]) && ft_is_number(split[2])))
		ret = 0;
	else if (split[0][0] == 'L' || split[0][0] == '#')
		ret = 0;
	ft_destroy_2d((void**)split);
	return (ret);
}

int			link_test(char *line, t_farm *farm)
{
	char	**split;
	int		ret;
	t_room	*tmp;
	int		r1;
	int		r2;

	ret = 1;
	split = ft_strsplit(line, '-');
	tmp = farm->rooms;
	r1 = 0;
	r2 = 0;
	if (ft_items_in_grid((void**)split) != 2)
		ret = 0;
	while (ret && tmp)
	{
		if (ft_strequ(tmp->name, split[0]))
			r1 = 1;
		else if (ft_strequ(tmp->name, split[1]))
			r2 = 1;
		tmp = tmp->next;
	}
	if (!r1 || !r2 || ft_strequ(split[0], split[1]))
		ret = 0;
	ft_destroy_2d((void**)split);
	return (ret);
}

int			is_comment(char *line)
{
	if (line[0] == '#')
		return (1);
	return (0);
}
