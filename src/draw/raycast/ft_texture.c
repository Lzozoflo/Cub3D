/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:58:58 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/23 08:23:54 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <math.h>

/**
 * @brief
 *
 * p.32 : "The ratios thus selected will only have to be multiplied
 * by respectively the width and height of the texture to have the
 * coordinate of the box where to find the color in the texture image."
 *
 * d->exec.texture.east.width - 1 - coord_x;
 *
 * y = d->exec.texture.west.height - 1 - coord_y;
 *
 * else pixel are inverted
 */
static int	ft_north_south_textures_color(t_data *d, char c, double x, double y)
{
	int	color;
	int	index;
	int	coord_x;

	color = 0;
	if (c == 'n')
	{
		y = d->exec.texture.north.height - 1
			- floor(y * d->exec.texture.north.height);
		x = d->exec.texture.north.width - 1
			- floor(x * d->exec.texture.north.width);
		index = ((y * d->exec.texture.north.line_len)
				+ (x * d->exec.texture.north.bpp));
		color = *(unsigned int *)(d->exec.texture.north.addr + index);
	}
	else if (c == 's')
	{
		coord_x = floor(x * d->exec.texture.south.width);
		y = d->exec.texture.south.height - 1
			- floor(y * d->exec.texture.south.height);
		index = ((y * d->exec.texture.south.line_len)
				+ (coord_x * d->exec.texture.south.bpp));
		color = *(unsigned int *)(d->exec.texture.south.addr + index);
	}
	return (color);
}

/**
 * @brief
 *
 * p.32 : "The ratios thus selected will only have to be multiplied
 * by respectively the width and height of the texture to have the
 * coordinate of the box where to find the color in the texture image."
 *
 * d->exec.texture.east.width - 1 - coord_x;
 *
 * y = d->exec.texture.west.height - 1 - coord_y;
 *
 * else pixel are inverted
 */
static int	ft_east_west_textures_color(t_data *d, char c, double x, double y)
{
	int	color;
	int	index;
	int	coord_x;

	color = 0;
	if (c == 'e')
	{
		coord_x = d->exec.texture.east.width - 1
			- floor(x * d->exec.texture.east.width);
		y = d->exec.texture.east.height - 1
			- floor(y * d->exec.texture.east.height);
		index = ((y * d->exec.texture.east.line_len)
				+ (coord_x * d->exec.texture.east.bpp));
		color = *(unsigned int *)(d->exec.texture.east.addr + index);
	}
	else if (c == 'w')
	{
		coord_x = floor(x * d->exec.texture.west.width);
		y = d->exec.texture.west.height - 1
			- floor(y * d->exec.texture.west.height);
		index = ((y * d->exec.texture.west.line_len)
				+ (coord_x * d->exec.texture.west.bpp));
		color = *(unsigned int *)(d->exec.texture.west.addr + index);
	}
	return (color);
}

/**
 * @brief `add texture to color`
 *
 * p.32 : "Just take the decimal part of the intersection point.
 *
 * For the x axis, the decimal parts to take are those of Ix and Iz.
 *
 * For the y axis, the decimal parts to take are those of Iy and Iz.""
 *
 * floor() recover the entire part, for exemple floor(3.14) = 3
 *
 * -----------------------------------------------
 *
 * The ratios thus selected will only have to be multiplied by
 * respectively the width and height of the texture to have
 * the coordinate of the box where to find the color in the texture image.
 */
int	ft_texture(t_data *d, char c)
{
	double	x;
	double	y;
	int		color;

	if (c == 'n' || c == 's')
	{
		x = d->exec.s.ix - floor(d->exec.s.ix);
		y = d->exec.s.iz - floor(d->exec.s.iz);
	}
	else
	{
		x = d->exec.s.iy - floor(d->exec.s.iy);
		y = d->exec.s.iz - floor(d->exec.s.iz);
	}
	color = ft_north_south_textures_color(d, c, x, y);
	if (color == 0)
		color = ft_east_west_textures_color(d, c, x, y);
	return (color);
}
