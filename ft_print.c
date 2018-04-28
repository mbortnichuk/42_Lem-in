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

void	ft_print_res(t_info *info, int n)
{
	int ants;

	if (n == (info->path_index + info->ants_amount + 1))
		return ;
	ants = info->ants_amount + 1;
	while (--ants > 0)
	{
		if (n - ants > 0 && (n - ants) <= info->path_index)
			ft_print_ant(ants, info->rooms[info->way[n - ants]]);
	}
	ft_putchar('\n');
	ft_print_res(info, ++n);
}

void	ft_print_ant(int ant, char *room)
{
	write(1, "L", 1);
	ft_putnbr(ant);
	write(1, "-", 1);
	ft_putstr(room);
	write(1, " ", 1);
}

void		ft_res(t_info *info)
{
	int i;

	i = -1;
	ft_putendl(info->ant_list);
	ft_putendl(info->room_list);
	ft_putendl(info->link_list);
	write(1, "\n", 1);
	ft_print_res(info, 2);
}
