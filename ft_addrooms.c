/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:15:09 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 17:15:10 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_addrooms(t_info *info)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = -1;
	j = 1;
	line = ft_strsplit(info->room_list, '\n');
	while (line[++i] && j < info->rooms_amount)
	{
		r = ft_strsplit(line[i], ' ');
		if (!ft_strcmp("##start", line[i]))
			ft_isgood(info, line, r, 0);
		else if (!ft_strcmp("##end", line[i]))
			ft_isgood(info, line, r, 1);
		else if (info->ok[0] == 1 && line[i][0] != '#')
			ft_check_st_end(info, r, 0);
		else if (info->ok[1] == 1 && line[i][0] != '#')
			ft_check_st_end(info, r, 1);
		else if (line[i][0] != '#')
			ft_isvalid(info, j++, r);
		ft_free_arr(r, info, 0);
	}
	ft_free_arr(line, info, 0);
}

int	ft_lastroom(t_info *info, int i)
{
	if (info->table[i][info->rooms_amount - 1])
	{
		info->way[++(info->path_index)] = i;
		info->way[++(info->path_index)] = info->rooms_amount - 1;
		return (1);
	}
	return (0);
}

void		ft_rooms(t_info *info, char *line)
{
	info->st_point = 2;
	info->room_list = ft_join(info->room_list, line, 0);
	if (line[0] == '#')
		return ;
	ft_valid_room(info, line);
	info->rooms_amount++;
}

void	ft_valid_link(t_info *info, char *link)
{
	char **l;

	l = ft_strsplit(link, '-');
	if (l[2] != NULL)
		ft_free_arr(l, info, 1);
	ft_free_arr(l, info, 0);
}

void	ft_links(t_info *info, char *line)
{
	if (info->st_point == 2)
		info->st_point = 3;
	if (info->st_point != 3)
		ft_freeandexit(info, 1);
	info->link_list = ft_join(info->link_list, line, 0);
}
