/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:04:15 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/15 19:05:57 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	main2(t_gener *s, t_cord **struct_xy, t_cord **struct_xy2)
{
	s->img_ptr = mlx_new_image(s->mlx_ptr, 1200, 800);
	s->pixl = mlx_get_data_addr(s->img_ptr, &s->bpp, &s->size_line, &s->endian);
	struct_xy = ft_malloc_struct(s);
	struct_xy2 = ft_malloc_struct(s);
	s->struct_xy = struct_xy;
	s->struct_xy2 = struct_xy2;
	ft_map_action(s, struct_xy, struct_xy2);
	draw_lines_wu(struct_xy2, s);
	draw_lines_wu_upright(struct_xy2, s);
	ft_text_put(s);
}

int		main(int argc, char **argv)
{
	t_gener		s;
	t_cord		**struct_xy;
	t_cord		**struct_xy2;

	struct_xy = NULL;
	struct_xy2 = NULL;
	if (argc != 2)
	{
		ft_putstrn("fdf: you need to enter just one argument");
		return (0);
	}
	ft_str_init(&s);
	ft_count_n(argv[1], &s);
	s.tab_z = read_file(argv[1], s.count_y);
	if (!(s.mlx_ptr = mlx_init()) ||
		!(s.win_ptr = mlx_new_window(s.mlx_ptr, 1600, 800, "fdf")))
		return (0);
	main2(&s, struct_xy, struct_xy2);
	mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, s.img_ptr, 400, 0);
	mlx_hook(s.win_ptr, 2, (1L << 0), my_key_fonction, &s);
	mlx_loop(s.mlx_ptr);
	return (0);
}

void	ft_text_put2(t_gener *str)
{
	str->text = "X-axis Min        - Button S";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 180, 0xFFFFFF, str->text);
	str->text = "Y-axis Left       - Button A";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 200, 0xFFFFFF, str->text);
	str->text = "Y-axis Right      - Button D";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 220, 0xFFFFFF, str->text);
	str->text = "Z-axis Left       - Button Q";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 240, 0xFFFFFF, str->text);
	str->text = "Z-axis Right      - Button E";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 260, 0xFFFFFF, str->text);
	str->text = "Map Zoom +        - Button +";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 280, 0xFFFFFF, str->text);
	str->text = "Map Zoom -        - Button -";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 300, 0xFFFFFF, str->text);
	str->text = "Map Reset         - Button Tab";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 320, 0xFFFFFF, str->text);
	str->text = "Exit              - Button Esc";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 340, 0xFFFFFF, str->text);
	str->text = "Bresenham's algo  - Button O";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 360, 0xFFFFFF, str->text);
	str->text = "Xiaolin Wu's algo - Button P";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 380, 0xFFFFFF, str->text);
}

void	ft_text_put(t_gener *str)
{
	str->text = "Menu:";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 20, 0xFFFFFF, str->text);
	str->text = "Height Up         - Button C";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 40, 0xFFFFFF, str->text);
	str->text = "Height Down       - Button X";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 60, 0xFFFFFF, str->text);
	str->text = "Up Map            - Up arrow Button";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 80, 0xFFFFFF, str->text);
	str->text = "Down Map          - Down arrow Button";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 100, 0xFFFFFF, str->text);
	str->text = "Left map          - Left arrow Button";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 120, 0xFFFFFF, str->text);
	str->text = "Right Map         - Right arrow Button";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 140, 0xFFFFFF, str->text);
	str->text = "X-axis Plus       - Button W";
	mlx_string_put(str->mlx_ptr, str->win_ptr, 20, 160, 0xFFFFFF, str->text);
	ft_text_put2(str);
}

void	ft_str_init(t_gener *str)
{
	str->dep_x = 100;
	str->dep_y = 400;
	str->dep_mp = 1;
	str->a = 0;
	str->b = 0;
	str->s = 0;
	str->wu = 0;
	str->min = 0;
	str->max = 0;
	str->count_y = 0;
	str->count_x = 0;
	str->t = 0;
	str->bpp = 0;
	str->size_line = 0;
	str->endian = 0;
	str->color = 0;
	str->z = 0;
	str->zp = 0;
	str->tab_z = NULL;
	str->mlx_ptr = NULL;
	str->win_ptr = NULL;
	str->img_ptr = NULL;
	str->pixl = NULL;
	str->struct_xy = NULL;
	str->struct_xy2 = NULL;
}
