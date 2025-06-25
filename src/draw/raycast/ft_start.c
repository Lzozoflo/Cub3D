/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/25 15:52:56 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <stdlib.h>
#include <math.h>

static void	ft_free_rotate_ray(t_radius *all_r, int i)
{
	while (i > 0)
	{
		free(all_r->ray[i]);
		all_r->ray[i] = NULL;
		i--;
	}
	free(all_r->ray);
	all_r->ray = NULL;
}

static int	ft_init_rotate_radius(t_exec *e, int win_scale)
{
	int		i;

	i = 0;
	e->all_r.ray = malloc(sizeof(t_ray *) * win_scale);
	if (e->all_r.ray == NULL)
		return (-1);
	while (i < win_scale)
	{
		e->all_r.ray[i] = malloc(sizeof(t_ray) * win_scale);
		if (e->all_r.ray[i] == NULL)
		{
			ft_free_rotate_ray(&e->all_r, i);
			return (-1);
		}
		i++;
	}
	return (0);
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
	ft_fov_h_and_v_ratio(e, d->win_scale);
	if (ft_calculate_all_radius(e, d->win_scale) == -1)
	{
		ft_clean_close(d, 1);
		return (-1);
	}
	if (ft_init_plane(e) == -1)
	{
		ft_clean_close(d, 1);
		return (-1);
	}
	ft_group_all_planes(d);
	if (ft_init_textures(d) == -1)
	{
		ft_clean_close(d, 1);
		return (-1);
	}
	if (ft_init_rotate_radius(e, d->win_scale) == -1)
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
void	ft_start(t_exec *e, t_data *d)
{
	const int		win_scale = d->win_scale;
	int				i;
	int				j;
	t_ray			radius;

	i = 0;
	j = 0;
	ft_init_camera(e);
	ft_rotate_radius(e, win_scale);
	ft_move(e);
	while (i < win_scale)
	{
		j = 0;
		while (j < win_scale)
		{
			radius = e->all_r.ray[i][j];
			ft_walls(d, i, j, radius);
			j++;
		}
		i++;
	}
}
