/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 16:29:06 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <stdlib.h>
#include <math.h>

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
	ft_init_camera(e);
	if (ft_rotate_radius(e) == -1)
		return (-1);
	ft_move(e);
	while (i < (WIN_SIZE / SCALE))
	{
		j = 0;
		while (j < (WIN_SIZE / SCALE))
		{
			radius = e->all_r.ray[i][j];	// mlx_mouse_hook(data->win, NULL, data);
			ft_walls(d, i, j, radius);
			j++;
		}
		i++;
	}
	return (1);
}
