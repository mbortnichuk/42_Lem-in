/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:52:39 by mbortnic          #+#    #+#             */
/*   Updated: 2018/03/26 18:52:40 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

/*
** Structure definition
*/
typedef struct s_room		t_room;
typedef struct s_linkroom	t_linkroom;
typedef struct s_info		t_info;

struct	s_room
{
	char		*name;
	int			r_weight;
	t_linkroom	*link;
	t_room		*next;
};

struct	s_linkroom
{
	t_room		*room;
	t_linkroom	*next;
};

struct	s_info
{
	int		w_max;
	int		weight;
	int		ant_nbr;
	int		room_nbr;
	char	*str;
	char	*start;
	char	*end;
};

#endif
