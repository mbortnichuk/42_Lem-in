/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_edgetable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:07:42 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 17:07:43 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_create_edgetable(t_info *info)
{
	int		i;
	int		r_1;
	int		r_2;
	char	**l;
	char	**links;

	i = -1;
	links = ft_strsplit(info->link_list, '\n');
	while (links[++i])
	{
		if (links[i][0] == '#')
			continue ;
		ft_valid_link(info, links[i]);
		l = ft_strsplit(links[i], '-');
		if ((r_1 = ft_roomid(info, l[0], 1)) >= info->rooms_amount ||
			(r_2 = ft_roomid(info, l[1], 1)) >= info->rooms_amount)
		{
			ft_free_arr(l, info, 0);
			ft_free_arr(links, info, 1);
		}
		(r_2) ? (info->table[r_1][r_2] = 1) : 0;
		(r_1) ? (info->table[r_2][r_1] = 1) : 0;
		ft_free_arr(l, info, 0);
	}
	ft_free_arr(links, info, 0);
}

t_info	*ft_init_edgetable(t_info *info)
{
	int i;
	int j;

	i = -1;
	info->in2 = 1;
	info->way = (int*)ft_memalloc(sizeof(int) * 1000);
	info->table = (int**)ft_memalloc(sizeof(int*) * info->rooms_amount);
	info->rooms = (char**)ft_memalloc(sizeof(char*) * (info->rooms_amount + 1));
	while (++i < info->rooms_amount)
	{
		info->way[i] = -1;
		info->rooms[i] = NULL;
		info->table[i] = (int*)ft_memalloc(sizeof(int) * info->rooms_amount);
		j = -1;
		while (info->table[i][++j])
			info->table[i][j] = 0;
	}
	info->rooms[i] = NULL;
	info->way[0] = 0;
	return (info);
}

void		ft_read_edgetable(t_info *info)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (info->ants_amount == 0)
			ft_ants_amount(info, line);
		else if (ft_strchr(line, '-') || info->st_point == 3)
			ft_links(info, line);
		else if ((info->st_point == 1 || info->st_point == 2) && !ft_empty(line))
			ft_rooms(info, line);
		else
			ft_freeandexit(info, 1);
	}
	if (!info->ants_amount || !info->link_list[0])
		ft_freeandexit(info, 1);
	info = ft_init_edgetable(info);
}
