/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:30 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/20 16:44:01 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <stdlib.h>
#include <math.h>

static void	ft_find_t_w_s(t_exec *e, char c, double *n, double *d)
{
	if (c == 'w')
	{
		*n = -((e->s.ox * e->s.cx) + (e->s.oy * e->s.cy) + (e->s.ox2
					* e->s.cz) + e->s.oy2);
		*d = ((e->s.ox * e->player.dir_x)
				+ (e->s.oy * e->player.dir_y)
				+ (e->s.ox2 * e->player.dir_z));
	}
	else if (c == 's')
	{
		*n = -((e->s.sx * e->s.cx) + (e->s.sy * e->s.cy) + (e->s.sx2
					* e->s.cz) + e->s.sy2);
		*d = ((e->s.sx * e->player.dir_x)
				+ (e->s.sy * e->player.dir_y)
				+ (e->s.sx2 * e->player.dir_z));
	}
}

/**
 * @brief `intersection between plane and straight line`
 *
 * p.23
 */
static double	ft_find_t(t_exec *e, char c)
{
	double	numerator;
	double	denominator;

	denominator = 0;
	numerator = 0;
	if (c == 'n')
	{
		numerator = -((e->s.nx * e->s.cx) + (e->s.ny * e->s.cy) + (e->s.nx2
					* e->s.cz) + e->s.ny2);
		denominator = ((e->s.nx * e->player.dir_x) + (e->s.ny * e->player.dir_y)
				+ (e->s.nx2 * e->player.dir_z));
	}
	else if (c == 'e')
	{
		numerator = -((e->s.ex * e->s.cx) + (e->s.ey * e->s.cy) + (e->s.ex2
					* e->s.cz) + e->s.ey2);
		denominator = ((e->s.ex * e->player.dir_x) + (e->s.ey * e->player.dir_y)
				+ (e->s.ex2 * e->player.dir_z));
	}
	else
		ft_find_t_w_s(e, c, &numerator, &denominator);
	if (denominator == 0)
		return (-1);
	return (numerator / denominator);
}

/**
 * @brief `intersection coord`
 *
 *	I = O + u * t //p.23
 * u = dir
 * O = camera = c
 */
static void	ft_intersection_coord(t_exec *e, double t)
{
	e->s.ix = e->s.cx + t * e->player.dir_x;
	e->s.iy = e->s.cy + t * e->player.dir_y;
	e->s.iz = e->s.cz + t * e->player.dir_z;
}

/**
 * @brief `if intersection, color`
 *
 * p.31
 */
int	ft_intersection(t_exec *e, t_data *d, char c)
{
	double	t;
	// static int i = 0;

	//printf("dir_y in ft_intersection: %f\n", e->player.dir_y);
	t = ft_find_t(e, c);
	// printf("t : %f\n", t);
	if (t <= 0.0)
		return (0);
	ft_intersection_coord(e, t);
	if (e->s.iz >= 0.0 && e->s.iz < 1.0)
	{
		e->s.px = (int)((e->s.ix + 5) * (WIN_SIZE / 10.0));
		e->s.py = (int)((1.5 - e->s.iz) * (WIN_SIZE / 3.0));
		if (e->s.px >= 0 && e->s.px < WIN_SIZE
			&& e->s.py >= 0 && e->s.py < WIN_SIZE)
		{
			if (c == 'n')
				ft_color_pixel(0xFFFFFF, e->s.px, e->s.py, d);
			else if (c == 'e')
			{
				// if (i++ < 50)
				// {
				// 	printf(" rh = %f, dir_x = %f, t = %f, ix = %f, px = %d\n",
				// 		e->s.rh, e->player.dir_x, t, e->s.ix, e->s.px);
				// // }

				ft_color_pixel(0xFF0000, e->s.px, e->s.py, d);
			}
			else if (c == 'w')
				ft_color_pixel(0x0000FF, e->s.px, e->s.py, d);
			else if (c == 's')
				ft_color_pixel(0xFF00FF, e->s.px, e->s.py, d);
		}
	}
	return (1);
}
