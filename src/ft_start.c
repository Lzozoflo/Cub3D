/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/19 17:51:00 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include <stdio.h> ////DELETE

double	ft_find_t(t_exec *e)
{
	double	numerator;
	double	denominator;

	numerator = -((e->s.nx * e->s.cx) + (e->s.ny * e->s.cy) + (e->s.nx2
				* e->s.cz) + e->s.ny2);
	denominator = ((e->s.nx * e->player.dir_x) + (e->s.ny * e->player.dir_y)
			+ (e->s.nx2 * e->player.dir_z));
	if (denominator == 0)
		return (-1);
	return (numerator / denominator);
}

int	ft_intersection(t_exec *e, t_data *d)
{
	double	t;
	int		px;
	int		py;

	t = ft_find_t(e);
	if (t <= 0.0)
		return (0);
	e->s.ix = e->s.cx + t * e->player.dir_x;
	e->s.iy = e->s.cy + t * e->player.dir_y;
	e->s.iz = e->s.cz + t * e->player.dir_z;
	if (e->s.iz >= 0.0 && e->s.iz <= 1.0)
	{
		px = (int)((e->s.ix + 5) * (WIN_SIZE / 10.0));
		py = (int)((1.5 - e->s.iz) * (WIN_SIZE / 3.0));

		if (px >= 0 && px < WIN_SIZE && py >= 0 && py < WIN_SIZE)
			ft_color_pixel(0xFFFFFF, px, py, d);
	}
	return (1);
}


int	ft_start(t_exec *e, t_data *d)
{
	int		i;
	double	camera;

	i = 0;
	camera = 0;
	// north
	e->s.nx = 0;
	e->s.ny = 1;
	e->s.nx2 = 0;
	e->s.ny2 = -3;
	// south
	e->s.sx = 0;
	e->s.sy = -1;
	e->s.sx2 = 0;
	e->s.sy2 = -3;
	// east
	e->s.ex = 1;
	e->s.ey = 0;
	e->s.ex2 = 3;
	e->s.ey2 = 0;
	// west
	e->s.ox = -1;
	e->s.oy = 0;
	e->s.ox2 = -3;
	e->s.oy2 = 0;
	// camera
	e->s.cx = 0;
	e->s.cy = 0;
	e->s.cz = 0.5;
	while (i < WIN_SIZE)
	{
		camera = 2.0 * i / (double)WIN_SIZE - 1.0;
		e->player.dir_x = camera;
		e->player.dir_y = 1.0;
		e->player.dir_z = 0;
		ft_intersection(e, d);
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
	return (1);
}
