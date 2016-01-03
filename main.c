/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:09:17 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/18 16:30:59 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_graph(t_point **point, t_env *a)
{
	int p;

	espace_moi(point, a);
	p = 0;
	while (point[p] != NULL)
	{
		if ((p + 1) % a->xmax != 0)
			draw_line(*(point[p]), *(point[p + 1]), a);
		if (p < a->xmax * (a->ymax - 1))
			draw_line(*(point[p]), *(point[p + a->xmax]), a);
		p++;
	}
}

int		handle_key_event(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	zoom(keycode, e);
	rotate_up_left(keycode, e);
	rotate_down_right(keycode, e);
	move_plus(keycode, e);
	move_minus(keycode, e);
	return (0);
}

int		expose_hook(t_env *e)
{
	print_graph(e->tab, e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env e;

	if (ac != 2)
	{
		ft_putstr_fd("Invalid use: ./fdf file.fdf\n", 2);
		return (0);
	}
	e.tab = parsing(av[1], &e);
	e.mlx = mlx_init();
	e.offset_x = 0;
	e.offset_y = 0;
	e.zoom = 30;
	e.win = mlx_new_window(e.mlx, WIN_SIZE, WIN_SIZE, "fdf");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, handle_key_event, &e);
	mlx_loop(e.mlx);
	return (0);
}
