/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:55:21 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/05 13:05:42 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <unistd.h>

static void	ft_opti_cal_bpp(t_texture *t)
{
	t->north.bpp = t->north.bpp >> 3;
	t->south.bpp = t->south.bpp >> 3;
	t->east.bpp = t->east.bpp >> 3;
	t->west.bpp = t->west.bpp >> 3;
}

static int	ft_init_textures_e_w(t_data *d, t_texture *t)
{
	t->east.img_ptr = mlx_xpm_file_to_image(d->mlx,
			t->texture_ea, &t->east.width,
			&t->east.height);
	if (!t->east.img_ptr)
	{
		write(2, "Error loading east\n", 20);
		return (-1);
	}
	t->east.addr = mlx_get_data_addr(
			t->east.img_ptr, &t->east.bpp,
			&t->east.line_len, &t->east.endian);
	t->west.img_ptr = mlx_xpm_file_to_image(d->mlx,
		t->texture_we, &t->west.width,
			&t->west.height);
	if (!t->west.img_ptr)
	{
		write(2, "Error loading west\n", 20);
		return (-1);
	}
	t->west.addr = mlx_get_data_addr(
			t->west.img_ptr, &t->west.bpp,
			&t->west.line_len, &t->west.endian);
	ft_opti_cal_bpp(t);
	return (1);
}

int	ft_init_textures(t_data *d, t_texture *t)
{
	t->north.img_ptr = mlx_xpm_file_to_image(d->mlx,
		t->texture_no, &t->north.width,
			&t->north.height);
	if (!t->north.img_ptr)
	{
		write(2, "Error loading north\n", 20);
		return (-1);
	}
	t->north.addr = mlx_get_data_addr(
			t->north.img_ptr, &t->north.bpp,
			&t->north.line_len, &t->north.endian);
	t->south.img_ptr = mlx_xpm_file_to_image(d->mlx,
		t->texture_so, &t->south.width,
			&t->south.height);
	if (!t->south.img_ptr)
	{
		write(2, "Error loading south\n", 20);
		return (-1);
	}
	t->south.addr = mlx_get_data_addr(
			t->south.img_ptr, &t->south.bpp,
			&t->south.line_len, &t->south.endian);
	if (ft_init_textures_e_w(d, t) == -1)
		return (-1);
	return (1);
}
