/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeandexit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:20:56 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 17:20:57 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_freeandexit(int err, t_info *info)
{
	int i;

	free(info->link_list);
	free(info->ant_list);
	free(info->room_list);
	if (info->in2)
	{
		free(info->way);
		ft_free_arr(0, info->rooms, info);
		i = 0;
		while (i < info->rooms_amount)
		{
			free(info->table[i]);
			i++;
		}
		free(info->table);
	}
	free(info);
	if (err)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void	ft_free_arr(int err, char **arr, t_info *info)
{
	int i;

	i = 0;
	while (arr[i])
		(arr[i]) ? free(arr[i++]) : 0;
	free(arr);
	if (err)
		ft_freeandexit(1, info);
	arr = NULL;
}

void	ft_delete_el(int i, int way, t_info *info)
{
	info->table[info->current_r][i] = 0;
	info->table[i][info->current_r] = 0;
	if (way)
	{
		info->way[info->path_index] = -1;
		info->path_index--;
	}
}
