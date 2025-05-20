/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/20 16:22:09 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>
#include <stdio.h> ////DELETE

/**
 * @brief `horizontal and vertical distance between radius + fov`
 *
 * p.13
 */
void	ft_fov_h_and_v_ratio(t_exec *e)
{
	e->s.fov = PI / 3;
	e->s.rh = 2 * tan(e->s.fov / 2) / WIN_SIZE;
	printf(" RH : %f\n",e->s.rh );
	e->s.rv = 2 * tan(e->s.fov * WIN_SIZE / (2.0 * WIN_SIZE)) / WIN_SIZE;
}

/**
 * @brief `calculate radius`
 *
 * p.15
 *
 * y = -1 to north
 */
void	ft_radius(t_exec *e, int i, int j, char c)
{
	if (c == 'w')
	{
		e->player.dir_x = -1;
		e->player.dir_y = -((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_z = (-(j - WIN_SIZE * 0.5) * e->s.rv);
	}
	else if (c == 's')
	{
		e->player.dir_x = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_y = 1;
		e->player.dir_z = (-(j - WIN_SIZE * 0.5) * e->s.rv);
	}
	else
	if (c == 'n')
	{
	// (void)c;
		e->player.dir_x = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_y = -1;
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
		// printf("dir_x from ft_radius: %f\n", e->player.dir_x);
	}
	else if (c == 'e')
	{
		e->player.dir_x = 1;
		e->player.dir_y = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
		//printf("dir_y from ft_radius: %f\n", e->player.dir_y);
	}
}

/**
 * @brief `init camera`
 *
 * p.17
 *
 */
void	ft_init_camera(t_exec *e)
{
	e->s.cx = 0;
	e->s.cy = 0;
	e->s.cz = 0.5;
}

int	ft_start(t_exec *e, t_data *d)
{
	ft_north(e, d);
	ft_east(e, d);
	ft_west(e, d);
	//ft_south(e, d);
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
	return (1);
}
