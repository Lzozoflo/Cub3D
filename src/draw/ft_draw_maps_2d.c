/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_maps_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 08:01:22 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/23 12:45:52 by fcretin          ###   ########.fr       */
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


void ft_draw_minimap_pixels_centered(t_data *data, t_minimap *m, t_player  *p)
{
    const char **tab = (const char **)data->exec.tab;
    int ts    = m->tile_size;
    int wmin  = m->win_xy_min;
    int wmax  = m->win_xy_max;
	double	div = 1.0 / (double)ts;
    double center = (wmin + wmax) * 0.5;

    // offset FLOAT qu’on doit appliquer pour que le joueur soit à “center”
    double offset_x = center - ((p->pos_x - m->tab_start_x) * ts);
    double offset_y = center - ((p->pos_y - m->tab_start_y) * ts);

    for (int py = wmin; py < wmax; py++)
    {
		double world_y = (py - offset_y) * div;
		int tile_y = (int)floor(world_y) + m->tab_start_y;
        for (int px = wmin; px < wmax && !(tile_y < 0 || tile_y > m->tab_end_y); px++)
        {
            // calcul “monde” en float puis floor → tuile
            double world_x = (px - offset_x) * div;
            int tile_x = (int)floor(world_x) + m->tab_start_x;

            // si hors de la map, on saute
            if (tile_x < 0 || tile_x > m->tab_end_x)
                continue;

            int color = ft_color_map_tile_px(tab[tile_y][tile_x]);
			if (color != 0)
            	ft_color_pixel(color, px, py, data);
        }
    }
}

void ft_draw_minimap_pixels_centered(t_data *data,
                                     t_minimap *m,
                                     t_player  *p)
{
    const char **tab = (const char **)data->exec.tab;
    int ts    = m->tile_size;
    int wmin  = m->win_xy_min;
    int wmax  = m->win_xy_max;
	double	div = 1.0 / (double)ts;
    // centre exact (float) de la zone de dessin
    double center = (wmin + wmax) * 0.5;

    // (re)calcule ton plan de tuiles autour du joueur
    // t_minimaps_set(m, p, m->zoom);

    // position RELATIVE du joueur (en px, float) par rapport à tab_start
    double rel_px_x_player = (p->pos_x - m->tab_start_x) * ts;
    double rel_px_y_player = (p->pos_y - m->tab_start_y) * ts;

    // offset FLOAT qu’on doit appliquer pour que le joueur soit à “center”
    double offset_x = center - rel_px_x_player;
    double offset_y = center - rel_px_y_player;

    for (int py = wmin; py < wmax; py++)
    {
		double world_y = (py - offset_y) * div;
		int tile_y = (int)floor(world_y) + m->tab_start_y;
        for (int px = wmin; px < wmax && !(tile_y < 0 || tile_y > m->tab_end_y); px++)
        {
            // calcul “monde” en float puis floor → tuile
            double world_x = (px - offset_x) * div;

            int tile_x = (int)floor(world_x) + m->tab_start_x;

            // si hors de la map, on saute
            if (tile_x < 0 || tile_x > m->tab_end_x)
                continue;

            int color = ft_color_map_tile_px(tab[tile_y][tile_x]);
			if (color != 0)
            	ft_color_pixel(color, px, py, data);
        }
    }
}


// ft_color_pixel(color, d_mini.px_x + x, d_mini.px_y + y, data);
void ft_draw_map_tile(t_data *data, t_exec *exec, t_minimap *m, t_player *p)
{
	int			px_y;
	int			px_x;
	int			x;
	int			y;
	(void)exec;

	t_minimaps_set(m, p, m->zoom);
	y = m->tab_start_y;
	px_y = m->tab_px_y_min;
	// printf("tile %d diff1 %d\t diff2 %d\n", m->tile_size,m->tab_px_x_min % m->tile_size,m->tab_px_y_min - m->win_xy_min);
	while (y <= m->tab_end_y && y < exec->max_height)
	{
		x = m->tab_start_x;
		px_x = m->tab_px_x_min;
		while (y >= 0 && x <= m->tab_end_x && x < exec->max_width)
		{
			if (x >= 0)
			{
				ft_draw_minimap_pixels_centered(data, m, p);
				// ft_draw_minimap_pixels(data, m);
				// ft_draw_square_px(data, t_draw_minimap_set(px_x, px_y, x, y), *m);
			}
			px_x += m->tile_size;
			x++;
		}
		px_y += m->tile_size;
		y++;
	}
}
