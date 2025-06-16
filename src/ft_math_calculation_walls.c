/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_calculation_walls.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:11:56 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/16 11:49:21 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

/**
 * @brief `intersection coord`
 *
 *p.23 :	I = O + u * t p.23

 *			u = dir

 *			O = camera = c
 */
void	ft_intersection_coord(t_exec *e, double t, int i, int j)
{
	e->s.ix = e->s.cx + t * e->radius.ray[i][j].dir_x;
	e->s.iy = e->s.cy + t * e->radius.ray[i][j].dir_y;
	e->s.iz = e->s.cz + t * e->radius.ray[i][j].dir_z;
}

/**
 * @brief `intersection between plane and straight line`
 *
 * p.23 :	-(aOx + bOy + cOz + d)	--> numerator
 *
 *			/ (aux + buy + cuz)		--> denominator
 *
 * 			a, b, c, d : coord north, south, east or west
 *
 * 			ux, uy, uz : vectore director = dir_x, dir_y, dir_z
 *
 * 			Ox, Oy, Oz : camera = cx, cy, cz
 *
 * @return double @return t
 */
double	ft_find_plane_intersection(t_exec *e, t_plane *plane, int i, int j)
{
	double	numerator;
	double	denominator;

	numerator = -((plane->a * e->s.cx) + (plane->b * e->s.cy) + (plane->c
				* e->s.cz) + plane->d);
	denominator = (plane->a *e->radius.ray[i][j].dir_x) + (plane->b * e->radius.ray[i][j].dir_y)
		+ (plane->c * e->radius.ray[i][j].dir_z);
	if (denominator == 0)
		return (-1);
	return (numerator / denominator);
}
