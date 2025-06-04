/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:07:56 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/04 10:23:40 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

/**
 * @brief `horizontal and vertical distance between radius + fov`
 *
 * p.11 PI / 3
 * p.13 RH and RV
 */
void	ft_fov_h_and_v_ratio(t_exec *e)
{
	e->s.fov = PI / 3;
	e->s.rh = 2 * tan(e->s.fov / 2) / WIN_SIZE;
	e->s.rv = 2 * tan(e->s.fov * WIN_SIZE / (2.0 * WIN_SIZE)) / WIN_SIZE;
}

/**
 * @brief `calculate radius`
 *
 * p.15
 *
 * (i - W *0.5) * Rh ; (H * 0.5 - j) * Rv
 *
 */
void	ft_director_vector(t_exec *e, int i, int j)
{
	if (e->player.pos == 'w')
	{
		e->player.dir_x = -1;
		e->player.dir_y = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
	}
	else if (e->player.pos == 's')
	{
		e->player.dir_x = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_y = 1;
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
	}
	else if (e->player.pos == 'n')
	{
		e->player.dir_x = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_y = -1;
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
	}
	else if (e->player.pos == 'e')
	{
		e->player.dir_x = 1;
		e->player.dir_y = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
	}
}

/**
 * @brief `rotate in place`
 *
 * p.29 : rotation matrix z
 *
 * cos𝜃	-sin𝜃	0
 * sin𝜃	cos𝜃	0
 * 0		0	  1
 *
 */
void	ft_move_l_r(t_exec *e)
{
	int	dx;
	int	dy;

	dx = e->player.dir_x;
	dy = e->player.dir_y;
	e->player.dir_x = cos(e->player.angle) * dx - sin(e->player.angle) * dy;
	e->player.dir_y = sin(e->player.angle) * dx + cos(e->player.angle) * dy;
}

/**
 * @brief `init camera/position of player`
 *
 * p.17
 *
 */
void	ft_init_camera(t_exec *e)
{
	e->s.cx = e->player.pos_x;
	e->s.cy = e->player.pos_y;
	e->s.cz = e->player.pos_z;
}
