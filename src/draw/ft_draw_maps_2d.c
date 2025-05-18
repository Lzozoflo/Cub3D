/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:01:22 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 11:52:15 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"
#include <math.h>


static void	ft_color_pixel(int color, int x, int y, t_data *data)
{
	t_image	img;
	int		index;

	if (x < 0 || y < 0 || x >= WIN_SIZE || y >= WIN_SIZE)
		return ;
	img = data->img;
	index = (y * img.line_len) + (x * (img.bpp));
	*(unsigned int *)(data->img.addr + index) = color;
}

static int	ft_color_for_square_px(int c)
{
	if (c == '1')
		return (COULEUR_1O);
	else if (c == '0')
		return (COULEUR_0);
	else if (ft_is_player_char(c))
		return (COULEUR_BLUE);
	return (0);
}


void	ft_draw_square_px(t_pos pos, t_data *data, int c)
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

void	ft_draw_map_2d(t_data *data, int zoom)
{//manefunc
	const char	**tab = (const char **)data->exec.tab;
	t_pos		pos;
	int			x_start;
	int			y_start;

	y_start = round(data->exec.player.pos_y) - 4;
	t_pos_set_draw_max(&pos, zoom, 0);
	while (pos.while_y--)
	{
		x_start = round(data->exec.player.pos_x) - 4;
		while (y_start >= 0 && pos.while_x--)
		{
			if (x_start >= 0)
				ft_draw_square_px(pos, data, tab[y_start][x_start]);
			pos.px_x += pos.size;
			x_start++;
		}
		t_pos_set_draw_max(&pos, zoom, 1);
		pos.px_y += pos.size;
		y_start++;
	}
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
