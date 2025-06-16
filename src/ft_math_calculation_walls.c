/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_calculation_walls.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:11:56 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/16 12:43:26 by mlaussel         ###   ########.fr       */
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
 * p.34 : "For each intersection calculation,
 * it is possible to remove parameters from the calculation.
 * For example, to calculate a plane in x, it will be possible
 * to remove all the parameters referring to the y axis since
 * they will all be 0. The opposite is also true."
 * --> delete calculates with c because c = 0
 * --> delete calculates with a because a = 0
 *
 * @return double @return t
 */
double	ft_find_plane_intersection_n_s(t_exec *e, t_plane *plane, int i, int j)
{
	double	numerator;
	double	denominator;

	numerator = -((plane->b * e->s.cy) + plane->d);
	denominator = (plane->b * e->radius.ray[i][j].dir_y);
	if (denominator == 0)
		return (-1);
	return (numerator / denominator);
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
 * p.34 : "For each intersection calculation,
 * it is possible to remove parameters from the calculation.
 * For example, to calculate a plane in x, it will be possible
 * to remove all the parameters referring to the y axis since
 * they will all be 0. The opposite is also true."
 * --> delete calculates with c because c = 0
 * --> delete calculates with b because b = 0
 *
 * @return double @return t
 */
double	ft_find_plane_intersection_e_w(t_exec *e, t_plane *plane, int i, int j)
{
	double	numerator;
	double	denominator;

	numerator = -((plane->a * e->s.cx) + plane->d);
	denominator = (plane->a *e->radius.ray[i][j].dir_x);
	if (denominator == 0)
		return (-1);
	return (numerator / denominator);
}
