/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:49 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/05 13:07:02 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include <math.h>

/**
 * @brief `init all info to found wall`
 *
 * 1- Find the square where the player is located (int for square)
 *
 * 2- Direction of the ray
 *
 * 3- how much distance (on the radius) must we travel to advance exactly 1 space
 *
 * fabs beceaue want a distance not a direction
 * 1 because it's a map with unity of size 1.
 *
 * 4- determine the direction : p.30 "looking at the u sign"
 * --> orientation_x and orientation_y 1 or -1
 *
 * 5- Calculate the distance between the player's position
 * and the first boundary on X and Y
 */
static void	ft_init_wall(t_data *d, t_wall *w)
{
	w->pos_x = floor(d->exec.player.pos_x);
	w->pos_y = floor(d->exec.player.pos_y);
	w->dir_x = d->exec.player.dir_x;
	w->dir_y = d->exec.player.dir_y;
	w->dist_x = fabs(1 / w->dir_x);
	w->dist_y = fabs(1 / w->dir_y);
	if (w->dir_x < 0)
		w->orientation_x = -1;
	else
		w->orientation_x = 1;
	if (w->dir_y < 0)
		w->orientation_y = -1;
	else
		w->orientation_y = 1;
	if (w->orientation_x == -1)
		w->side_x = (d->exec.player.pos_x - w->pos_x) * w->dist_x;
	else
		w->side_x = (w->pos_x + 1.0 - d->exec.player.pos_x) * w->dist_x;
	if (w->orientation_y == -1)
		w->side_y = (d->exec.player.pos_y - w->pos_y) * w->dist_y;
	else
		w->side_y = (w->pos_y + 1.0 - d->exec.player.pos_y) * w->dist_y;
}

/**
 * @brief `check if hit a wall`
 */
static void	ft_check_if_wall(t_data *d, t_wall *w)
{
	w->hit = 0;
	while (w->hit == 0)
	{
		if (w->side_x < w->side_y)
		{
			w->side_x += w->dist_x;
			w->pos_x += w->orientation_x;
			w->side = 0;
		}
		else
		{
			w->side_y += w->dist_y;
			w->pos_y += w->orientation_y;
			w->side = 1;
		}
		if (d->exec.tab[w->pos_y][w->pos_x] == '1')
			w->hit = 1;
	}
}

/**
 * @brief `check if we hit a vertical or horizontal wall
 *
 */
static void	ft_each_side(t_wall *w)
{
	if (w->side == 0)
	{
		w->t = (w->side_x - w->dist_x);
		if (w->orientation_x > 0)
			w->d = 'e';
		else
			w->d = 'w';
	}
	if (w->side == 1)
	{
		w->t = (w->side_y - w->dist_y);
		if (w->orientation_y > 0)
			w->d = 'n';
		else
			w->d = 's';
	}
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
	e->s.iz = e->s.cz + t * e->player.dir_z;
}

/**
 * @brief `main of wall`
 *
 *
 *p.30 : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 */
void	ft_walls(t_data *d, int y, int x, t_u_texture *u)
{
	ft_init_wall(d, &d->w);
	ft_check_if_wall(d, &d->w);
	ft_each_side(&d->w);
	ft_intersection_coord(&d->exec, d->w.t);
	u->c = d->w.d;
	if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0
		&& d->w.t > 0) // && ft_check_east(d) == 1)
	{
		ft_texture(d, u);
		ft_color_pixel(u->color, y, x, d);
	}
}
