/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 12:03:37 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <stdlib.h>
#include <math.h>

/**
 * @brief `calculate all radius for opti`
 *
 * `(p.15) - double loop` :"To create our direction vectors,
 * we simply need to put an increment on the x (which we will call i)
 * and another for the y (j)."
 *
 * `(p.30) - Radius precalculation`
 * "First, it is very important to calculate the radii beforehand.
 * As shown here, radii can be calculated before the graph loop.
 * We therefore create them with a North orientation and then simply
 * turn the ray towards our direction just before using it in the algorithm.
 * This saves all the creation time during the loop."
 */
int	ft_calculate_all_radius(t_exec *e)
{
	int	i;
	int	j;

	i = 0;
	e->radius.ray = NULL;
	e->radius.ray = malloc(sizeof(t_ray *) * WIN_SIZE_SCALE);
	if (e->radius.ray == NULL)
		return (-1);
	while (i < WIN_SIZE_SCALE)
	{
		e->radius.ray[i] = malloc(sizeof(t_ray) * WIN_SIZE_SCALE);
		j = 0;
		while (j < WIN_SIZE_SCALE)
		{
			//ft_director_vector2(e, i, j);
			ft_director_vector(e, &e->player, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free_radius(t_radius *r)
{
	int	i;

	if (r->ray)
		return ;
	i = 0;
	while (i < WIN_SIZE_SCALE)
	{
		if (r->ray[i])
			free(r->ray[i]);
		i++;
	}
	free(r->ray);
	r->ray = NULL;
}

/**
 * @brief `init param`
 *
 *
 * `(p.11 and p.13) - ft_fov_h_and_v_ratio` : horizontal and vertical distance
 * between radius + fov
 *
 * `(p.30) - ft_init_plane & ft_group_all_planes` : create all possible planes
 */
int	ft_init_start(t_exec *e, t_data *d)
{
	ft_fov_h_and_v_ratio(e);
	if (ft_calculate_all_radius(e) == -1)
		return (-1);
	if (ft_init_plane(e) == -1)
	{
		ft_free_radius(&e->radius);
		ft_free_cardi(e);
		return (-1);
	}
	ft_group_all_planes(d);
	if (ft_init_textures(d) == -1)
		return (-1);
	return (0);
}

/**@brief `begining of graphic and maths part`
 *
 * `(p.17) - ft_init_camera`
 *
 * `(p.29) - ft_move_l_r : z rotation matrix`
 *
 * `X - ft_move_f_b`
 *
 * `X - ft_walls`
 *
*/
int	ft_start(t_exec *e, t_data *d)
{
	int		i;
	int		j;
	t_ray	radius;

	i = 0;
	j = 0;
	ft_draw_sky_floor_shadow(d);
	ft_init_camera(e);
	ft_move(e);
	while (i < WIN_SIZE_SCALE)
	{
		j = 0;
		while (j < WIN_SIZE_SCALE)
		{
			radius = ft_rotate(e, i, j);
			ft_walls(d, i, j, radius);
			j++;
		}
		i++;
	}
	return (1);
}
