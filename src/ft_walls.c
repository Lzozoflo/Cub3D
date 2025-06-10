/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:49 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/10 15:15:33 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include <math.h>

// /**
//  * @brief `init all info to found wall`
//  *
//  * 1- pos_x / pos_y : Find the square where the player is located (int for square)
//  *
//  * 2- dir_x / dir_y : Direction of the ray
//  *
//  * 3- dist_x / dist_y : how much distance (on the radius) must we travel to advance exactly 1 space.
//  * fabs beceaue want a distance not a direction
//  * 1 because it's a map with unity of size 1.
//  *
//  * 4- orientation_x / orientation_y : determine the direction : p.30 "looking at the u sign"
//  *
//  * 5- side_x / side_y : Calculate the distance between the player's position
//  * and the first wall on X and Y
//  */
// static void	ft_init_wall(t_data *d, t_wall *w)
// {
// 	w->pos_x = floor(d->exec.player.pos_x);
// 	w->pos_y = floor(d->exec.player.pos_y);
// 	w->dir_x = d->exec.player.dir_x;
// 	w->dir_y = d->exec.player.dir_y;
// 	w->dist_x = fabs(1 / w->dir_x);
// 	w->dist_y = fabs(1 / w->dir_y);
// 	if (w->dir_x < 0)
// 		w->orientation_x = -1;
// 	else
// 		w->orientation_x = 1;
// 	if (w->dir_y < 0)
// 		w->orientation_y = -1;
// 	else
// 		w->orientation_y = 1;
// 	if (w->orientation_x == -1)
// 		w->side_x = (d->exec.player.pos_x - w->pos_x) * w->dist_x;
// 	else
// 		w->side_x = (w->pos_x + 1.0 - d->exec.player.pos_x) * w->dist_x;
// 	if (w->orientation_y == -1)
// 		w->side_y = (d->exec.player.pos_y - w->pos_y) * w->dist_y;
// 	else
// 		w->side_y = (w->pos_y + 1.0 - d->exec.player.pos_y) * w->dist_y;
// }

// /**
//  * @brief `check if hit a wall`
//  *
//  * (p.30) "The simplest way to navigate the planes is to
//  * start at the player position index (O),
//  * then increment or decrement this according to the
//  * direction of the ray (looking at the sign of u).
//  * So, simply stop at the first wall and compare the distance
//  * (t) of the closest wall on the x-axis with the
//  * one closest on the y-axis.
//  * We can therefore display a different color/texture
//  * depending on the cardinal point."
//  */
// static void	ft_check_if_wall(t_data *d, t_wall *w)
// {
// 	w->hit = 0;
// 	while (w->hit == 0)
// 	{
// 		if (w->side_x < w->side_y)
// 		{
// 			w->side_x += w->dist_x;
// 			w->pos_x += w->orientation_x;
// 			w->side = 0;
// 		}
// 		else
// 		{
// 			w->side_y += w->dist_y;
// 			w->pos_y += w->orientation_y;
// 			w->side = 1;
// 		}
// 		if (d->exec.tab[w->pos_y][w->pos_x] == '1')
// 			w->hit = 1;
// 	}
// }

// /**
//  * @brief `check if we hit a vertical or horizontal wall
//  *
//  * t : roughly corresponds to the actual distance traveled
//  * from the starting position (player) to the affected wall.
//  */
// static void	ft_each_side(t_wall *w, t_exec *e)
// {
// 	if (w->side == 0)
// 	{
// 		//w->t = (w->side_x - w->dist_x);
// 		if (w->orientation_x > 0)
// 		{
// 			w->t = ft_find_t(e, 'w');
// 			w->d = 'w';
// 		}
// 		else
// 		{
// 			w->t = ft_find_t(e, 'e');
// 			w->d = 'e';
// 		}
// 	}
// 	if (w->side == 1)
// 	{
// 		//w->t = (w->side_y - w->dist_y);
// 		if (w->orientation_y > 0)
// 		{
// 			w->t = ft_find_t(e, 'n');
// 			w->d = 'n';
// 		}
// 		else
// 		{
// 			w->t = ft_find_t(e, 's');
// 			w->d = 's';
// 		}
// 	}
// }

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


double	min_of_four(double a, double b, double c, double d)
{
	double	min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;

	return min;
}


static void	ft_try_algo(t_data *d, t_wall *w)
{
	double t1 = 0;
	double t2 = 0;
	double t3 = 0;
	double t4 = 0;

	w->pos_x = floor(d->exec.wall.pos_x);
	w->pos_y = floor(d->exec.wall.pos_y);
	while (d->exec.tab[w->pos_y][w->pos_x] && d->exec.tab[w->pos_y][w->pos_x] != '1')
	{
		w->pos_x++;
	}
	t1 = ft_find_t(&d->exec, 'n');
	t2 = ft_find_t(&d->exec, 's');
	w->pos_x = floor(d->exec.wall.pos_x);
	while (d->exec.tab[w->pos_y][w->pos_x] && d->exec.tab[w->pos_y][w->pos_x] != '1')
	{
		w->pos_y++;
	}
	t3 = ft_find_t(&d->exec, 'n');
	t4 = ft_find_t(&d->exec, 's');
	w->t = min_of_four(t1, t2, t3, t4);
}

/**
 * @brief `main of wall`
 *
 *p.30 : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 */
void	ft_walls(t_data *d, int i, int j)
{
	t_wall	w;
	int		color;

	// ft_init_wall(d, &w);
	// ft_check_if_wall(d, &w);
	// ft_each_side(&w, &d->exec);
	ft_try_algo(d, &w);
	ft_intersection_coord(&d->exec, w.t);
	if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0
		&& w.t > 0) // && ft_check_east(d) == 1)
	{
		color = ft_texture(d, w.d);
		ft_color_pixel(color, i, j, d);
	}
}
