/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 06:08:09 by mmacheli          #+#    #+#             */
/*   Updated: 2018/09/20 10:11:50 by mmacheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include <stdlib.h>

typedef struct			s_link
{
	char				*name;
	struct s_link		*next;
}						t_link;

typedef struct			s_room
{
	char				*name;
	int					level;
	int					visited;
	char				*parent;
	char				*visitedby;
	int					ants_inside;
	t_link				*linked;
	struct s_room		*next;
}						t_room;

typedef struct			s_queue
{
	t_room				*room;
	struct s_queue		*next;
}						t_queue;

typedef	struct			s_path
{
	int					n_rooms;
	char				**rooms;
	struct s_path		*next;
}						t_path;

typedef struct			s_ant
{
	int					num;
	int					p_num;
	int					move;
	int					dist;
	t_path				*path;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_farm
{
	int					num_ants;
	int					g_ants;
	int					g_room;
	int					g_links;
	int					g_cmd;
	char				*start;
	char				*end;
	t_room				*rooms;
	t_ant				*ants;
}						t_farm;

void					move_ants(t_farm **farm);
void					sort_paths(t_path **paths);
t_ant					*create_ant(int num, int p_num);
void					add_ant(t_ant **colony, t_ant *ant);
void					transverse_farm(t_farm **farm);
void					init_ants(t_farm **farm, t_path *paths, int ind);
int						check_ancestry(t_room *tmp, t_link *link, int min_lvl);
int						linked_to_same_room(char *n, t_link *l, char *e);
void					remove_from_linked(t_farm **f, t_room *tr, t_queue *h);
void					get_paths(t_farm *farm, t_path **paths);
t_queue					*create_queue(t_room *room);
void					add_to_queue(t_queue **que, t_queue *cue);
void					remove_from_queue(t_queue **que);
void					add_to_links(t_link **linked, t_link *link);
void					set_room(t_room **room, int level, t_room *room2);
void					clean_up(t_farm **farm, t_room **en, char **rs, int n);
int						count_neighbours(t_room *room);
void					destroy_tunnel(t_room **r1, t_room **r2);
t_path					*init_path(int n_rooms);
void					add_to_paths(t_path **paths, t_path *path);
t_room					*get_room(t_farm *farm, char *name);
void					destroy_link(t_link **link);
void					destroy_farm(t_farm **farm);
int						get_room_nbr(t_farm *farm);
int						valid_cmd(char *line);
int						valid_room(char *line, t_farm *farm);
int						link_test(char *line, t_farm *farm);
int						is_comment(char *line);
t_room					*create_room(char *line);
t_farm					*create_farm(void);
void					add_room_to_farm(t_farm **farm, t_room *r, char **cmd);
void					create_tunnel(t_farm **farm, char *line);
#endif
