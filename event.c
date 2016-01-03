/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:19:59 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/17 18:09:01 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	zoom(int keycode, t_env *e)
{
	if (keycode == 18 && e->zoom >= 4)
	{
		e->zoom -= 4;
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
	else if (keycode == 19)
	{
		e->zoom += 4;
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
}

void	rotate_up_left(int keycode, t_env *e)
{
	if (keycode == 125)
	{
		multmat('x', e->tab, -1 * PI / 24);
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
	else if (keycode == 123)
	{
		multmat('z', e->tab, PI / 24);
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
	else if (keycode == 30)
	{
		multmat('y', e->tab, PI / 24);
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
}

void	rotate_down_right(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		multmat('x', e->tab, PI / 24);
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
	else if (keycode == 124)
	{
		multmat('z', e->tab, -1 * PI / 24);
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
	else if (keycode == 33)
	{
		multmat('y', e->tab, -1 * PI / 24);
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
}

void	move_minus(int keycode, t_env *e)
{
	if (keycode == 13)
	{
		e->offset_y -= 20;
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
	else if (keycode == 0)
	{
		e->offset_x -= 20;
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
}

void	move_plus(int keycode, t_env *e)
{
	if (keycode == 1)
	{
		e->offset_y += 20;
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
	else if (keycode == 2)
	{
		e->offset_x += 20;
		mlx_clear_window(e->mlx, e->win);
		print_graph(e->tab, e);
	}
}
