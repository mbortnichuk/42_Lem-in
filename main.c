/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:01:28 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 17:01:30 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_info *info;

	info = ft_initiation();
	ft_read_edgetable(info);
	ft_addrooms(info);
	if (!info->ok[0] || !info->ok[1])
		ft_freeandexit(info, 1);
	ft_create_edgetable(info);
	if (ft_pathfinder(info, 0))
		ft_res(info);
	else
		ft_freeandexit(info, 1);
	ft_freeandexit(info, 0);
}
