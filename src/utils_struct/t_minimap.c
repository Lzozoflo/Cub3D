/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:48:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/23 12:26:09 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>


void	t_minimap_set_plane(t_minimap *m, double pos_x, double pos_y, int tile)
{

	// 1plane pos in tab
	//need to know the charatere to draw the right color when its negatif we just skip it
	m->tab_start_x = floor(pos_x) - 4;
	m->tab_start_y = floor(pos_y) - 4;
	m->tab_end_x = ceil(pos_x) + 4;
	m->tab_end_y = ceil(pos_y) + 4;
	m->tab_px_x_min = round((pos_x - 4.0) * (double)tile);
	m->tab_px_y_min = round((pos_y - 4.0) * (double)tile);
	m->tab_px_x_max = round((pos_x + 4.0) * (double)tile);
	m->tab_px_y_max = round((pos_y + 4.0) * (double)tile);
	// printf("tab_px_y_min%d\ttab_px_x_min %d\n", m->tab_px_y_min,m->tab_px_x_min);
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
	// 3plane
	mini->win_xy_min = size_tile * 0.5;
	mini->win_xy_max = mini->tile_size * 9.5;
	t_minimap_set_plane(mini, p->pos_x, p->pos_y, size_tile);
	// printf("win_xy_min %d\twin_xy_max%d\n",mini->win_xy_min, mini->win_xy_max);
}

t_draw_minimap	t_draw_minimap_set(int px_x, int px_y, int x, int y)
{
	t_draw_minimap tmp;

	tmp.px_x = px_x;
	tmp.px_y = px_y;
	tmp.x = x;
	tmp.y = y;
	return (tmp);
}
