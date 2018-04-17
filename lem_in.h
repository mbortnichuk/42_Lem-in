/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:52:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/26 18:52:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

/*
** Structure definition
*/
typedef struct s_room		t_room;
typedef struct s_linkroom	t_linkroom;
typedef struct s_info		t_info;

struct	s_room
{
	char		*name;
	int			r_weight;
	t_linkroom	*link;
	t_room		*next;
};

struct	s_linkroom
{
	t_room		*room;
	t_linkroom	*next;
};

struct	s_info
{
	int		w_max;
	int		weight;
	int		ant_nbr;
	int		room_nbr;
	char	*str;
	char	*start;
	char	*end;
};

int		ft_strisdigit(char *str);
void	ft_initiation(t_info *info);
void	ft_err();
void	ft_valid_map(t_info *info);
void	ft_print_way(t_info *info, char **way);
void	ft_ants_nbr(t_info *info);
t_room	*ft_find_room(t_room *room, char *str);
t_room	*ft_add_new_room(int i, t_room *room, t_info *info);
t_room	*ft_add_new_link(char *src, char *dest, t_room *room);
t_room	*ft_parse_pipe(t_room *room, t_info *info);
t_room	*ft_parse_map(t_room *room, t_info *info);
t_room	*ft_first_move(t_room *room, t_info *info);
t_room	*ft_set_endweight(t_room *room, t_info *info);
t_room	*ft_set_unlroom(t_info *info, t_room *room);

#endif
