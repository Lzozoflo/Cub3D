/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 09:11:56 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/10 15:15:42 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

// /**
//  * @brief `intersection between plane and straight line for west ans south wall`
//  *
//  * p.23 :	-(aOx + bOy + cOz + d)	--> numerator
//  *			/ (aux + buy + cuz)		--> denominator
//  *
//  * 			a, b, c, d : coord north, south, east or west
//  * 			ux, uy, uz : vectore director = dir_x, dir_y, dir_z
//  * 			Ox, Oy, Oz : camera = cx, cy, cz
//  */
// static void	ft_find_t_w_s(t_exec *e, char c, double *n, double *d)
// {
// 	if (c == 'w')
// 	{
// 		*n = -((e->s.w.a * e->s.cx) + (e->s.w.b * e->s.cy) + (e->s.w.c
// 					* e->s.cz) + e->s.w.d);
// 		*d = ((e->s.w.a * e->player.dir_x) + (e->s.w.b * e->player.dir_y)
// 				+ (e->s.w.c * e->player.dir_z));
// 	}
// 	else if (c == 's')
// 	{
// 		*n = -((e->s.s.a * e->s.cx) + (e->s.s.b * e->s.cy) + (e->s.s.c
// 					* e->s.cz) + e->s.s.d);
// 		*d = ((e->s.s.a * e->player.dir_x) + (e->s.s.b * e->player.dir_y)
// 				+ (e->s.s.c * e->player.dir_z));
// 	}
// 	else
// 	{
// 		*d = 0;
// 		*n = 0;
// 	}
// }

// /**
//  * @brief `intersection between plane and straight line`
//  *
//  * p.23 :	-(aOx + bOy + cOz + d)	--> numerator
//  *
//  *			/ (aux + buy + cuz)		--> denominator
//  *
//  * 			a, b, c, d : coord north, south, east or west
//  *
//  * 			ux, uy, uz : vectore director = dir_x, dir_y, dir_z
//  *
//  * 			Ox, Oy, Oz : camera = cx, cy, cz
//  *
//  * @return double @return t
//  */
// double	ft_find_t(t_exec *e, char c)
// {
// 	double	numerator;
// 	double	denominator;

// 	denominator = 0;
// 	numerator = 0;
// 	if (c == 'n')
// 	{
// 		numerator = -((e->cardi.n[e->wall.pos_y].a * e->s.cx) + (e->cardi.n[e->wall.pos_y].b * e->s.cy) + (e->cardi.n[e->wall.pos_y].c
// 					* e->s.cz) + e->cardi.n[e->wall.pos_y].d);
// 		denominator = ((e->cardi.n[e->wall.pos_y].a * e->player.dir_x) + (e->cardi.n[e->wall.pos_y].b
// 					* e->player.dir_y) + (e->cardi.n[e->wall.pos_y].c * e->player.dir_z));
// 	}
// 	else if (c == 'e')
// 	{
// 		numerator = -((e->s.e.a * e->s.cx) + (e->s.e.b * e->s.cy) + (e->s.e.c
// 					* e->s.cz) + e->s.e.d);
// 		denominator = ((e->s.e.a * e->player.dir_x) + (e->s.e.b
// 					* e->player.dir_y) + (e->s.e.c * e->player.dir_z));
// 	}
// 	else
// 		ft_find_t_w_s(e, c, &numerator, &denominator);
// 	if (denominator == 0)
// 		return (-1);
// 	return (numerator / denominator);
// }


#include "stdio.h"
double	ft_find_t(t_exec *e, char c)
{
	double	n;
	double	d;
	t_plane *plane;
	int		index;


	if (c == 'n')
	{
		index = e->wall.pos_y;
		plane = &e->cardi.n[index];
	}
	else if (c == 's')
	{
		index =  e->wall.pos_y;
		plane = &e->cardi.s[index];
	}
	else if (c == 'e')
	{
		index =  e->wall.pos_x;
		plane = &e->cardi.e[index];
	}
	else
	{
		index =  e->wall.pos_x;
		plane = &e->cardi.w[index];
	}
	n = -((plane->a * e->s.cx) + (plane->b * e->s.cy) + (plane->c
				* e->s.cz) + plane->d);
	d = ((plane->a * e->player.dir_x) + (plane->b
				* e->player.dir_y) + (plane->c * e->player.dir_z));
	if (d == 0)
		return (-1);
	return (n / d);
}
