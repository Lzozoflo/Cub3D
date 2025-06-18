/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:07:56 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 10:58:01 by mlaussel         ###   ########.fr       */
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
 * @brief `normalize`
 *
 * `(p.37) - Twilight`
 *
 * "Note: Remember to normalize the ray vectors when creating
 * so that t represents the distance with the intersection afterwards."
 *
 * Normalized vector: u = u / |u|
 *
 * normalize : |u| = sqrt(x² + y² + z²)
 */
static void	ft_normalize(t_ray *ray)
{
	double	normalize;

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
 * @brief `calculate radius`
 *
 * `p.15 - Radius`
 *
 * (i - W *0.5) * Rh ; -1 ; (H * 0.5 - j) * Rv
 *
 */
void	ft_director_vector(t_exec *e, t_player *p, int i, int j)
{
	t_ray	*ray;

	ray = &e->radius.ray[i][j];
	if (p->pos == 'w')
	{
		ray->dir_x = -1;
		ray->dir_y = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		ray->dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
	}
	else if (p->pos == 's')
	{
		ray->dir_x = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		ray->dir_y = 1;
		ray->dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
	}
	else if (p->pos == 'n')
	{
		ray->dir_x = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		ray->dir_y = -1;
		ray->dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
	}
	else if (p->pos == 'e')
	{
		ray->dir_x = 1;
		ray->dir_y = ((i - WIN_SIZE_SCALE * 0.5) * e->s.rh);
		ray->dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
	}
	ft_normalize(ray);
}

void	ft_director_vector2(t_exec *e, int i, int j)
{
	t_ray	*ray;
	double	normalize;

	ray = &e->radius.ray[i][j];
	ray->dir_x = (i - WIN_SIZE_SCALE * 0.5) * e->s.rh;
	ray->dir_y = -1.0;
	ray->dir_z = (WIN_SIZE_SCALE * 0.5 - j) * e->s.rv;
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
 * @brief `rotate in place`
 *
 * p.29 : rotation matrix z
 *
 * cos𝜃	-sin𝜃	0
 * sin𝜃	cos𝜃	0
 * 0		0	  1
 *
 */
void	ft_rotate(t_exec *e, int i, int j)
{
	t_ray	base;
	t_ray	rotated;

	base = e->radius.ray[i][j];
	rotated.dir_x = base.dir_x * cos(e->player.angle)
		- base.dir_y * sin(e->player.angle);
	rotated.dir_y = base.dir_x * sin(e->player.angle)
		+ base.dir_y * cos(e->player.angle);
	rotated.dir_z = base.dir_z;
	e->player.dir_x = rotated.dir_x;
	e->player.dir_y = rotated.dir_y;
	e->player.dir_z = rotated.dir_z;
}

/**
 * @brief `move back and forth`
 */
void	ft_move(t_exec *e, int i, int j)
{
	(void)i;
	(void)j;
	e->s.cx = e->s.cx + e->player.dir_x * e->player.moove;
	e->s.cy = e->s.cy + e->player.dir_y * e->player.moove;
	e->player.moove = 0;
	// e->s.cx = e->s.cx + e->radius.ray[i][j].dir_x * e->player.moove;
	// e->s.cy = e->s.cy + e->radius.ray[i][j].dir_y * e->player.moove;
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
