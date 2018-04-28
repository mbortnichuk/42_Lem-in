/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:35:51 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 18:35:53 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"

typedef struct s_info	t_info;

struct 					s_info
{
	char		**rooms;		// array of room names
	char		*room_list;	// list of rooms that was passed at the beginning
	char		*ant_list;		// list of ants that was passed at the beginning
	char		*link_list;			// list of links that was passed at the beginning
	int			rooms_amount;		// quantity of rooms
	int			ants_amount;			// quantity of ants
	int			st_point;		// a part of validation
	int			current_r;		// an index of current room we're in
	int			path_index;			// last path index, current size of path
	int			*way;			// path
	int			**table;			// edge table
	int			ok[2];		// a part of validation
	int			in2;			// a part of validation
};

/*
** ft_addrooms.c
*/

void		ft_addrooms(t_info *info);
int	ft_lastroom(t_info *info, int i);
void		ft_rooms(t_info *info, char *line);
void	ft_valid_link(t_info *info, char *link);
void	ft_links(t_info *info, char *line);

/*
** ft_freeandexit.c
*/

void	ft_freeandexit(t_info *info, int error);
void	ft_free_arr(char **array, t_info *info, int error);
void	ft_delete_el(t_info *info, int i, int path);

/*
** ft_init_edgetable.c
*/

void		ft_create_edgetable(t_info *info);
t_info	*ft_init_edgetable(t_info *info);
void		ft_read_edgetable(t_info *info);

/*
** ft_pathfinder.c
*/

void	ft_ants_amount(t_info *info, char *line);
int	ft_find_way(t_info *info, int r_index, int d_index);
int	ft_ontheway(t_info *info, int r_index);
int			ft_pathfinder(t_info *info, int i);

/*
** ft_print.c
*/

void	ft_print_res(t_info *info, int n);
void	ft_print_ant(int ant, char *room);
void		ft_res(t_info *info);

/*
** ft_support_func.c
*/

t_info	*ft_initiation(void);
int		ft_empty(char *s);
char	*ft_join(char *s1, char *s2, int clean);
void	ft_is_number(char **r, t_info *info, char *s);

/*
** ft_validate.c
*/

void	ft_check_st_end(t_info *info, char **r, int end);
int	ft_roomid(t_info *info, char *room_name, int start);
void	ft_isvalid(t_info *info, int i, char **r);
void	ft_isgood(t_info *info, char **line, char **r, int end);
void	ft_valid_room(t_info *info, char *line);

#endif
