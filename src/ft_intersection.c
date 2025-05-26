/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:30 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/26 16:34:35 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <stdlib.h>
#include <math.h>

/**
 * @brief `intersection between plane and straight line for west ans south wall`
 *
 * p.23 :	-(aOx + bOy + cOz + d)	--> numerator
 *			/ (aux + buy + cuz)		--> denominator
 *
 * 			a, b, c, d : coord north, south, east or west
 * 			ux, uy, uz : vectore director = dir_x, dir_y, dir_z
 * 			Ox, Oy, Oz : camera = cx, cy, cz
 */
static void	ft_find_t_w_s(t_exec *e, char c, double *n, double *d)
{
	if (c == 'w')
	{
		*n = -((e->s.w.a * e->s.cx) + (e->s.w.b * e->s.cy) + (e->s.w.c
					* e->s.cz) + e->s.w.d);
		*d = ((e->s.w.a * e->player.dir_x) + (e->s.w.b * e->player.dir_y)
				+ (e->s.w.c * e->player.dir_z));
	}
	else if (c == 's')
	{
		*n = -((e->s.s.a * e->s.cx) + (e->s.s.b * e->s.cy) + (e->s.s.c
					* e->s.cz) + e->s.s.d);
		*d = ((e->s.s.a * e->player.dir_x) + (e->s.s.b * e->player.dir_y)
				+ (e->s.s.c * e->player.dir_z));
	}
}

/**
 * @brief `intersection between plane and straight line`
 *
 * p.23 :	-(aOx + bOy + cOz + d)	--> numerator
 *			/ (aux + buy + cuz)		--> denominator
 *
 * 			a, b, c, d : coord north, south, east or west
 * 			ux, uy, uz : vectore director = dir_x, dir_y, dir_z
 * 			Ox, Oy, Oz : camera = cx, cy, cz
 *
 * @return double @return t
 */
double	ft_find_t(t_exec *e, char c)
{
	double	numerator;
	double	denominator;

	denominator = 0;
	numerator = 0;
	if (c == 'n')
	{
		numerator = -((e->s.n.a * e->s.cx) + (e->s.n.b * e->s.cy) + (e->s.n.c
					* e->s.cz) + e->s.n.d);
		denominator = ((e->s.n.a * e->player.dir_x) + (e->s.n.b * e->player.dir_y)
				+ (e->s.n.c * e->player.dir_z));
	}
	else if (c == 'e')
	{
		numerator = -((e->s.e.a * e->s.cx) + (e->s.e.b * e->s.cy) + (e->s.e.c
					* e->s.cz) + e->s.e.d);
		denominator = ((e->s.e.a * e->player.dir_x) + (e->s.e.b * e->player.dir_y)
				+ (e->s.e.c * e->player.dir_z));
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
 *p.23 :	I = O + u * t p.23
 *			u = dir
 *			O = camera = c
 */
static void	ft_intersection_coord(t_exec *e, double t)
{
	e->s.ix = e->s.cx + t * e->player.dir_x;
	e->s.iy = e->s.cy + t * e->player.dir_y;
	e->s.iz = e->s.cz + t * e->player.dir_z;//peu etre return
}

/**
 * @brief `if intersection, color`
 *
 * p.25 :	t <= 0 to check if intersection point is behind us.
 * p.25 :	iz >= 0 and iz < 1 because wall have size 1.
 * 			size 1 thanks to tab**
 */
int	ft_intersection(t_exec *e, t_data *d, char c, int i, int j)
{
	double	t;

	t = ft_find_t(e, c);
	if (t <= 0.0)
		return (0);
	ft_intersection_coord(e, t);
	if (e->s.iz >= 0.0 && e->s.iz < 1.0)
	{
		if (c == 'n')
			ft_color_pixel(0xFFFFFF, i, j, d);
		else if (c == 'e')
			ft_color_pixel(0xFF0000, i, j, d);
		else if (c == 'w')
			ft_color_pixel(0x0000FF, i, j, d);
		else if (c == 's')
			ft_color_pixel(0xFF00FF, i, j, d);
	}
	return (1);
}
