/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:58:58 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/05 12:59:01 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>
#include <unistd.h>

static void	ft_color_texture(const t_image *img, t_u_texture *u)
{
	u->coord_x = floor(u->x * img->width);
	u->coord_y = floor(u->y * img->height);
	u->y = img->height - 1 - u->coord_y;
	u->index = ((u->y * img->line_len)
			+ (u->coord_x * (img->bpp)));
	u->color = *(unsigned int *)(img->addr + u->index);
}

/**
 * @brief
 *
 * t->height - 1 - coord_y because else pixel are inverted
 */
static void	ft_search_color_texture(t_data *d, t_u_texture *u)
{
	if (u->c == 'n')
	{
		ft_color_texture(&d->exec.texture.north, u);
	}
	else if (u->c == 's')
	{
		ft_color_texture(&d->exec.texture.south, u);
	}
	else if (u->c == 'e')
	{
		ft_color_texture(&d->exec.texture.east, u);
	}
	else
	{
		ft_color_texture(&d->exec.texture.west, u);
	}
}

/**
 * @brief `add texture to color`
 *
 * p.32 : Just take the decimal part of the intersection point.
 *
 * For the x axis, the decimal parts to take are those of Ix and Iz.
 *
 * For the y axis, the decimal parts to take are those of Iy and Iz.
 *
 * floor() recover the entire part, for exemple floor(3.14) = 3
 *
 * -----------------------------------------------
 *
 * The ratios thus selected will only have to be multiplied by
 * respectively the width and height of the texture to have
 * the coordinate of the box where to find the color in the texture image.
 */
void	ft_texture(t_data *d, t_u_texture *u)
{

	if (u->c == 'n' || u->c == 's')
	{
		u->x = d->exec.s.ix - floor(d->exec.s.ix);
		u->y = d->exec.s.iz - floor(d->exec.s.iz);
	}
	else
	{
		u->x = d->exec.s.iy - floor(d->exec.s.iy);
		u->y = d->exec.s.iz - floor(d->exec.s.iz);
	}
	return (ft_search_color_texture(d, u));
}
