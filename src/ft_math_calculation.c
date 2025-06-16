/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:07:56 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/16 16:51:50 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <math.h>

/**
 * @brief `horizontal and vertical distance between radius + fov`
 *
 * `p.11 FOV` - "The FOV can be set to 60 degrees or 𝜋 / 3 radians
 * (standard field of view)."
 *
 * `p.13 RH and RV`

 * R_H = 2 * tan(FOV / 2) / W
 * RV = 2 * tan(FOV * H / (W * 2)) / H
 *
 * --> true RV : 2 * tan(e->s.fov * WIN_SIZE / (2.0 * WIN_SIZE)) / WIN_SIZE;
 * we can simplify
 */
void	ft_fov_h_and_v_ratio(t_exec *e)
{
	e->s.fov = PI * 0.33;
	e->s.rh = 2 * tan(e->s.fov * 0.5) / (WIN_SIZE_SCALE);
	e->s.rv = 2 * tan(e->s.fov * 0.5) / (WIN_SIZE_SCALE);
}

/**
 * @brief `calculate radius`
 *
 * p.15
 *
 * (i - W *0.5) * Rh ; -1 ; (H * 0.5 - j) * Rv
 *
 */
void	ft_director_vector(t_exec *e, t_player *p, int i, int j)
{
	if (p->pos == 'w')
	{
		e->radius.ray[i][j].dir_x = -1;
		e->radius.ray[i][j].dir_y = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		e->radius.ray[i][j].dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
	}
	else if (p->pos == 's')
	{
		e->radius.ray[i][j].dir_x = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		e->radius.ray[i][j].dir_y = 1;
		e->radius.ray[i][j].dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
	}
	else if (p->pos == 'n')
	{
		e->radius.ray[i][j].dir_x = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		e->radius.ray[i][j].dir_y = -1;
		e->radius.ray[i][j].dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
	}
	else if (p->pos == 'e')
	{
		e->radius.ray[i][j].dir_x = 1;
		e->radius.ray[i][j].dir_y = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		e->radius.ray[i][j].dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
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
void	ft_move_l_r(t_exec *e, int i, int j)
{
	double	dx;
	double	dy;
	t_radius *r;

	r = &e->radius;
	dx = e->radius.ray[i][j].dir_x;
	dy = e->radius.ray[i][j].dir_y;
	e->radius.ray[i][j].dir_x = cos(e->player.angle) * dx
		- sin(e->player.angle) * dy;
	e->radius.ray[i][j].dir_y = sin(e->player.angle) * dx
		+ cos(e->player.angle) * dy;
}

/**
 * @brief `move back and forth`
 */
void	ft_move_f_b(t_exec *e, int i, int j)
{
	e->s.cx = e->s.cx + e->radius.ray[i][j].dir_x * e->player.moove;
	e->s.cy = e->s.cy + e->radius.ray[i][j].dir_y * e->player.moove;
	e->player.moove = 0;
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
