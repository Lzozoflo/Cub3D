/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:51:58 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 09:59:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"
#include "ft_define.h"
#include <stdlib.h>

static void	ft_hook_event(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_key_press, data);
	// mlx_mouse_hook(data->win, NULL, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_cross, data);
}

int	ft_init_texture_mlx_ptr(t_data *data, t_texture *texture)
{
	(void)data;
	(void)texture;
	// mlx_xpm_to_image(data->mlx, );
	return (0);
}

int	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIN_SIZE, WIN_SIZE, WIN_NAME);
	if (!data->win)
		ft_clean_close(data, 1);
	data->img.img_ptr = mlx_new_image(data->mlx, WIN_SIZE, WIN_SIZE);
	if (!data->img.img_ptr)
		ft_clean_close(data, 1);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.bpp = data->img.bpp >> 3;
	ft_init_texture_mlx_ptr(data, &data->exec.texture);
	ft_hook_event(data);
	return (1);
}
