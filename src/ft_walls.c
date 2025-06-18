/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:49 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 15:59:58 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_init_wall(t_wall *w)
{
	w->t_n = -1;
	w->t_s = -1;
	w->t_e = -1;
	w->t_w = -1;
	w->t_min = -1;
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

static int	ft_color_shadow_floor(const unsigned int colorfloor, size_t y,
	const size_t half)
{
int		r;
int		g;
int		b;
int		shadow_color;
double	factor;

factor = ((double)(y - half) / (double)half);
if (factor > 1.0)
	factor = 1.0;
r = (colorfloor / 0x10000) * factor;
g = ((colorfloor / 0x100) % 0x100) * factor;
b = (colorfloor % 0x100) * factor;
shadow_color = (r * 0x10000) + (g * 0x100) + b;
return (shadow_color);
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
	const size_t		half = (WIN_SIZE / SCALE) >> 1;
	int	color;

	if (d->exec.wall.t_min < 0)
		return ;
	ft_intersection_coord(&d->exec, d->exec.wall.t_min, radius);
	if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0 && d->exec.wall.t_min <= MAX_D)
	{
		color = ft_texture(d, d->exec.wall.face);
		color = ft_shadow(color, d);
		ft_color_scale(d, i, j, color);
	}
	else if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0
		&& d->exec.wall.t_min > MAX_D)
		ft_color_scale(d, i, j, 0x000000);
	else if ((size_t)j > half)
	{
		color = ft_color_shadow_floor(d->exec.floor, j, half);
		ft_color_scale(d, i, j,color);
	}
	else if ((size_t)j < half)
	{
		color = ft_color_shadow_floor( d->exec.sky, j, half);
		ft_color_scale(d, i, j, color);
		// color = ft_shadow(d->exec.sky, d);
		// ft_color_scale(d, i, j, color);
	}
}

/**
 * @brief `main of wall`
 *
 * (p.30) - "Route of plans"
 */
void	ft_walls(t_data *d, int i, int j, t_ray radius)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_init_wall(&d->exec.wall);
	while (y < d->exec.max_height)
	{
		ft_north_wall(&d->exec, y, radius);
		ft_south_wall(&d->exec, y, radius);
		y++;
	}
	while (x < d->exec.max_width)
	{
		ft_east_wall(&d->exec, x, radius);
		ft_west_wall(&d->exec, x, radius);
		x++;
	}
	ft_color_wall(d, i, j, radius);
}

