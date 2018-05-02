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

void	ft_create_edgetable(t_info *info)
{
	int		i;
	int		crd1;
	int		crd2;
	char	**l;
	char	**link_arr;

	i = -1;
	link_arr = ft_strsplit(info->link_list, '\n');
	while (link_arr[++i])
	{
		if (link_arr[i][0] == '#')
			continue ;
		ft_valid_link(link_arr[i], info);
		l = ft_strsplit(link_arr[i], '-');
		if ((crd1 = ft_roomid(1, l[0], info)) >= info->rooms_amount ||
			(crd2 = ft_roomid(1, l[1], info)) >= info->rooms_amount)
		{
			ft_free_arr(0, l, info);
			ft_free_arr(1, link_arr, info);
		}
		(crd2) ? (info->table[crd1][crd2] = 1) : 0;
		(crd1) ? (info->table[crd2][crd1] = 1) : 0;
		ft_free_arr(0, l, info);
	}
	ft_free_arr(0, link_arr, info);
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

void	ft_read_edgetable(t_info *info)
{
	char *str;

	while (get_next_line(0, &str) > 0)
	{
		if (info->ants_amount == 0)
			ft_ants_amount(str, info);
		else if (ft_strchr(str, '-') || info->st_point == 3)
			ft_links(str, info);
		else if ((info->st_point == 1 || info->st_point == 2) && !ft_empty(str))
			ft_rooms(str, info);
		else
			ft_freeandexit(1, info);
	}
	if (!info->ants_amount || !info->link_list[0])
		ft_freeandexit(1, info);
	info = ft_init_edgetable(info);
}
