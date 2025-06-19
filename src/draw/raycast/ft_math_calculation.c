/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:07:56 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/19 10:31:14 by fcretin          ###   ########.fr       */
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
	e->s.rh = 2 * tan(e->s.fov * 0.5) / ((WIN_SIZE / SCALE));
	e->s.rv = 2 * tan(e->s.fov * 0.5) / ((WIN_SIZE / SCALE));
}

/**
 * @brief `calculate radius`
 *
 * `p.15 - Radius`
 *
 * (i - W *0.5) * Rh ; -1 ; (H * 0.5 - j) * Rv
 *
 * `normalize`
 *
 * `(p.37) - Twilight`
 *
 * "Note: Remember to normalize the ray vectors when creating
 * so that t represents the distance with the intersection afterwards."
 *
 * Normalized vector: u = u / |u|
 *
 * normalize : |u| = sqrt(x² + y² + z²)
 *
 */
void	ft_director_vector(t_exec *e, int i, int j)
{
	t_ray	*ray;
	double	normalize;

	ray = &e->radius.ray[i][j];
	ray->dir_x = (i - (WIN_SIZE / SCALE) * 0.5) * e->s.rh;
	ray->dir_y = -1.0;
	ray->dir_z = ((WIN_SIZE / SCALE) * 0.5 - j) * e->s.rv;
	normalize = sqrt(ray->dir_x * ray->dir_x
			+ ray->dir_y * ray->dir_y + ray->dir_z * ray->dir_z);
	if (normalize != 0.0)
	{
		ray->dir_x /= normalize;
		ray->dir_y /= normalize;
		ray->dir_z /= normalize;
	}
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
