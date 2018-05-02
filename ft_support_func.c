/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:05:35 by mbortnic          #+#    #+#             */
/*   Updated: 2018/04/28 17:05:36 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_info	*ft_initiation(void)
{
	t_info *info;

	info = (t_info*)ft_memalloc(sizeof(t_info));
	info->link_list = ft_strnew(1);
	info->ant_list = ft_strnew(1);
	info->room_list = ft_strnew(1);
	info->rooms_amount = 0;
	info->ants_amount = 0;
	info->st_point = 0;
	info->current_r = 0;
	info->path_index = 0;
	info->in2 = 0;
	info->ok[0] = 0;
	info->ok[1] = 0;
	info->rooms = NULL;
	info->table = NULL;
	info->way = NULL;
	return (info);
}

int		ft_empty(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

char	*ft_join(int blank, char *str1, char *str2)
{
	char *fresh;

	fresh = ft_strnew(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (str1[0] == 0)
		return (str2);
	ft_strcat(fresh, str1);
	ft_strcat(fresh, "\n");
	ft_strcat(fresh, str2);
	ft_strdel(&str1);
	(blank) ? ft_strdel(&str2) : 0;
	return (fresh);
}

void	ft_is_number(t_info *info, char **room, char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || (str[0] >= '0' && str[0] <= '9'))
	{
		while (str[++i])
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				ft_free_arr(1, room, info);
		}
	}
	else
		ft_free_arr(1, room, info);
}
