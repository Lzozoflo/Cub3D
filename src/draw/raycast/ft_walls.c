/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:49 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/26 10:16:55 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_init_wall(t_wall *w)
{
	w->x_check = 0;
	w->y_check = 0;
	w->t_n = -1;
	w->t_s = -1;
	w->t_e = -1;
	w->t_w = -1;
	w->t_min = MAX_D;
	w->face = 0;
}

/**
 * @brief `remove scale`
 *
 * p.38 : "To optimize the rendering, the scale allows you
 * to divide the number of pixels calculated by 4.
 * There will therefore ultimately be 4 times fewer calculations.
 * The principle is to do the calculations on a window 4 times smaller
 * (W / 2 by H / 2) then enlarge the result (the pixels of 1 by 1 will
 * become 2 by 2) up to the requested rendering window."
 */
static void	ft_color_scale(t_data *d, int i, int j, int color)
{
	int	scale_x;
	int	scale_y;
	int	k;
	int	l;

	k = 0;
	l = 0;
	scale_x = i * SCALE;
	scale_y = j * SCALE;
	while (k < SCALE)
	{
		l = 0;
		while (l < SCALE)
		{
			ft_color_pixel(color, k + scale_x, l + scale_y, d);
			l++;
		}
		k++;
	}
}

/**
 * @brief `color pixel with color of texture if intersection`
 *
 *p.30 : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 * and "We can therefore display a different color/texture
 * depending on the cardinal point."
 */
static void	ft_color_wall(t_data *d, int i, int j, t_ray radius)
{
	int					color;
	const size_t		half = d->win_scale >> 1;

	ft_intersection_coord(&d->exec, d->exec.wall.t_min, radius);
	if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0
		&& d->exec.wall.t_min < MAX_D)
	{
		color = ft_texture(d, d->exec.wall.face);
		color = ft_shadow(color, d);
		ft_color_scale(d, i, j, color);
	}
	else if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0
		&& d->exec.wall.t_min == MAX_D)
		ft_color_scale(d, i, j, 0x000000);
	else if ((size_t)j > half)
	{
		color = ft_color_shadow_floor(d->exec.floor, j, half);
		ft_color_scale(d, i, j, color);
	}
	else if ((size_t)j < half)
	{
		color = ft_color_shadow_ceiling(d->exec.sky, j, half);
		ft_color_scale(d, i, j, color);
	}
}

void	ft_east_west_walls(t_data *d, t_ray radius)
{
	int		x;
	int		k;
	t_exec	*e;

	k = MAX_D + 1;
	e = &d->exec;
	x = e->player.pos_x;
	if (radius.dir_x < 0)
	{
		while (x >= 0 && k-- != 0)
		{
			ft_east_wall(e, x--, radius);
		}
	}
	else if (radius.dir_x > 0)
	{
		while (x < e->max_width && k-- != 0)
		{
			ft_west_wall(e, x++, radius);
		}
	}
}

/**
 * @brief `main of wall`
 *
 * (p.30) - "Route of plans"
 * The easiest way to go through the planes is to start at
 * the index of the player's position (O), then increment or
 * decrement it according to the direction of the radius
 * (looking at the sign of u).
 * Thus, it is sufficient to stop at the first wall and
 * compare the distance (t) of the nearest wall on the’axe
 * of x with that closest to the’axe of y. It will therefore
 * be possible to display a different color/texture according
 * to the cardinal point.
 *
 * (p.30) : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 * and "We can therefore display a different color/texture
 * depending on the cardinal point."
 *
 */
void	ft_walls(t_data *d, int i, int j, t_ray radius)
{
	t_exec	*e;
	int		k;
	int		y;

	k = MAX_D + 1;
	e = &d->exec;
	y = e->player.pos_y;
	ft_init_wall(&e->wall);
	if (radius.dir_y < 0)
	{
		while (y >= 0 && k-- != 0)
		{
			ft_south_wall(e, y--, radius);
		}
	}
	else if (radius.dir_y > 0)
	{
		while (y < e->max_height && k-- != 0)
		{
			ft_north_wall(e, y++, radius);
		}
	}
	ft_east_west_walls(d, radius);
	if (e->wall.t_min > 0)
		ft_color_wall(d, i, j, radius);
}
