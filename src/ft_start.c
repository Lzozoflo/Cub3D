/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/20 11:02:50 by mlaussel         ###   ########.fr       */
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
	int px;
	int	py;

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
		{
			printf("Draw pixel at (%d, %d)\n", px, py);
			ft_color_pixel(0xFFFFFF, px, py, d);
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

int	ft_start(t_exec *e, t_data *d)
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
			e->player.dir_x = ((i - WIN_SIZE * 0.5) * e->s.rh);  // p.15
			e->player.dir_y = -1;                                //nord
			e->player.dir_z = (-(j - WIN_SIZE * 0.5) * e->s.rv); // p.15 Dernier point,l’axe z est inversement proportionnel au vecteurs verticaux de la fenêtre. Il faut donc prendre l'opposé pour la coordonnée z : ​-(j- H * 0.5) * R_V
			ft_intersection(e, d);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
	return (1);
}

/*
	// south
	e->s.sx = 0;
	e->s.sy = 1;
	e->s.sx2 = 0;
	e->s.sy2 = -3;
	// east
	e->s.ex = 1;
	e->s.ey = 0;
	e->s.ex2 = 0;
	e->s.ey2 = 3;
	// west
	e->s.ox = 1;
	e->s.oy = 0;
	e->s.ox2 = 0;
	e->s.oy2 = -3;
	*/
