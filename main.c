/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:04:23 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/26 19:04:27 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_strisdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i])) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_initiation(t_info *info)
{
	info->ant_nbr = 0;
	info->weight = 0;
	info->w_max = 0;
	info->start = NULL;
	info->end = NULL;
}





void	ft_err()
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}





void	ft_valid_map(t_info *info)
{
	if (info->start == NULL || info->end == NULL)
		ft_err();
}







void	ft_print_way(t_info *info, char **way)
{
	int		room;
	int		ant;

	ant = 0;
	write(1, "\n", 1);
	while (++ant <= info->ant_nbr)
	{
		room = 0;
		while (way[room])
		{
			ft_putstr(ft_strjoin("L", ft_itoa(ant)));
			ft_putendl(ft_strjoin("-", way[room++]));
		}
	}
}







void	ft_ants_nbr(t_info *info)
{
	if (get_next_line(0, &info->str) < 1)
		ft_err();
	if (!ft_strisdigit(info->str))
		ft_err();
	if ((info->ant_nbr = ft_atoi(info->str)) < 1)
		ft_err();
	ft_putendl(info->str);
	free(info->str);
}





t_room	*ft_find_room(t_room *room, char *str)
{
	t_room	*temp;

	temp = room;
	while (temp)
	{
		if (!ft_strcmp(temp->name, str))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}




t_room	*ft_add_new_room(int i, t_room *room, t_info *info)
{
	t_room	*new;
	t_room	*temp;

	if (!(new = ft_memalloc(sizeof(t_room))))
		ft_err();
	info->room_nbr++;
	new->name = ft_strndup(info->str, i);
	new->link = NULL;
	new->next = NULL;
	new->r_weight = 0;
	if (!room)
		return (new);
	else
	{
		temp = room;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		return (new);
	}
}

t_room	*ft_add_new_link(char *src, char *dest, t_room *room)
{
	t_room	*temp1;
	t_room	*temp2;
	t_linkroom	*new;
	t_linkroom	*new_tmp;

	if (!(new = ft_memalloc(sizeof(t_room))))
		ft_err();
	if (!(temp1 = ft_find_room(room, dest)) || !ft_strcmp(src, dest))
		ft_err();
	if (!(temp1 = ft_find_room(room, src)))
		ft_err();
	new->room = temp2;
	new->next = NULL;
	if (!temp1->link)
		temp1->link = new;
	else
	{
		new_tmp = temp1->link;
		while (new_tmp->next)
			new_tmp = new_tmp->next;
		new_tmp = new;
	}
	return (room);
}





t_room	*ft_parse_pipe(t_room *room, t_info *info)
{
	char	**pipe;

	if (info->str)
		room = ft_first_move(room, info);
	while (get_next_line(0, &info->str) > 0)
	{
		if (!ft_strchr(info->str, '-') && info->str[0] != '#')
			break ;
		if (info->str[0] != '#')
		{
			pipe = ft_strsplit(info->str, '-');
			room = ft_add_new_link(pipe[0], pipe[1], room);
			room = ft_add_new_link(pipe[1], pipe[0], room);
			free(pipe[0]);
			free(pipe[1]);
			free(pipe);
		}
		ft_putendl(info->str);
		free(info->str);
	}
	return (room);
}

t_room	*ft_parse_map(t_room *room, t_info *info)
{
	int stat;
	int i;

	while (get_next_line(0, &info->str) > 0)
	{
		if (!ft_strchr(info->str, ' ') && info->str[0] != '#')
			break ;
		if (!ft_strcmp(info->str, "##start"))
			stat = 1;
		if (!ft_strcmp(info->str, "##end"))
			stat = 2;
		if (info->str[0] != '#')
		{
			i = ft_strchr(info->str, ' ') - info->str;
			room = ft_add_new_room(i, room, info);
			if (stat == 1)
				info->start = ft_strndup(info->str, i);
			if (stat == 2)
				info->end = ft_strndup(info->str, i);
			stat = 0;
		}
		ft_putendl(info->str);
		free(info->str);
	}
	return (room);
}









t_room	*ft_first_move(t_room *room, t_info *info)
{
	char	**p;

	if (!ft_strchr(info->str, '-') && info->str[0] != '#')
		ft_err();
	if (info->str[0] != '#')
	{
		p = ft_strsplit(info->str, '-');
		room = ft_add_new_link(p[0], p[1], room);
		room = ft_add_new_link(p[1], p[0], room);
		free(p[0]);
		free(p[1]);
		free(p);
	}
	ft_putendl(info->str);
	free(info->str);
	return (room);
}

















t_room	*ft_set_unlroom(t_info *info, t_room *room)
{
	t_room	*temp;

	temp = room;
	if (info->w_max >= info->room_nbr + 10)
		ft_err();
	while (temp)
	{
		if (temp->r_weight == 0)
			info->weight++;
		if (temp->r_weight == -1 || temp->r_weight == 0)
			temp->r_weight = info->w_max + 1;
		temp = temp->next;
	}
	return (room);
}

t_room	*ft_set_endweight(t_room *room, t_info *info)
{
	t_linkroom	*t2;
	t_room		*t1;

	t1 = room;
	t2 = room->link;
	while (ft_strcmp(t1->name, info->end))
		t1 = t1->next;
	if (!t1->link)
		ft_err();
	info->weight = 1;
	t1->r_weight = 1;
	info->w_max = 1;
	return (room);
}





#include <stdio.h>
int main(void)
{
	char	**way;
	t_room	*room;
	t_info	info;

	room = NULL;
	way = NULL;
	ft_initiation(&info);
	ft_ants_nbr(&info);
	room = ft_parse_map(room, &info);
	room = ft_parse_pipe(room, &info);
	ft_valid_map(&info);
	// room = ft_set_weight(room, &info);
	// way = ft_find_way(room, &info);
	// ft_print_way(&info, way);
	return (0);
}