/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:57:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 12:00:21 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <math.h>

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
t_ray	ft_rotate(t_exec *e, int i, int j)
{
	t_ray	base;
	t_ray	rotated;

	base = e->radius.ray[i][j];
	rotated.dir_x = base.dir_x * cos(e->player.angle)
		- base.dir_y * sin(e->player.angle);
	rotated.dir_y = base.dir_x * sin(e->player.angle)
		+ base.dir_y * cos(e->player.angle);
	rotated.dir_z = base.dir_z;
	return (rotated);
}

/**
 * @brief `move back and forth`
 */
void	ft_move(t_exec *e)
{
	e->player.dir_x = cos(e->player.angle);
	e->player.dir_y = sin(e->player.angle);
	e->s.cx = e->s.cx + e->player.dir_x * e->player.moove;
	e->s.cy = e->s.cy + e->player.dir_y * e->player.moove;
	e->player.moove = 0;
}
