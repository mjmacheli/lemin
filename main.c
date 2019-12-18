/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 21:59:24 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 15:15:21 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		update_farm(t_farm **farm, char **tmp, char **cmd)
{
	if (ft_is_number(*tmp) && !(*farm)->g_ants && ft_atoi(*tmp) >= 0)
	{
		(*farm)->num_ants = ft_atoi(*tmp);
		(*farm)->g_ants = 1;
	}
	else if (valid_cmd(*tmp) && !*cmd && !(*farm)->g_links && (*farm)->g_ants)
		*cmd = ft_strdup(*tmp);
	else if (valid_room(*tmp, *farm) && !(*farm)->g_links && (*farm)->g_ants)
	{
		add_room_to_farm(farm, create_room(*tmp), cmd);
		(*farm)->g_cmd = ((*farm)->start && (*farm)->end) ? 1 : 0;
	}
	else if ((*farm)->g_cmd && (*farm)->g_room && link_test(*tmp, *farm))
		create_tunnel(farm, *tmp);
	else if (valid_cmd(*tmp) || !is_comment(*tmp))
	{
		ft_putendl("Error");
		free(*tmp);
		if (*cmd)
			free(*cmd);
		exit(0);
	}
	free(*tmp);
}

int				main(void)
{
	char	*line;
	char	*tmp;
	char	*cmd;
	t_farm	*farm;
	t_path	*paths;

	line = NULL;
	cmd = NULL;
	farm = create_farm();
	while (get_next_line(0, &line) > 0)
	{
		ft_replace(&line, '\t', ' ');
		tmp = ft_strtrim(line);
		update_farm(&farm, &tmp, &cmd);
	}
	if (line)
		free(line);
	transverse_farm(&farm);
	paths = NULL;
	get_paths(farm, &paths);
	sort_paths(&paths);
	init_ants(&farm, paths, 0);
	move_ants(&farm);
	return (0);
}
