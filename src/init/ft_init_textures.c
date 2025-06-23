/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:07:45 by mathildelau       #+#    #+#             */
/*   Updated: 2025/06/23 11:37:08 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <unistd.h>

void	ft_destroy_textures(t_data *d)
{
	if (d->exec.texture.north.img_ptr)
		mlx_destroy_image(d->mlx, d->exec.texture.north.img_ptr);
	if (d->exec.texture.south.img_ptr)
		mlx_destroy_image(d->mlx, d->exec.texture.south.img_ptr);
	if (d->exec.texture.east.img_ptr)
		mlx_destroy_image(d->mlx, d->exec.texture.east.img_ptr);
	if (d->exec.texture.west.img_ptr)
		mlx_destroy_image(d->mlx, d->exec.texture.west.img_ptr);
}

static void	ft_cal_texture(t_data *d)
{
	d->exec.texture.east.bpp = d->exec.texture.east.bpp >> 3;
	d->exec.texture.west.bpp = d->exec.texture.west.bpp >> 3;
	d->exec.texture.north.bpp = d->exec.texture.north.bpp >> 3;
	d->exec.texture.south.bpp = d->exec.texture.south.bpp >> 3;
}

static int	ft_init_textures_e_w(t_data *d)
{
	d->exec.texture.east.img_ptr = mlx_xpm_file_to_image(d->mlx,
			d->exec.texture.texture_ea, &d->exec.texture.east.width,
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
			d->exec.texture.texture_we, &d->exec.texture.west.width,
			&d->exec.texture.west.height);
	if (!d->exec.texture.west.img_ptr)
	{
		write(2, "Error loading west.xpm\n", 24);
		return (-1);
	}
	d->exec.texture.west.addr = mlx_get_data_addr(
			d->exec.texture.west.img_ptr, &d->exec.texture.west.bpp,
			&d->exec.texture.west.line_len, &d->exec.texture.west.endian);
	ft_cal_texture(d);
	return (1);
}

int	ft_init_textures(t_data *d)
{
	d->exec.texture.north.img_ptr = mlx_xpm_file_to_image(d->mlx,
			d->exec.texture.texture_no, &d->exec.texture.north.width,
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
			d->exec.texture.texture_so, &d->exec.texture.south.width,
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
