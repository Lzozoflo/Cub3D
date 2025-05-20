/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/20 12:35:49 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h> ////DELETE

/**
 * @brief `intersection between plane and straight line`
 *
 * p.23
 */
double	ft_find_t(t_exec *e, char c)
{
	double	numerator;
	double	denominator;

	denominator = 0;
	if (c == 'n')
	{
		numerator = -((e->s.nx * e->s.cx) + (e->s.ny * e->s.cy) + (e->s.nx2
					* e->s.cz) + e->s.ny2);
		denominator = ((e->s.nx * e->player.dir_x) + (e->s.ny * e->player.dir_y)
				+ (e->s.nx2 * e->player.dir_z));
	}
	else if (c == 'e')
	{
		numerator = -((e->s.ex * e->s.cx) + (e->s.ey * e->s.cy) + (e->s.ex2
					* e->s.cz) + e->s.ey2);
		denominator = ((e->s.ex * e->player.dir_x) + (e->s.ey * e->player.dir_y)
				+ (e->s.ex2 * e->player.dir_z));
	}
	else if (c == 'w')
	{
		numerator = -((e->s.ox * e->s.cx) + (e->s.oy * e->s.cy) + (e->s.ox2
					* e->s.cz) + e->s.oy2);
		denominator = ((e->s.ox * e->player.dir_x) + (e->s.oy * e->player.dir_y)
				+ (e->s.ox2 * e->player.dir_z));
	}
	else if (c == 's')
	{
		numerator = -((e->s.sx * e->s.cx) + (e->s.sy * e->s.cy) + (e->s.sx2
					* e->s.cz) + e->s.sy2);
		denominator = ((e->s.sx * e->player.dir_x) + (e->s.sy * e->player.dir_y)
				+ (e->s.sx2 * e->player.dir_z));
	}
	if (denominator == 0)
		return (-1);
	return (numerator / denominator);
}

int	ft_intersection(t_exec *e, t_data *d, char c)
{
	double	t;

	t = ft_find_t(e, c);
	if (t <= 0.0)
		return (0);
	e->s.ix = e->s.cx + t * e->player.dir_x;
	e->s.iy = e->s.cy + t * e->player.dir_y;
	e->s.iz = e->s.cz + t * e->player.dir_z;
	if (e->s.iz >= 0.0 && e->s.iz <= 1.0)
	{
		// px = (int)((e->s.ix + 1) * (WIN_SIZE / 2.0));
		// py = (int)((1.0 - e->s.iz) * (WIN_SIZE - 1));
		e->s.px = (int)((e->s.ix + 5) * (WIN_SIZE / 10.0));
		e->s.py = (int)((1.5 - e->s.iz) * (WIN_SIZE / 3.0));
		if (e->s.px >= 0 && e->s.px < WIN_SIZE && e->s.py >= 0 && e->s.py < WIN_SIZE)
		{
			if (c == 'n')
				ft_color_pixel(0xFFFFFF, e->s.px, e->s.py, d);
			else if (c == 'e')
			{
				ft_color_pixel(0xFF0000, e->s.px, e->s.py, d);
			}
			else if (c == 'w')
			{
				ft_color_pixel(0x0000FF, e->s.px, e->s.py, d);
			}
			else if (c == 's')
				ft_color_pixel(0x00FF00, e->s.px, e->s.py, d);
		}
	}
	return (1);
}

/**
 * @brief `horizontal and vertical distance between radius`
 */
void	ft_h_and_v_ratio(t_exec *e)
{
	e->s.rh = 2 * tan(e->s.fov / 2) / WIN_SIZE;
		// p.13
	e->s.rv = 2 * tan(e->s.fov * WIN_SIZE / (2.0 * WIN_SIZE)) / WIN_SIZE;
		// p.13
}


void	ft_north(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// north p.17
	e->s.nx = 0;
	e->s.ny = 1;
	e->s.nx2 = 0;
	e->s.ny2 = 3;
	// camera p.17
	e->s.cx = 0;
	e->s.cy = 0;
	e->s.cz = 0.5;
	// fov
	e->s.fov = PI / 3; // p.13
	ft_h_and_v_ratio(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			e->player.dir_x = -((i - WIN_SIZE * 0.5) * e->s.rh); // p.15
			e->player.dir_y = -1; //north
			e->player.dir_z = (-(j - WIN_SIZE * 0.5) * e->s.rv); //p.15
			ft_intersection(e, d, 'n');
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
}

void	ft_east(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// east p.17
	e->s.ex = 1;
	e->s.ey = 0;
	e->s.ex2 = 0;
	e->s.ey2 = 3;
	// camera p.17
	e->s.cx = 0;
	e->s.cy = 0;
	e->s.cz = 0.5;
	// fov
	e->s.fov = PI / 3; // p.13
	ft_h_and_v_ratio(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			e->player.dir_x = -((i - WIN_SIZE * 0.5) * e->s.rh); // p.15
			e->player.dir_y = -1; //north
			e->player.dir_z = (-(j - WIN_SIZE * 0.5) * e->s.rv); //p.15
			ft_intersection(e, d, 'e');
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
}

void	ft_west(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// west
	e->s.ox = 1;
	e->s.oy = 0;
	e->s.ox2 = 0;
	e->s.oy2 = -3;
	// camera p.17
	e->s.cx = 0;
	e->s.cy = 0;
	e->s.cz = 0.5;
	// fov
	e->s.fov = PI / 3; // p.13
	ft_h_and_v_ratio(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			e->player.dir_x = -((i - WIN_SIZE * 0.5) * e->s.rh); // p.15
			e->player.dir_y = -1; //north
			e->player.dir_z = (-(j - WIN_SIZE * 0.5) * e->s.rv); //p.15
			ft_intersection(e, d, 'w');
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
}

int	ft_start(t_exec *e, t_data *d)
{
	ft_north(e, d);
	ft_east(e, d);
	ft_west(e, d);
	return (1);
}

/*
	// south
	e->s.sx = 0;
	e->s.sy = 1;
	e->s.sx2 = 0;
	e->s.sy2 = -3;

	*/

	//p31 bandes
