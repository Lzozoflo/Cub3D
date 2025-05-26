/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:48:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/26 09:22:52 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>


void	t_minimap_set_plane(t_minimap *m, double pos_x, double pos_y, int ts)
{
	m->tab_start_x = floor(pos_x) - 4;
	m->tab_start_y = floor(pos_y) - 4;
	m->tab_end_x = ceil(pos_x) + 4;
	m->tab_end_y = ceil(pos_y) + 4;
	m->div = 1.0 / (double)ts;
	m->center = (m->win_xy_min + m->win_xy_max) * 0.5;
	m->offset_x = m->center - ((pos_x - m->tab_start_x) * (double)ts);
	m->offset_y = m->center - ((pos_y - m->tab_start_y) * (double)ts);
}

void	t_minimaps_set(t_minimap *mini, t_player *p, int zoom)
{
	int	size_tile;

	if (zoom == 0)
	{
		size_tile = WIN_SIZE * 0.03;
		mini->tile_size = size_tile;
	}
	else
	{
		size_tile = WIN_SIZE * 0.1;
		mini->tile_size = size_tile;
	}
	mini->win_xy_min = size_tile * 0.5;
	mini->win_xy_max = mini->tile_size * 9.5;
	t_minimap_set_plane(mini, p->pos_x, p->pos_y, size_tile);
}
