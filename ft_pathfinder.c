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

void	ft_ants_amount(t_info *info, char *line)
{
	int		i;
	char	*s;

	i = 0;
	info->st_point = 1;
	info->ant_list = ft_join(info->ant_list, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((info->ants_amount = ft_atoi(s)) <= 0)
		ft_freeandexit(info, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
			ft_freeandexit(info, 1);
	}
}

int	ft_find_way(t_info *info, int r_index, int d_index)
{
	while (d_index < info->rooms_amount)
	{
		if (info->table[r_index][++d_index] == 1)
			return (d_index);
	}
	return (0);
}

int	ft_ontheway(t_info *info, int r_index)
{
	int i;

	i = -1;
	while (info->way[++i] != -1)
	{
		if (info->way[i] == r_index)
			return (1);
	}
	return (0);
}

int			ft_pathfinder(t_info *info, int i)
{
	if (info->table[0][info->rooms_amount - 1])
	{
		info->way[++(info->path_index)] = info->rooms_amount - 1;
		return (1);
	}
	while ((i = ft_find_way(info, info->current_r, i)))
	{
		if (ft_lastroom(info, i))
			return (1);
		else if (ft_ontheway(info, i))
			ft_delete_el(info, i, 0);
	}
	if ((info->current_r = ft_find_way(info, info->current_r, 0)) == 0)
	{
		if (info->path_index == 0 || info->current_r == 0)
			return (0);
		info->current_r = info->way[info->path_index - 1];
		ft_delete_el(info, info->way[info->path_index], 1);
		if (ft_pathfinder(info, 0))
			return (1);
	}
	info->way[++(info->path_index)] = info->current_r;
	if (ft_pathfinder(info, 0))
		return (1);
	return (0);
}
