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

void	ft_freeandexit(t_info *info, int error)
{
	int i;

	free(info->link_list);
	free(info->ant_list);
	free(info->room_list);
	if (info->in2)
	{
		free(info->way);
		ft_free_arr(info->rooms, info, 0);
		i = -1;
		while (++i < info->rooms_amount)
			free(info->table[i]);
		free(info->table);
	}
	free(info);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void	ft_free_arr(char **array, t_info *info, int error)
{
	int i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	if (error)
		ft_freeandexit(info, 1);
	array = NULL;
}

void	ft_delete_el(t_info *info, int i, int path)
{
	info->table[info->current_r][i] = 0;
	info->table[i][info->current_r] = 0;
	if (path)
	{
		info->way[info->path_index] = -1;
		info->path_index--;
	}
}
