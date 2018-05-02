/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:31:14 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 18:31:17 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_check_st_end(int theend, char **room, t_info *info)
{
	if (theend)
	{
		info->rooms[info->rooms_amount - 1] = ft_strdup(room[0]);
		(info->ok[1])++;
		return ;
	}
	info->rooms[0] = ft_strdup(room[0]);
	(info->ok[0])++;
}

int		ft_roomid(int st, char *r_name, t_info *info)
{
	int index;

	index = (st) ? -1 : 0;
	while (info->rooms[++index] && index < info->rooms_amount)
	{
		if (ft_strcmp(info->rooms[index], r_name) == 0)
			return (index);
	}
	return (index);
}

void	ft_isvalid(int i, char **room, t_info *info)
{
	int roomid;

	roomid = ft_roomid(0, room[0], info);
	if (roomid > 0 && i != roomid)
		ft_freeandexit(1, info);
	info->rooms[i] = ft_strdup(room[0]);
}

void	ft_isgood(int theend, t_info *info, char **str, char **room)
{
	if (++(info->ok[theend]) > 1)
	{
		ft_free_arr(0, room, info);
		ft_free_arr(1, str, info);
	}
}

void	ft_valid_room(char *str, t_info *info)
{
	char **room;

	room = ft_strsplit(str, ' ');
	if (room[0][0] == 'L' || room[3] != NULL)
		ft_free_arr(1, room, info);
	ft_is_number(info, room, room[1]);
	ft_is_number(info, room, room[2]);
	ft_free_arr(0, room, info);
}
