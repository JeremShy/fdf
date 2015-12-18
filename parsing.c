/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 19:34:29 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/18 16:40:53 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int		ft_open(char *fichier, int *x, int *y, t_env *e)
{
	int		fd;
	char	*str;
	char	**split;
	int		i;

	fd = open(fichier, O_RDONLY);
	*y = 0;
	*x = -1;
	while ((i = get_next_line(fd, &str)))
	{
		if (i == -1)
		{
			ft_putstr_fd("Error: Invalid file.\n", 2);
			exit(EXIT_FAILURE);
		}
		handle_error(x, e, str);
		(*y)++;
	}
	return (fd);
}

static int		process_tab(t_point ***rez, t_env *e, char *str, int y)
{
	char		**split;
	static int	nb = 0;
	int			x;

	x = 0;
	split = ft_strsplit(str, ' ');
	while (split[x] != NULL)
	{
		(*rez)[nb] = malloc(sizeof(t_point));
		((*rez)[nb])->x = x - e->xmax / 2;
		((*rez)[nb])->y = y - e->ymax / 2;
		((*rez)[nb])->z = ft_atoi(split[x]);
		((*rez)[nb])->py = ((*rez)[nb])->y;
		((*rez)[nb])->px = ((*rez)[nb])->x;
		if (e->zmax <= ft_atoi(split[x]))
			e->zmax = ft_atoi(split[x]);
		x++;
		nb++;
	}
	return (nb);
}

static int		recup_tab(t_env *e, int fd, t_point ***rez)
{
	int		y;
	char	*str;
	int		nb;

	nb = 0;
	y = 0;
	while (get_next_line(fd, &str))
	{
		nb = process_tab(rez, e, str, y);
		y++;
	}
	return (nb);
}

static void		color_and_error(t_env *e, int nb, t_point **rez)
{
	int	x;

	if (nb % e->xmax != 0)
	{
		ft_putstr_fd("Error: Invalid file\n", 2);
		exit(EXIT_FAILURE);
	}
	x = 0;
	while (rez[x] != NULL)
	{
		(rez[x])->color = (255 - (rez[x])->z * 255 / ((double)e->zmax + 0.01))
			+ 256 * (rez[x])->z * 255 / ((double)e->zmax + 0.01) + 65536;
		(rez[x])->z -= e->zmax / 2;
		x++;
	}
}

t_point			**parsing(char *fichier, t_env *e)
{
	int		fd;
	t_point **rez;
	int		x;
	int		y;
	int		nb;

	fd = ft_open(fichier, &x, &y, e);
	e->xmax = x;
	e->ymax = y;
	rez = malloc(x * y * sizeof(t_point*));
	if (!rez)
	{
		ft_putstr_fd("Malloc failed\n", 2);
	}
	x = open(fichier, O_RDONLY);
	close(fd);
	fd = x;
	e->zmax = -2147483648;
	nb = recup_tab(e, fd, &rez);
	rez[nb] = NULL;
	color_and_error(e, nb, rez);
	return (rez);
}
