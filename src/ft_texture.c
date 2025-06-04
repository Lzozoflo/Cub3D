/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:58:58 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/04 11:32:44 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>
#include <unistd.h>

/**
 * @brief
 *
 * d->exec.texture.height - 1 - coord_y because else pixel are inverted
 */
static int	ft_color_texture(t_data *d, char c, double x, double y)
{
	int	color;
	int	index;
	int	coord_x;
	int	coord_y;

	if (c == 'n')
	{
		coord_x = floor(x * d->exec.texture.north.width);
		coord_y = floor(y * d->exec.texture.north.height);
		y = d->exec.texture.north.height - 1 - coord_y;
		index = ((y * d->exec.texture.north.line_len)
				+ (coord_x * (d->exec.texture.north.bpp) / 8));
		color = *(unsigned int *)d->exec.texture.north.addr + index;
	}
	if (c == 's')
	{
		coord_x = floor(x * d->exec.texture.south.width);
		coord_y = floor(y * d->exec.texture.south.height);
		y = d->exec.texture.south.height - 1 - coord_y;
		index = ((y * d->exec.texture.south.line_len)
				+ (coord_x * (d->exec.texture.south.bpp / 8)));
		color = *(unsigned int *)d->exec.texture.south.addr + index;
	}
	if (c == 'e')
	{
		coord_x = floor(x * d->exec.texture.east.width);
		coord_y = floor(y * d->exec.texture.east.height);
		y = d->exec.texture.east.height - 1 - coord_y;
		index = ((y * d->exec.texture.east.line_len)
				+ (coord_x * (d->exec.texture.east.bpp / 8)));
		color =*(unsigned int *)d->exec.texture.east.addr + index;
	}
	else
	{
		coord_x = floor(x * d->exec.texture.west.width);
		coord_y = floor(y * d->exec.texture.west.height);
		y = d->exec.texture.west.height - 1 - coord_y;
		index = ((y * d->exec.texture.west.line_len)
				+ (coord_x * (d->exec.texture.west.bpp / 8)));
		color =*(unsigned int *)d->exec.texture.west.addr + index;
	}
	return (color);
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
	color = ft_color_texture(d, c, x, y);
	return (color);
}


int	ft_init_textures_e_w(t_data *d)
{
	d->exec.texture.east.img_ptr = mlx_xpm_file_to_image(d->mlx,
		"./textures/east.xpm", &d->exec.texture.east.width,
		&d->exec.texture.east.height);
	if (!d->exec.texture.east.img_ptr)
	{
		write(2, "Error loading east.xpm\n", 24);
		return (-1);
	}
	d->exec.texture.east.addr = mlx_get_data_addr(
			d->exec.texture.east.img_ptr, &d->exec.texture.east.bpp,
			&d->exec.texture.east.line_len, &d->exec.texture.east.endian);

	d->exec.texture.west.img_ptr = mlx_xpm_file_to_image(d->mlx,
			"./textures/west.xpm", &d->exec.texture.west.width,
			&d->exec.texture.west.height);
	if (!d->exec.texture.west.img_ptr)
	{
		write(2, "Error loading west.xpm\n", 24);
		return (-1);
	}
	d->exec.texture.west.addr = mlx_get_data_addr(
			d->exec.texture.west.img_ptr, &d->exec.texture.west.bpp,
			&d->exec.texture.west.line_len, &d->exec.texture.west.endian);
	return (1);
}

int	ft_init_textures(t_data *d)
{
	d->exec.texture.north.img_ptr = mlx_xpm_file_to_image(d->mlx,
			"./textures/north.xpm", &d->exec.texture.north.width,
			&d->exec.texture.north.height);
	if (!d->exec.texture.north.img_ptr)
	{
		write(2, "Error loading north.xpm\n", 24);
		return (-1);
	}
	d->exec.texture.north.addr = mlx_get_data_addr(
			d->exec.texture.north.img_ptr, &d->exec.texture.north.bpp,
			&d->exec.texture.north.line_len, &d->exec.texture.north.endian);

	d->exec.texture.south.img_ptr = mlx_xpm_file_to_image(d->mlx,
			"./textures/south.xpm", &d->exec.texture.south.width,
			&d->exec.texture.south.height);
	if (!d->exec.texture.south.img_ptr)
	{
		write(2, "Error loading south.xpm\n", 24);
		return (-1);
	}
	d->exec.texture.south.addr = mlx_get_data_addr(
			d->exec.texture.south.img_ptr, &d->exec.texture.south.bpp,
			&d->exec.texture.south.line_len, &d->exec.texture.south.endian);

	if (ft_init_textures_e_w(d) == -1)
		return (-1);
	return (1);
}
