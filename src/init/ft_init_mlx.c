/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:51:58 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/26 10:36:24 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"
#include "ft_define.h"
#include <stdlib.h>
static void	ft_hook_event(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 17, ft_cross, data);
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
	ft_hook_event(data);
	return (1);
}
