/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:31:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 09:22:09 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

int	ft_start(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	if (ft_malloc_cardi(d) == -1) //MUST ADD FREE
		return (-1);
	ft_north_and_south_walls(d, d->exec.tab);
	ft_east_and_west_walls(d, d->exec.tab);
	ft_init_point(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_director_vector(e, i, j);
			ft_move_l_r(e);
			ft_choose_t(d, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
