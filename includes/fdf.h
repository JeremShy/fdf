/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 18:32:25 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/18 16:30:50 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <get_next_line.h>
# include <libft.h>
# define WIN_SIZE 840
# define PI 3.141592653589793
# define MIN(x1, x2) (x1 < x2 ? x1 : x2)
# define MAX(x1, x2) (x1 > x2 ? x1 : x2)
# define ABS(x) x > 0 ? x : -1 * x

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int		py;
	int		px;
	int		color;
}				t_point;

typedef struct	s_env
{
	void	*win;
	void	*mlx;
	t_point	**tab;
	int		xmax;
	int		ymax;
	int		zmax;
	int		zoom;
	int		offset_x;
	int		offset_y;
	int		bpp;
	int		size_line;
	int		endian;
}				t_env;

t_point			**parsing(char *fichier, t_env *e);
void			print_point(t_point *point);
void			print_tab(t_point **point);
void			multmat(char axe, t_point **point, double theta);
void			draw_line(t_point p1, t_point p2, t_env *e);
void			quadrant1(t_point p1, t_point p2, t_env *e);
void			quadrant2(t_point p1, t_point p2, t_env *e);
void			quadrant3(t_point p2, t_point p1, t_env *e);
void			quadrant4(t_point p2, t_point p1, t_env *e);
void			espace_moi(t_point **tab, t_env *e);
void			aa_pixel_put(t_env *e, int x, int y, int color);
void			print_graph(t_point **tab, t_env *e);
void			zoom(int keycode, t_env *e);
void			rotate_up_left(int keycode, t_env *e);
void			rotate_down_right(int keycode, t_env *e);
void			move_plus(int keycode, t_env *e);
void			move_minus(int keycode, t_env *e);
void			handle_error(int *x, t_env *e, char *str);
#endif
