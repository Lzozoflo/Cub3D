/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/05 12:24:25 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

/**@brief `begining of graphic and maths part`
 *
 * ft_fov_h_and_v_ratio : horizontal and vertical distance
 * between radius + fov (p.11 and p.13)
 *
 * ft_group_all_planes : create all possible planes (p.30)
 *
 * ft_director_vector : calculate radius. (p.15)
 *
 * ft_choose_t : calculate t (distance between us and wall)
 * and recover color to print pixel (p.25 and p.30)
 *
*/
int	ft_start(t_exec *e, t_data *d)
{
	int			y;
	int			x;

	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	if (ft_init_plane(e) == -1)
	{
		ft_free_cardi(e);
		return (-1);
	}
	ft_group_all_planes(d);
	if (ft_init_textures(d) == -1)
		return (-1);
	y = 0;
	while (y < WIN_SIZE)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			ft_move_l_r(e);
			ft_move_f_b(e);
			ft_director_vector(e, y, x);
			ft_walls(d, y, x);
			x++;
		}
		y++;
	}
	ft_free_cardi(e);
	return (1);
}
