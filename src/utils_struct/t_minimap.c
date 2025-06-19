/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:48:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/19 10:29:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

static void	t_minimap_set_plane(t_minimap *m, double x, double y, int ts)
{
	m->tab_start_x = (int)(floor(x)) - 4;
	m->tab_start_y = (int)(floor(y)) - 4;
	m->div = 1.0 / (double)ts;
	m->center = (m->win_xy_min + m->win_xy_max) * 0.5;
	m->offset_x = m->center - ((x - m->tab_start_x) * (double)ts);
	m->offset_y = m->center - ((y - m->tab_start_y) * (double)ts);
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
	mini->win_xy_max = size_tile * 9.5;
	t_minimap_set_plane(mini, p->pos_x, p->pos_y, size_tile);
}
