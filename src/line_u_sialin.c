/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_u_sialin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:30:34 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/15 20:43:54 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_choose_color(t_gener *str, int diff)
{
	if (str->z >= str->min && str->z <= str->min + diff / 10)
		str->color = mlx_get_color_value(str->mlx_ptr, 0x81b8e1);
	else if (str->z >= str->min + diff / 10 && str->z < str->min + diff / 5)
		str->color = mlx_get_color_value(str->mlx_ptr, 0x94c8ef);
	else if (str->z >= str->min + diff / 5 &&
		str->z < str->min + 5 * diff / 10)
		str->color = mlx_get_color_value(str->mlx_ptr, 0xd8f3fe);
	else if (str->z >= str->min + 5 * diff / 10 &&
		str->z < str->min + 6 * diff / 10)
		str->color = mlx_get_color_value(str->mlx_ptr, 0xc0dbba);
	else if (str->z >= str->min + 6 * diff / 10 &&
		str->z < str->min + 7 * diff / 10)
		str->color = mlx_get_color_value(str->mlx_ptr, 0xacd3a6);
	else if (str->z >= str->min + 7 * diff / 10 &&
		str->z < str->min + 8 * diff / 10)
		str->color = mlx_get_color_value(str->mlx_ptr, 0xf6f2c3);
	else if (str->z >= str->min + 8 * diff / 10 &&
		str->z < str->min + 9 * diff / 10)
		str->color = mlx_get_color_value(str->mlx_ptr, 0xd3c692);
	else if (str->z >= str->min + 9 * diff / 10 &&
		str->z <= str->min + 10 * diff / 10)
		str->color = mlx_get_color_value(str->mlx_ptr, 0x806133);
}

void	ft_add_point(t_gener *str, int x, int y)
{
	int diff;

	diff = str->max - str->min;
	if (x >= 0 && y >= 0 && x < 1200 && y < 800)
	{
		ft_choose_color(str, diff);
		*(unsigned int *)(str->pixl + x * (str->bpp / 8) +
			(y * str->size_line)) = str->color;
		str->pixl[x * (str->bpp / 8) + 3 + y * str->size_line] = str->t;
	}
}

void	draw_lines_wu(t_cord **struct_xy, t_gener *str)
{
	t_line l;

	l.x = 0;
	l.y = 0;
	while (l.y < str->count_y)
	{
		while (l.x < str->count_x - 1)
		{
			l.x0 = struct_xy[l.y][l.x].x;
			l.x1 = struct_xy[l.y][l.x + 1].x;
			l.y0 = struct_xy[l.y][l.x].y;
			l.y1 = struct_xy[l.y][l.x + 1].y;
			if (struct_xy[l.y][l.x].z_b == 0)
				str->z = struct_xy[l.y][l.x + 1].z_b;
			else
				str->z = struct_xy[l.y][l.x].z_b;
			if (!struct_xy[l.y][l.x].no_ex && !struct_xy[l.y][l.x + 1].no_ex
				&& l.x0 < 1400 && l.x1 >= -100
				&& l.y0 < 1000 && l.y1 >= -100)
				ft_draw_line(str, l);
			l.x++;
		}
		l.x = 0;
		l.y++;
	}
}

void	draw_lines_wu_upright(t_cord **struct_xy, t_gener *str)
{
	t_line l;

	l.x = 0;
	l.y = 0;
	while (l.y < str->count_y - 1)
	{
		while (l.x < str->count_x)
		{
			l.x0 = struct_xy[l.y][l.x].x;
			l.x1 = struct_xy[l.y + 1][l.x].x;
			l.y0 = struct_xy[l.y][l.x].y;
			l.y1 = struct_xy[l.y + 1][l.x].y;
			if (struct_xy[l.y][l.x].z_b == 0)
				str->z = struct_xy[l.y + 1][l.x].z_b;
			else
				str->z = struct_xy[l.y][l.x].z_b;
			if (!struct_xy[l.y][l.x].no_ex && !struct_xy[l.y + 1][l.x].no_ex
				&& l.x0 < 1400 && l.x1 >= -100
				&& l.y0 < 1000 && l.y1 >= -100)
				ft_draw_line(str, l);
			l.x++;
		}
		l.x = 0;
		l.y++;
	}
}

void	draw_line_hor(t_gener *str, t_line line)
{
	if (line.x1 == line.x0)
	{
		if (line.y1 < line.y0)
			while (line.y1 < line.y0)
				ft_add_point(str, line.x1, line.y1++);
		else if (line.y1 > line.y0)
			while (line.y1 > line.y0)
				ft_add_point(str, line.x1, line.y1--);
	}
	else if (line.y1 == line.y0)
	{
		if (line.x1 < line.x0)
			while (line.x1 < line.x0)
				ft_add_point(str, line.x1++, line.y1);
		else if (line.x1 > line.x0)
			while (line.x1 > line.x0)
				ft_add_point(str, line.x1--, line.y1);
	}
}
