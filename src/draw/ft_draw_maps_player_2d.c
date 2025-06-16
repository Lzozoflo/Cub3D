/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_player_2d.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:27:42 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/16 14:25:57 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"

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
