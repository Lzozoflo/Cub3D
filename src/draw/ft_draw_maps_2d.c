/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:01:22 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/26 09:40:23 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include "ft_define.h"
#include <math.h>

static inline int	ft_color_map_tile_px(int c)
{
	if (c == '1')
		return (PX_REDO);
	else if (c == '0')
		return (PX_GREEN);
	else if (ft_is_player_char(c))
		return (PX_BLUE);
	return (0);
}

void	ft_draw_minimap_x(t_data *data, t_minimap *m, int py, int tile_y)
{
	const char **tab = (const char **)data->exec.tab;
	int	tile_x;
	int	color;
	int	wmax;
	int	px;

	wmax = m->win_xy_max;
	px = m->win_xy_min;
	while (px < wmax)
	{
		tile_x = (int)floor((px - m->offset_x) * m->div) + m->tab_start_x;
		if (tile_x < 0 || tile_x > m->tab_end_x)
			continue ;
		color = ft_color_map_tile_px(tab[tile_y][tile_x]);
		if (color != 0)
			ft_color_pixel(color, px, py, data);
		px++;
	}
}

void	ft_draw_minimap(t_data *data, t_minimap *m, t_player *p)
{
	const int		start_y = m->tab_start_y;
	const double	offy = m->offset_y;
	int				tile_y;
	int				wmax;
	int				py;

	t_minimaps_set(m, p, m->zoom);
	wmax = m->win_xy_max;
	py = m->win_xy_min;
	while (py < wmax)
	{
		tile_y = (int)floor((py - offy) * m->div) + start_y;
		if (!(tile_y < 0 || tile_y > m->tab_end_y))
			ft_draw_minimap_x(data, m, py, tile_y);
		py++;
	}
}
