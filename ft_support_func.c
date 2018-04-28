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

int		ft_empty(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

char	*ft_join(char *s1, char *s2, int clean)
{
	char *new_s;

	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0] == 0)
		return (s2);
	ft_strcat(new_s, s1);
	ft_strcat(new_s, "\n");
	ft_strcat(new_s, s2);
	ft_strdel(&s1);
	(clean) ? ft_strdel(&s2) : 0;
	return (new_s);
}

void	ft_is_number(char **r, t_info *info, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				ft_free_arr(r, info, 1);
		}
	}
	else
		ft_free_arr(r, info, 1);
}
