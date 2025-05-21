/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:01:22 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/21 10:29:37 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include "ft_define.h"
#include <math.h>

static inline int	ft_color_for_square_px(int c)
{
	if (c == '1')
		return (PX_REDO);
	else if (c == '0')
		return (PX_GREEN);
	else if (ft_is_player_char(c))
		return (PX_BLUE);
	return (0);
}

void	ft_draw_square_px(t_minimap pos, t_data *data, int c)
{
	const int	color = ft_color_for_square_px(c);
	int			i;
	int			j;

	j = 0;
	while (j < pos.size)
	{
		i = 0;
		while (i < pos.size)
		{
			ft_color_pixel(color, pos.px_x + i, pos.px_y + j, data);
			i++;
		}
		j++;
	}
}

static void	ft_draw_map(t_data *data, int y_start, int x_start, t_exec *exec)
{
	const char	*str = (const char *)exec->tab[y_start];
	const int	max_width = exec->max_width;
	t_minimap		*pos;
	int			i;

	i = 9;
	pos = &exec->pos;
	while (y_start >= 0 && i-- && x_start < max_width)
	{
		if (x_start >= 0 && x_start < max_width)
		{
			ft_draw_square_px(*pos, data, str[x_start]);
		}
		pos->px_x += pos->size;
		x_start++;
	}
	t_minimap_set_draw_max(pos, exec->zoom, 1);
	pos->px_y += pos->size;
}

void	ft_draw_circle(t_data *data, int cx, int cy, int radius)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				ft_color_pixel(PX_GRAY, cx + x, cy + y, data);
			x++;
		}
		y++;
	}
}

void	ft_draw_map_tile(t_data *data)
{
	t_exec	*exec;
	int		y_start;
	int		x_start;
	int		i;

	i = 9;
	exec = &data->exec;
	t_minimap_set_draw_max(&exec->pos, exec->zoom, 0);
	x_start = floor(exec->player.pos_x) - 4;
	y_start = floor(exec->player.pos_y) - 4;
	while (i-- && y_start < exec->max_height)
	{
		ft_draw_map(data, y_start, x_start, exec);
		y_start++;
	}
	t_minimap_set_draw_max(&exec->pos, exec->zoom, 0);
	i = exec->pos.size * 4.5;
	y_start = exec->pos.px_y + i;
	x_start = exec->pos.px_x + i;
	if (exec->zoom == 1)
		ft_draw_circle(data, x_start, y_start, exec->pos.size >> 1);
	else if (exec->zoom == 0)
		ft_draw_circle(data, x_start, y_start, exec->pos.size >> 1);
}

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
