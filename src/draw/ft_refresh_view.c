/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:25:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 09:48:36 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

void	ft_refresh_view(t_data *data)
{
	const size_t	res = WIN_SIZE * WIN_SIZE * data->img.bpp;


	ft_bzero(data->img.addr, res);
	ft_draw_sky_floor(data);
	if (data->exec.zoom != -1)
		ft_draw_map_tile(data);

	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
