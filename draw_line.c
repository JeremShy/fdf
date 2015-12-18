/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:56 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/18 16:11:06 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	espace_moi(t_point **tab, t_env *e)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		tab[i]->px = (int)((tab[i]->x) * e->zoom + WIN_SIZE / 2 + e->offset_x);
		tab[i]->py = (int)((tab[i]->y) * e->zoom + WIN_SIZE / 2 + e->offset_y);
		i++;
	}
}

void	aa_pixel_put(t_env *e, int x, int y, int color)
{
	if (x < 0 || x > WIN_SIZE || y < 0 || y > WIN_SIZE)
		return ;
	mlx_pixel_put(e->mlx, e->win, x, y, color);
}

void	draw_line(t_point p1, t_point p2, t_env *e)
{
	int x;
	int y;

	y = MIN(p1.py, p2.py);
	x = MIN(p1.px, p2.px);
	if (p1.px == p2.px)
	{
		while (y <= (int)MAX(p1.py, p2.py))
		{
			aa_pixel_put(e, x, y, (p1.color + p2.color) / 2);
			y++;
		}
		return ;
	}
	if (p1.px < p2.px && p1.py <= p2.py)
		quadrant1(p1, p2, e);
	else if (p1.py <= p2.py && p2.px < p1.px)
		quadrant2(p1, p2, e);
	else if (p1.px < p2.px && p2.py <= p1.py)
		quadrant3(p1, p2, e);
	else if (p2.py <= p1.py && p2.px < p1.px)
		quadrant4(p1, p2, e);
}
