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

struct					s_info
{
	int			ok[2];
	int			in2;
	int			st_point;
	int			current_r;
	int			path_index;
	int			rooms_amount;
	int			ants_amount;
	char		*room_list;
	char		*ant_list;
	char		*link_list;
	int			*way;
	char		**rooms;
	int			**table;
};

/*
** ft_addrooms.c
*/

void					ft_addrooms(t_info *info);
int						ft_lastroom(int i, t_info *info);
void					ft_rooms(char *str, t_info *info);
void					ft_valid_link(char *connection, t_info *info);
void					ft_links(char *str, t_info *info);

/*
** ft_freeandexit.c
*/

void					ft_freeandexit(int err, t_info *info);
void					ft_free_arr(int err, char **arr, t_info *info);
void					ft_delete_el(int i, int way, t_info *info);

/*
** ft_init_edgetable.c
*/

void					ft_create_edgetable(t_info *info);
t_info					*ft_init_edgetable(t_info *info);
void					ft_read_edgetable(t_info *info);

/*
** ft_pathfinder.c
*/

void					ft_ants_amount(char *str, t_info *info);
int						ft_find_way(int roomid, int doorid, t_info *info);
int						ft_ontheway(int roomid, t_info *info);
int						ft_pathfinder(int i, t_info *info);

/*
** ft_print.c
*/

void					ft_print_res(int i, t_info *info);
void					ft_print_ant(char *r, int a);
void					ft_res(t_info *info);

/*
** ft_support_func.c
*/

t_info					*ft_initiation(void);
int						ft_empty(char *str);
char					*ft_join(int blank, char *str1, char *str2);
void					ft_is_number(t_info *info, char **room, char *str);

/*
** ft_validate.c
*/

void					ft_check_st_end(int theend, char **room, t_info *info);
int						ft_roomid(int st, char *r_name, t_info *info);
void					ft_isvalid(int i, char **room, t_info *info);
void					ft_isgood(int theend, t_info *info, char **str, \
									char **room);
void					ft_valid_room(char *str, t_info *info);

#endif
