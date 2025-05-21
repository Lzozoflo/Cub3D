/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:48:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/21 15:01:04 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include <math.h>

void	t_minimaps_set_size_tile(t_minimap *mini, int zoom)
{
	int	base_pos;

	if (zoom == 0)
	{
		mini->tile_size = WIN_SIZE * 0.03;
		base_pos = WIN_SIZE * 0.015;
		mini->px_y_x_min = base_pos;
	}
	else
	{
		mini->tile_size = WIN_SIZE * 0.1;
		base_pos = WIN_SIZE * 0.045;
		mini->px_y_x_min = base_pos;
	}
	mini->px_y_x_max = base_pos + (mini->tile_size * 9);
}

void	t_minimap_set(t_minimap *mini, t_player *p)
{
	const int	x = floor(p->pos_x);
	const int	y = floor(p->pos_y);

	mini->frac_x = p->pos_y - x;
	mini->frac_y = p->pos_y - y;
	mini->tile_start_x = x - 4;
	mini->tile_start_y = y - 4;
	mini->int_x = x;
	mini->int_y = y;
	t_minimaps_set_size_tile(mini, mini->zoom);
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
