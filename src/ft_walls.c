/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:49 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/11 16:01:06 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_init_wall(t_data *d)
{
	d->exec.wall.t_n = -1;
	d->exec.wall.t_s = -1;
	d->exec.wall.t_e = -1;
	d->exec.wall.t_w = -1;
	d->exec.wall.t_min = -1;
	d->exec.wall.face = 0;
}

/**
 * @brief `color pixel with color of texture if intersection`
 *
 *p.30 : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 * and "We can therefore display a different color/texture 
 * depending on the cardinal point."
 */
static void	ft_color_wall(t_data *d, int i, int j)
{
	int	color;
	if (d->exec.wall.t_min < 0)
		return ;
	ft_intersection_coord(&d->exec, d->exec.wall.t_min);
	if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0)
	{
		color = ft_texture(d, d->exec.wall.face);
		ft_color_pixel(color, i, j, d);
	}
}

/**
 * @brief `main of wall`
 *
 * (p.30) - "Route of plans"
 */
void	ft_walls(t_data *d, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_init_wall(d);
	while (y < d->exec.max_height)
	{
		ft_north_wall(d, y);
		ft_south_wall(d, y);
		y++;
	}
	while (x < d->exec.max_width)
	{
		ft_east_wall(d, x);
		ft_west_wall(d, x);
		x++;
	}
	ft_color_wall(d, i, j);
}
