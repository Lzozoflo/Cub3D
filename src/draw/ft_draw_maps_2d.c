/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:01:22 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/21 15:21:33 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include "ft_define.h"
#include <math.h>

// void	ft_draw_circle(t_data *data, int cx, int cy, int radius)
// {
// 	int	x;
// 	int	y;

// 	y = -radius;
// 	while (y <= radius)
// 	{
// 		x = -radius;
// 		while (x <= radius)
// 		{
// 			if (x * x + y * y <= radius * radius)
// 				ft_color_pixel(PX_GRAY, cx + x, cy + y, data);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	ft_draw_square_px(t_data *data, int c)
// {
// 	const int	color = ft_color_for_square_px(c);
// 	int			i;
// 	int			j;
// 	int			size = 20; // taille du carré à tester

// 	j = 0;
// 	while (j < size)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			ft_color_pixel(color, j, i, data);
// 			i++;
// 		}
// 		j++;
// 	}
// }



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

// void	ft_draw_circle(t_data *data, int cx, int cy, int radius)
// {
// 	int	x;
// 	int	y;

// 	y = -radius;
// 	while (y <= radius)
// 	{
// 		x = -radius;
// 		while (x <= radius)
// 		{
// 			if (x * x + y * y <= radius * radius)
// 				ft_color_pixel(PX_GRAY, cx + x, cy + y, data);
// 			x++;
// 		}
// 		y++;
// 	}
// }


void	ft_draw_square_px(t_data *data, t_draw_minimap d_mini, t_minimap mini)
{
	const char	**t = (const char **)data->exec.tab;
	const int	color = ft_color_map_tile_px(t[d_mini.y][d_mini.y]);
	int			y;
	int			x;

	y = 0;
	while (y < mini.tile_size)
	{
		x = 0;
		while (x < mini.tile_size)
		{
			// if (d_mini.px_y + y >= mini.px_y_x_min && d_mini.px_x + x >= mini.px_y_x_min)
				ft_color_pixel(color, d_mini.px_x + x, d_mini.px_y + y, data);
			x++;
		}
		y++;
	}
}

void ft_draw_map_tile(t_data *data, t_exec *exec, t_minimap *mini, t_player *p)
{
	const int	tile_size = mini->tile_size;
	int			px_x;
	int			px_y;
	int			x;
	int			y;

	t_minimap_set(&exec->mini, p);
	y = mini->tile_start_y;
	px_y = mini->px_y_x_min;
	while (y < exec->max_height)
	{
		x = mini->tile_start_x;
		px_x = mini->px_y_x_min;
		while (y >= 0 && x <= exec->max_width)
		{
			if (x >= 0)
			{
				ft_draw_square_px(data, t_draw_minimap_set(px_x, px_y,x,y), *mini);
			}
			px_x += tile_size;
			x++;
		}
		px_y += tile_size;
		y++;
	}
}

// 	 (y_start >= 0 && y_start < max_height)
// 	 (x_start >= 0 && x_start < max_width)
