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

void	ft_check_st_end(t_info *info, char **r, int end)
{
	if (end)
	{
		info->rooms[info->rooms_amount - 1] = ft_strdup(r[0]);
		(info->ok[1])++;
		return ;
	}
	info->rooms[0] = ft_strdup(r[0]);
	(info->ok[0])++;
}

int	ft_roomid(t_info *info, char *room_name, int start)
{
	int index;

	index = (start) ? -1 : 0;
	while (info->rooms[++index] && index < info->rooms_amount)
	{
		if (ft_strcmp(info->rooms[index], room_name) == 0)
			return (index);
	}
	return (index);
}

void	ft_isvalid(t_info *info, int i, char **r)
{
	int r_index;

	r_index = ft_roomid(info, r[0], 0);
	if (r_index > 0 && i != r_index)
		ft_freeandexit(info, 1);
	info->rooms[i] = ft_strdup(r[0]);
}

void	ft_isgood(t_info *info, char **line, char **r, int end)
{
	if (++(info->ok[end]) > 1)
	{
		ft_free_arr(r, info, 0);
		ft_free_arr(line, info, 1);
	}
}

void	ft_valid_room(t_info *info, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		ft_free_arr(r, info, 1);
	ft_is_number(r, info, r[1]);
	ft_is_number(r, info, r[2]);
	ft_free_arr(r, info, 0);
}
