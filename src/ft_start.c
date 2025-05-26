/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/26 16:17:32 by fcretin          ###   ########.fr       */
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
 * p.11 PI / 3
 * p.13
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
 * y = -1 to north
 */
void	ft_director_vector(t_exec *e, int i, int j)
{
	if (e->player.dir_y)
	{
		e->player.dir_x = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
	}
	else
	{
		e->player.dir_y = ((i - WIN_SIZE * 0.5) * e->s.rh);
		e->player.dir_z = (WIN_SIZE * 0.5 - j) * e->s.rv;
	}
}


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
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	ft_init_point(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_director_vector(e, i, j);
			ft_move_l_r(e);
			ft_intersection(e, d, 'n', i, j);
			ft_intersection(e, d, 'e', i, j);
			ft_intersection(e, d, 'w', i, j);
			ft_intersection(e, d, 's', i, j);
			j++;
		}
		i++;
	}
	return (1);
}



/*
| Orientation | Angle (en radians) | Angle (en degrés) |
| ----------- | ------------------ | ----------------- |
| N (Nord)    | π/2                | 90°               |
| S (Sud)     | 3π/2               | 270°              |
| E (Est)     | 0                  | 0°                |
| W (Ouest)   | π                  | 180°              |
*/
