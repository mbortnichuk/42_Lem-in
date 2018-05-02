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

void	ft_addrooms(t_info *info)
{
	int		i;
	int		j;
	char	**str;
	char	**r;

	i = -1;
	j = 1;
	str = ft_strsplit(info->room_list, '\n');
	while (str[++i] && j < info->rooms_amount)
	{
		r = ft_strsplit(str[i], ' ');
		if (!ft_strcmp("##start", str[i]))
			ft_isgood(0, info, str, r);
		else if (!ft_strcmp("##end", str[i]))
			ft_isgood(1, info, str, r);
		else if (info->ok[0] == 1 && str[i][0] != '#')
			ft_check_st_end(0, r, info);
		else if (info->ok[1] == 1 && str[i][0] != '#')
			ft_check_st_end(1, r, info);
		else if (str[i][0] != '#')
			ft_isvalid(j++, r, info);
		ft_free_arr(0, r, info);
	}
	ft_free_arr(0, str, info);
}

int		ft_lastroom(int i, t_info *info)
{
	if (info->table[i][info->rooms_amount - 1])
	{
		info->way[++(info->path_index)] = i;
		info->way[++(info->path_index)] = info->rooms_amount - 1;
		return (1);
	}
	return (0);
}

void	ft_rooms(char *str, t_info *info)
{
	info->st_point = 2;
	info->room_list = ft_join(0, info->room_list, str);
	if (str[0] == '#')
		return ;
	ft_valid_room(str, info);
	info->rooms_amount++;
}

void	ft_valid_link(char *connection, t_info *info)
{
	char **link;

	link = ft_strsplit(connection, '-');
	if (link[2] != NULL)
		ft_free_arr(1, link, info);
	ft_free_arr(0, link, info);
}

void	ft_links(char *str, t_info *info)
{
	if (info->st_point == 2)
		info->st_point = 3;
	if (info->st_point != 3)
		ft_freeandexit(1, info);
	info->link_list = ft_join(0, info->link_list, str);
}
