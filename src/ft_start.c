/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/16 12:00:21 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"


#include <stdlib.h> //maybe delete
int	ft_calculate_all_radius(t_exec *e)
{
	int	i;
	int	j;

	i = 0;
	e->radius.ray = NULL;
	e->radius.ray = malloc(sizeof(t_ray *) * WIN_SIZE);
	if (e->radius.ray == NULL)
		return (-1);
	while (i < WIN_SIZE)
	{
		e->radius.ray[i] = malloc(sizeof(t_ray) * WIN_SIZE);
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_director_vector(e, &e->player, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief `init param`
 *
 * `(p.17) - ft_init_camera`
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
		//ft_free_radius() //to create
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
 * `(p.15) - double loop` : "To create our direction vectors,
 * we simply need to put an increment on the x (which we will call i)
 * and another for the y (j)."
 *
 * `(p.29) - ft_move_l_r : z rotation matrix`
 *
 * `X - ft_move_f_b`
 *
 * `(p.15) - ft_director_vector` : calculate radius.
 *
 * `X - ft_walls`
 *
*/
int	ft_start(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_camera(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_move_l_r(e, i , j);
			ft_move_f_b(e, i , j);
			ft_walls(d, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
