/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsusheno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 15:05:27 by dsusheno          #+#    #+#             */
/*   Updated: 2016/03/15 20:52:19 by dsusheno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include "get_next_line.h"

typedef struct		s_cord
{
	double		x;
	double		y;
	double		z;
	double		z_b;
	int			x_max;
	int			no_ex;
}					t_cord;

typedef struct		s_map
{
	int			x;
	int			y;
	double		z;
	double		x1;
	double		y1;
	double		z1;
}					t_map;

typedef struct		s_gener
{
	int				min;
	int				max;
	int				count_y;
	int				count_x;
	int				wu;
	int				t;
	int				dep_x;
	int				dep_y;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	color;
	double			a;
	double			b;
	double			s;
	double			z;
	double			zp;
	double			dep_mp;
	char			***tab_z;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*pixl;
	t_cord			**struct_xy;
	t_cord			**struct_xy2;
	char			*text;
}					t_gener;

typedef struct		s_line
{
	float			grad;
	float			intery;
	float			interx;
	int				dx;
	int				dy;
	int				x;
	int				y;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_line;

char				***read_file(char *file, int count);
void				ft_count_n(char *file, t_gener *str);
int					**ft_tab_xy(char ***map, int count);
t_cord				**ft_malloc_struct(t_gener *str);
void				ft_put_line_upright(t_cord **struct_xy, t_gener str);
void				ft_put_line_hor(t_cord **struct_xy, t_gener str);
int					ft_words(char *str, char c);
void				ft_put_segment(t_cord **struct_xy, t_gener str);
void				ft_map_action(t_gener *str, t_cord **struct_xy,
	t_cord **struct_xy2);
float				fpart(float x);
void				ft_draw_line(t_gener *str, t_line line);
void				draw_line_hor(t_gener *str, t_line line);
void				draw_lines_wu(t_cord **struct_xy, t_gener *str);
void				draw_lines_wu_upright(t_cord **struct_xy, t_gener *str);
float				f_part(float x);
int					my_key_fonction(int keycode, void *param);
void				my_key_fonction2(int keycode, t_gener *str);
void				ft_str_init(t_gener *str);
void				ft_text_put(t_gener *str);
void				ft_text_put2(t_gener *str);
void				ft_map_init_begin(t_gener *str);
void				ft_add_point(t_gener *str, int x, int y);
void				ft_map_free(t_gener *str);
float				f_part(float x);
void				ft_image_action(t_gener *str);
void				ft_min_max(int z, t_gener *str);
int					ft_words(char *str, char c);
void				ft_error(char *file);
void				ft_map_init_begin(t_gener *str);

#endif
