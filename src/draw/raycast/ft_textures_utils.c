/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:15:04 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/23 13:16:15 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <unistd.h>

void	ft_destroy_textures(t_data *d)
{
	if (d->exec.texture.north.img_ptr)
	{
		mlx_destroy_image(d->mlx, d->exec.texture.north.img_ptr);
		d->exec.texture.north.img_ptr = NULL;
	}
	if (d->exec.texture.south.img_ptr)
	{
		mlx_destroy_image(d->mlx, d->exec.texture.south.img_ptr);
		d->exec.texture.south.img_ptr = NULL;
	}
	if (d->exec.texture.east.img_ptr)
	{
		mlx_destroy_image(d->mlx, d->exec.texture.east.img_ptr);
		d->exec.texture.east.img_ptr = NULL;
	}
	if (d->exec.texture.west.img_ptr)
	{
		mlx_destroy_image(d->mlx, d->exec.texture.west.img_ptr);
		d->exec.texture.west.img_ptr = NULL;
	}
}

void	ft_cal_texture(t_data *d)
{
	d->exec.texture.east.bpp = d->exec.texture.east.bpp >> 3;
	d->exec.texture.west.bpp = d->exec.texture.west.bpp >> 3;
	d->exec.texture.north.bpp = d->exec.texture.north.bpp >> 3;
	d->exec.texture.south.bpp = d->exec.texture.south.bpp >> 3;
}
