/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:09:24 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/17 18:09:25 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	matricemult(double m2[3][3], t_point *p)
{
	double rez[3];

	rez[0] = p->x * m2[0][0] + p->y * m2[0][1] + p->z * m2[0][2];
	rez[1] = p->x * m2[1][0] + p->y * m2[1][1] + p->z * m2[1][2];
	rez[2] = p->x * m2[2][0] + p->y * m2[2][1] + p->z * m2[2][2];
	p->x = rez[0];
	p->y = rez[1];
	p->z = rez[2];
}

static void	init_z(double (*m2)[3][3], char axe, double theta)
{
	if (axe == 'z')
	{
		(*m2)[0][0] = cos(theta);
		(*m2)[0][1] = -1 * sin(theta);
		(*m2)[0][2] = 0;
		(*m2)[1][0] = sin(theta);
		(*m2)[1][1] = cos(theta);
		(*m2)[1][2] = 0;
		(*m2)[2][0] = 0;
		(*m2)[2][1] = 0;
		(*m2)[2][2] = 1;
	}
}

static void	init_y(double (*m2)[3][3], char axe, double theta)
{
	if (axe == 'y')
	{
		(*m2)[0][0] = cos(theta);
		(*m2)[0][1] = 0;
		(*m2)[0][2] = sin(theta);
		(*m2)[1][0] = 0;
		(*m2)[1][1] = 1;
		(*m2)[1][2] = 0;
		(*m2)[2][0] = -1 * sin(theta);
		(*m2)[2][1] = 0;
		(*m2)[2][2] = cos(theta);
	}
}

static void	init_x(double (*m2)[3][3], char axe, double theta)
{
	if (axe == 'x')
	{
		(*m2)[0][0] = 1;
		(*m2)[0][1] = 0;
		(*m2)[0][2] = 0;
		(*m2)[1][0] = 0;
		(*m2)[1][1] = cos(theta);
		(*m2)[1][2] = -1 * sin(theta);
		(*m2)[2][0] = 0;
		(*m2)[2][1] = sin(theta);
		(*m2)[2][2] = cos(theta);
	}
}

void		multmat(char axe, t_point **point, double theta)
{
	int		p;
	double	m2[3][3];

	p = 0;
	init_z(&m2, axe, theta);
	init_y(&m2, axe, theta);
	init_x(&m2, axe, theta);
	while (point[p] != NULL)
	{
		matricemult(m2, point[p]);
		p++;
	}
}
