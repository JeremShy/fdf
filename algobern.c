/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobern.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 18:08:49 by jcamhi            #+#    #+#             */
/*   Updated: 2015/12/17 18:08:50 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	quadrant1(t_point p1, t_point p2, t_env *e)
{
	int dp;
	int de;
	int	dne;
	int i;

	i = ((double)(p2.py - p1.py) / ((double)p2.px - p1.px) > 1 ? 0 : 1);
	de = (i ? 2 * (p2.py - p1.py) : 2 * (p2.px - p1.px));
	dp = (i ? 2 * (p2.py - p1.py) - (p2.px - p1.px)
			: 2 * (p2.px - p1.px) - (p2.py - p1.py));
	dne = (i ? 2 * ((p2.py - p1.py) - (p2.px - p1.px))
			: 2 * ((p2.px - p1.px) - (p2.py - p1.py)));
	aa_pixel_put(e, p1.px, p1.py, p1.color);
	while ((p1.px < p2.px && i == 1) || (p1.py < p2.py && i == 0))
	{
		if (dp <= 0)
			dp = dp + de;
		else
		{
			i ? p1.py++ : p1.px++;
			dp = dp + dne;
		}
		i ? p1.px++ : p1.py++;
		aa_pixel_put(e, p1.px, p1.py, (p1.color + p2.color) / 2);
	}
}

void	quadrant2(t_point p1, t_point p2, t_env *e)
{
	int dp;
	int de;
	int	dne;
	int i;

	i = ((double)(p2.py - p1.py) / ((double)p1.px - p2.px) > 1 ? 0 : 1);
	de = (i ? 2 * (p2.py - p1.py) : 2 * (p1.px - p2.px));
	dp = (i ? 2 * (p2.py - p1.py) - (p1.px - p2.px)
			: 2 * (p1.px - p2.px) - (p2.py - p1.py));
	dne = (i ? 2 * ((p2.py - p1.py) - (p1.px - p2.px))
			: 2 * ((p1.px - p2.px) - (p2.py - p1.py)));
	aa_pixel_put(e, p1.px, p1.py, p1.color);
	while ((p1.px > p2.px && i == 1) || (p1.py < p2.py && i == 0))
	{
		if (dp <= 0)
			dp = dp + de;
		else
		{
			dp = dp + dne;
			i ? p1.py++ : p1.px--;
		}
		i ? p1.px-- : p1.py++;
		aa_pixel_put(e, p1.px, p1.py, (p1.color + p2.color) / 2);
	}
}

void	quadrant3(t_point p1, t_point p2, t_env *e)
{
	int dp;
	int de;
	int	dne;
	int i;

	i = ((double)(p1.py - p2.py) / ((double)p2.px - p1.px) > 1 ? 0 : 1);
	de = (i ? 2 * (p1.py - p2.py) : 2 * (p2.px - p1.px));
	dp = (i ? 2 * (p1.py - p2.py) - (p2.px - p1.px)
			: 2 * (p2.px - p1.px) - (p1.py - p2.py));
	dne = (i ? 2 * ((p1.py - p2.py) - (p2.px - p1.px))
			: 2 * ((p2.px - p1.px) - (p1.py - p2.py)));
	aa_pixel_put(e, p1.px, p1.py, p1.color);
	while ((p1.px < p2.px && i == 1) || (p1.py > p2.py && i == 0))
	{
		if (dp <= 0)
			dp = dp + de;
		else
		{
			dp = dp + dne;
			i ? p1.py-- : p1.px++;
		}
		i ? p1.px++ : p1.py--;
		aa_pixel_put(e, p1.px, p1.py, (p1.color + p2.color) / 2);
	}
}

void	quadrant4(t_point p1, t_point p2, t_env *e)
{
	int dp;
	int de;
	int	dne;
	int i;

	i = ((double)(p1.py - p2.py) / ((double)p1.px - p2.px) > 1 ? 0 : 1);
	de = (i ? 2 * (p1.py - p2.py) : 2 * (p1.px - p2.px));
	dp = (i ? 2 * (p1.py - p2.py) - (p1.px - p2.px)
			: 2 * (p1.px - p2.px) - (p1.py - p2.py));
	dne = (i ? 2 * ((p1.py - p2.py) - (p1.px - p2.px))
			: 2 * ((p1.px - p2.px) - (p1.py - p2.py)));
	aa_pixel_put(e, p1.px, p1.py, p1.color);
	while ((p1.px > p2.px && i == 1) || (p1.py > p2.py && i == 0))
	{
		if (dp <= 0)
			dp = dp + de;
		else
		{
			i ? p1.py-- : p1.px--;
			dp = dp + dne;
		}
		i ? p1.px-- : p1.py--;
		aa_pixel_put(e, p1.px, p1.py, (p1.color + p2.color) / 2);
	}
}
