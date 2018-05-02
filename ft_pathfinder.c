/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:22:55 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 18:22:56 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_ants_amount(char *str, t_info *info)
{
	int		i;
	char	*line;

	i = 0;
	info->st_point = 1;
	info->ant_list = ft_join(0, info->ant_list, str);
	if (str[0] == '#')
		return ;
	line = ft_strtrim(str);
	if ((info->ants_amount = ft_atoi(line)) <= 0)
		ft_freeandexit(1, info);
	while (line[i] != '\n' && line[i] != 0)
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			ft_freeandexit(1, info);
		i++;
	}
}

int		ft_find_way(int roomid, int doorid, t_info *info)
{
	while (doorid < info->rooms_amount)
	{
		if (info->table[roomid][++doorid] == 1)
			return (doorid);
	}
	return (0);
}

int		ft_ontheway(int roomid, t_info *info)
{
	int i;

	i = 0;
	while (info->way[i] != -1)
	{
		if (info->way[i] == roomid)
			return (1);
		i++;
	}
	return (0);
}

int		ft_pathfinder(int i, t_info *info)
{
	if (info->table[0][info->rooms_amount - 1])
	{
		info->way[++(info->path_index)] = info->rooms_amount - 1;
		return (1);
	}
	while ((i = ft_find_way(info->current_r, i, info)))
	{
		if (ft_lastroom(i, info))
			return (1);
		else if (ft_ontheway(i, info))
			ft_delete_el(i, 0, info);
	}
	if ((info->current_r = ft_find_way(info->current_r, 0, info)) == 0)
	{
		if (info->path_index == 0 || info->current_r == 0)
			return (0);
		info->current_r = info->way[info->path_index - 1];
		ft_delete_el(info->way[info->path_index], 1, info);
		if (ft_pathfinder(0, info))
			return (1);
	}
	info->way[++(info->path_index)] = info->current_r;
	if (ft_pathfinder(0, info))
		return (1);
	return (0);
}
