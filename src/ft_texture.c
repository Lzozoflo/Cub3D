/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:58:58 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 15:41:54 by mlaussel         ###   ########.fr       */
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
static int	ft_color_texture(t_data *d, char c, int coord_x, int coord_y)
{
	int	color;

	int	y;

	y = d->exec.texture.height - 1 - coord_y;
	if (c == 'n')
		color = d->exec.texture.data_no[y * d->exec.texture.width
			+ coord_x];
	else if (c == 's')
		color = d->exec.texture.data_so[y * d->exec.texture.width
			+ coord_x];
	else if (c == 'e')
		color = d->exec.texture.data_ea[y * d->exec.texture.width
			+ coord_x];
	else
		color = d->exec.texture.data_we[y * d->exec.texture.width
			+ coord_x];
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
	int		coord_x;
	int		coord_y;

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
	coord_x = (int)(x * d->exec.texture.width);
	coord_y = (int)(y * d->exec.texture.height);
	color = ft_color_texture(d, c, coord_x, coord_y);
	return (color);
}



int	ft_init_textures_e_w(t_data *d)
{
	int	bpp;
	int	line_len;
	int	endian;

	d->exec.texture.texture_ea = mlx_xpm_file_to_image(d->mlx,
			"./textures/east.xpm", &d->exec.texture.width,
			&d->exec.texture.height);
	if (!d->exec.texture.texture_ea)
	{
		write(2, "Error loading east.xpm\n", 23);
		return (-1);
	}
	d->exec.texture.data_ea = (int *)mlx_get_data_addr(
			d->exec.texture.texture_ea, &bpp, &line_len, &endian);
	d->exec.texture.texture_we = mlx_xpm_file_to_image(d->mlx,
			"./textures/west.xpm", &d->exec.texture.width,
			&d->exec.texture.height);
	if (!d->exec.texture.texture_we)
	{
		write(2, "Error loading north.xpm\n", 23);
		return (-1);
	}
	d->exec.texture.data_we = (int *)mlx_get_data_addr(
			d->exec.texture.texture_we, &bpp, &line_len, &endian);
	return (1);
}

int	ft_init_textures(t_data *d)
{
	int	bpp;
	int	line_len;
	int	endian;

	d->exec.texture.texture_no = mlx_xpm_file_to_image(d->mlx,
			"./textures/north.xpm", &d->exec.texture.width,
			&d->exec.texture.height);
	if (!d->exec.texture.texture_no)
	{
		write(2, "Error loading north.xpm\n", 24);
		return (-1);
	}
	d->exec.texture.data_no = (int *)mlx_get_data_addr(
			d->exec.texture.texture_no, &bpp, &line_len, &endian);
	d->exec.texture.texture_so = mlx_xpm_file_to_image(d->mlx,
			"./textures/south.xpm", &d->exec.texture.width,
			&d->exec.texture.height);
	if (!d->exec.texture.texture_so)
	{
		write(2, "Error loading south.xpm\n", 24);
		return (-1);
	}
	d->exec.texture.data_so = (int *)mlx_get_data_addr(
			d->exec.texture.texture_so, &bpp, &line_len, &endian);
	if (ft_init_textures_e_w(d) == -1)
		return (-1);
	return (1);
}
