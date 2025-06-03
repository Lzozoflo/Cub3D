/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 14:05:51 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

void	ft_move_f_b(t_exec *e)
{
	e->s.cx = e->s.cx + e->player.dir_x * e->player.moove;
	e->s.cy = e->s.cy + e->player.dir_y * e->player.moove;
	e->player.moove = 0;
}

int	ft_start(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	ft_north_and_south_walls(d, d->exec.tab);
	ft_east_and_west_walls(d, d->exec.tab);
	ft_init_point(e);
	if (ft_init_textures(d) == -1)
		return (-1);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_director_vector(e, i, j);
			ft_move_l_r(e);
			ft_move_f_b(e);
			ft_choose_t(d, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
