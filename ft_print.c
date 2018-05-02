/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:27:37 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 18:27:38 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_res(int i, t_info *info)
{
	int ants;

	if (i == (info->path_index + info->ants_amount + 1))
		return ;
	ants = info->ants_amount + 1;
	while (--ants > 0)
	{
		if (i - ants > 0 && (i - ants) <= info->path_index)
			ft_print_ant(info->rooms[info->way[i - ants]], ants);
	}
	write(1, "\n", 1);
	ft_print_res(++i, info);
}

void	ft_print_ant(char *r, int a)
{
	write(1, "L", 1);
	ft_putnbr(a);
	write(1, "-", 1);
	ft_putstr(r);
	write(1, " ", 1);
}

void	ft_res(t_info *info)
{
	int i;

	i = -1;
	ft_putendl(info->ant_list);
	ft_putendl(info->room_list);
	ft_putendl(info->link_list);
	write(1, "\n", 1);
	ft_print_res(2, info);
}
