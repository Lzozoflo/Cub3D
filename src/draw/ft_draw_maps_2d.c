/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:01:22 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/16 14:26:41 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include "ft_define.h"
#include <math.h>

static inline unsigned int	ft_color_map_tile_px(int c, t_minimap *m)
{
	if (c == '0')
		return (m->color_minimap[0]);
	else if (c == '1')
		return (m->color_minimap[1]);
	else if (ft_is_player_char(c))
		return (m->color_minimap[2]);
	return (0);
	// if (c == '1')
	// 	return (PX_REDO);
	// else if (c == '0')
	// 	return (PX_GREEN);
	// else if (ft_is_player_char(c))
	// 	return (PX_BLUE);
	return (0);
}

void	ft_draw_circle(t_data *data, t_minimap *m)
{
	const int	radius = (int)(m->tile_size * RADIUSPLAYER);
	const int	r2 = radius * radius;
	const int	c = (int)m->center;
	int			dy;
	int			dx;

	dy = -radius;
	while (dy <= radius)
	{
		dx = -radius;
		while (dx <= radius)
		{
			if (dx * dx + dy * dy <= r2)
				ft_color_pixel(PX_GRAY_DARK, c + dx, c + dy, data);
			dx++;
		}
		dy++;
	}
}

static void	ft_draw_minimap_x(t_data *data, t_minimap *m, int py, int tile_y)
{
	const char		**tab = (const char **)data->exec.tab;
	const int		wmax = m->win_xy_max;
	int				tile_x;
	unsigned int	color;
	int				px;

	px = m->win_xy_min;
	while (px < wmax)
	{
		tile_x = floor((px - m->offset_x) * m->div) + m->tab_start_x;
		if (tile_x < 0)
		{
			px++;
			continue ;
		}
		if (tile_x >= data->exec.max_width)
			return ;
		color = ft_color_map_tile_px(tab[tile_y][tile_x], m);
		if (color != 0)
			ft_color_pixel(color, px, py, data);
		px++;
	}
}

void	ft_draw_minimap(t_data *data, t_minimap *m)
{
	const int		start_y = m->tab_start_y;
	const double	offy = m->offset_y;
	const int		wmax = m->win_xy_max;
	int				tile_y;
	int				py;

	py = m->win_xy_min;
	while (py < wmax)
	{
		tile_y = floor((py - offy) * m->div) + start_y;
		if (tile_y < 0)
		{
			py++;
			continue ;
		}
		if (tile_y >= data->exec.max_height)
			return ;
		ft_draw_minimap_x(data, m, py, tile_y);
		py++;
	}
}
