/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:02:50 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/19 10:18:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

int	ft_color_shadow_floor(const unsigned int colorfloor, int y,
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
	r = (int)((colorfloor / 0x10000) * factor);
	g = (int)(((colorfloor / 0x100) % 0x100) * factor);
	b = (int)((colorfloor % 0x100) * factor);
	shadow_color = (r * 0x10000) + (g * 0x100) + b;
	return (shadow_color);
}

int	ft_color_shadow_ceiling(const unsigned int colorceiling,
	int y, const size_t half)
{
	int		r;
	int		g;
	int		b;
	int		shadow_color;
	double	factor;

	factor = ((double)(half - y) / (double)half);
	if (factor > 1.0)
		factor = 1.0;
	r = (int)((colorceiling / 0x10000) * factor);
	g = (int)(((colorceiling / 0x100) % 0x100) * factor);
	b = (int)((colorceiling % 0x100) * factor);
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
int	ft_shadow(int color, t_data *d)
{
	int		r;
	int		g;
	int		b;
	double	factor;

	factor = 1.0 - (d->exec.wall.t_min / MAX_D);
	if (factor < 0.0)
		factor = 0.0;
	r = (int)((color / 0x10000) * factor);
	g = (int)(((color / 0x100) % 0x100) * factor);
	b = (int)((color % 0x100) * factor);
	color = (r * 0x10000) + (g * 0x100) + b;
	return (color);
}
