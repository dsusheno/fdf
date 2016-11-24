/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:05:42 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/15 20:41:11 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_malloc_struct2(t_cord **struct_xy, t_gener *str, t_map st)
{
	if (str->tab_z[st.y][st.x])
	{
		struct_xy[st.y][st.x].z = ft_getnbr(str->tab_z[st.y][st.x]);
		ft_min_max(struct_xy[st.y][st.x].z, str);
		struct_xy[st.y][st.x].z_b = struct_xy[st.y][st.x].z;
		struct_xy[st.y][st.x].z /= 3;
		struct_xy[st.y][st.x].no_ex = 0;
	}
	else
		struct_xy[st.y][st.x].no_ex = 1;
	struct_xy[st.y][st.x].x = st.x;
	struct_xy[st.y][st.x].y = st.y;
}

t_cord		**ft_malloc_struct(t_gener *str)
{
	t_map		st;
	t_cord		**struct_xy;

	st.x = 0;
	st.y = 0;
	struct_xy = malloc(sizeof(t_cord *) * str->count_y);
	while (st.y < str->count_y)
	{
		struct_xy[st.y] = malloc(sizeof(t_cord) * str->count_x);
		while (st.x < str->count_x)
		{
			ft_malloc_struct2(struct_xy, str, st);
			st.x++;
		}
		st.x = 0;
		st.y++;
	}
	return (struct_xy);
}

void		ft_map_init_begin(t_gener *str)
{
	str->dep_x = 100;
	str->dep_y = 400;
	str->dep_mp = 1;
	str->a = 0;
	str->b = 0;
	str->s = 0;
	str->zp = 1;
}

float		f_part(float x)
{
	while (x >= 0)
		x--;
	x++;
	return (x);
}
