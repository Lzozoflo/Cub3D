/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:02:50 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 16:07:09 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

static void	ft_draw_sky(t_data *data)
{
	size_t				y;
	int					x;
	const size_t		half = WIN_SIZE >> 1;
	const unsigned int	colorsky = data->exec.sky;

	x = 0;
	y = 0;
	while (y < half)
	{
		while (x < WIN_SIZE)
		{
			ft_color_pixel(colorsky, x, y, data);
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_color_shadow_floor(const unsigned int colorfloor, size_t y,
		const size_t half)
{
	int		r;
	int		g;
	int		b;
	int		shadow_color;
	double	factor;

	factor = ((double)(y - half) / (double)half);
	if (factor > 1.0)
		factor = 1.0;
	r = (colorfloor / 0x10000) * factor;
	g = ((colorfloor / 0x100) % 0x100) * factor;
	b = (colorfloor % 0x100) * factor;
	shadow_color = (r * 0x10000) + (g * 0x100) + b;
	return (shadow_color);
}

int	ft_color_shadow_ceiling(const unsigned int colorceiling, size_t y, const size_t half)
{
	int		r;
	int		g;
	int		b;
	int		shadow_color;
	double	factor;

	factor = ((double)(half - y) / (double)half);
	if (factor > 1.0)
		factor = 1.0;
	r = (colorceiling / 0x10000) * factor;
	g = ((colorceiling / 0x100) % 0x100) * factor;
	b = (colorceiling % 0x100) * factor;
	shadow_color = (r * 0x10000) + (g * 0x100) + b;
	return (shadow_color);
}

/**
 * @brief `opti with shadow`
 *
 * `(p.37) - Twilight`
 *
 * "The darkness which is easily installable is that
 * linked to the player's viewing distance.
 * It is thus possible to darken the decor by moving away from the player.
 * Simply put, the further something is from the camera,
 * the darker it is and the less we see it.
 * In addition to accentuating the realism of the scene,
 * this makes it possible to no longer
 * calculate everything that is beyond the limit where
 * we no longer see anything and everything is black.
 *
 * Note: Remember to normalize the ray vectors when creating
 * so that t represents the distance with the intersection afterwards."
 */
void	ft_draw_sky_floor_shadow(t_data *data)
{
	const unsigned int	colorfloor = data->exec.floor;
	const size_t		half = WIN_SIZE >> 1;
	size_t				y;
	int					x;
	int					shadow_color;

	ft_draw_sky(data);
	y = half;
	while (y < WIN_SIZE)
	{
		shadow_color = ft_color_shadow_floor(colorfloor, y, half);
		x = 0;
		while (x < WIN_SIZE)
		{
			ft_color_pixel(shadow_color, x, y, data);
			x++;
		}
		y++;
	}
}

/**
 * @brief `opti with shadow`
 *
 * `(p.37) - Twilight`
 *
 * "The darkness which is easily installable is that
 * linked to the player's viewing distance.
 * It is thus possible to darken the decor by moving away from the player.
 * Simply put, the further something is from the camera,
 * the darker it is and the less we see it.
 * In addition to accentuating the realism of the scene,
 * this makes it possible to no longer
 * calculate everything that is beyond the limit where
 * we no longer see anything and everything is black.
 *
 * Note: Remember to normalize the ray vectors when creating
 * so that t represents the distance with the intersection afterwards."
 */
int	ft_shadow(int color, t_data *d)
{
	int		r;
	int		g;
	int		b;
	double	factor;

		factor = 1.0 - (d->exec.wall.t_min / MAX_D);
		if (factor < 0.0)
			factor = 0.0;
		r = color / 0x10000;
		g = (color / 0x100) % 0x100;
		b = color % 0x100;
		r = r * factor;
		g = g * factor;
		b = b * factor;
		color = (r * 0x10000) + (g * 0x100) + b;
	return (color);
}
