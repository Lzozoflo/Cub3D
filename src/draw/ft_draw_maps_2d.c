/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:01:22 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/21 10:44:00 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include "ft_define.h"
#include <math.h>


void	t_minimap_set_draw_max(t_minimap *mini, int zoom, int x)
{
	int	base_pos;

	if (zoom == 0)
		base_pos = WIN_SIZE * 0.015;
	else if (zoom == 1)
		base_pos = WIN_SIZE * 0.045;
	if (zoom == 0)
	{
		if (!x)
		{
			mini->size = WIN_SIZE * 0.03;
			mini->px_y = base_pos;
		}
		mini->px_x = base_pos;
	}
	else if (zoom == 1)
	{
		if (!x)
		{
			mini->size = WIN_SIZE * 0.1;
			mini->px_y = base_pos;
		}
		mini->px_x = base_pos;
	}
}

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

void	ft_draw_square_px(t_minimap mini, t_data *data, int c)
{
	const int	color = ft_color_for_square_px(c);
	int			i;
	int			j;

	j = 0;
	while (j < mini.size)
	{
		i = 0;
		while (i < mini.size)
		{
			ft_color_pixel(color, mini.px_x + i, mini.px_y + j, data);
			i++;
		}
		j++;
	}
}

static void	ft_draw_map(t_data *data, int y_start, int x_start, t_exec *exec)
{
	const char	*str = (const char *)exec->tab[y_start];
	const int	max_width = exec->max_width;
	t_minimap		*mini;
	int			i;

	i = 9;
	mini = &exec->mini;
	while (y_start >= 0 && i-- && x_start < max_width)
	{
		if (x_start >= 0 && x_start < max_width)
		{
			ft_draw_square_px(*mini, data, str[x_start]);
		}
		mini->px_x += mini->size;
		x_start++;
	}
	t_minimap_set_draw_max(mini, exec->zoom, 1);
	mini->px_y += mini->size;
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
	t_minimap_set_draw_max(&exec->mini, exec->zoom, 0);
	x_start = floor(exec->player.pos_x) - 4;
	y_start = floor(exec->player.pos_y) - 4;
	while (i-- && y_start < exec->max_height)
	{
		ft_draw_map(data, y_start, x_start, exec);
		y_start++;
	}
	t_minimap_set_draw_max(&exec->mini, exec->zoom, 0);
	i = exec->mini.size * 4.5;
	y_start = exec->mini.px_y + i;
	x_start = exec->mini.px_x + i;
	if (exec->zoom == 1)
		ft_draw_circle(data, x_start, y_start, exec->mini.size >> 1);
	else if (exec->zoom == 0)
		ft_draw_circle(data, x_start, y_start, exec->mini.size >> 1);
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
