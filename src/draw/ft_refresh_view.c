/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:25:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/21 15:00:45 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

void	ft_refresh_view(t_data *d)
{
	const size_t	res = WIN_SIZE * WIN_SIZE * d->img.bpp;
	t_exec	*exec = &d->exec;


	ft_bzero(d->img.addr, res);
	ft_draw_sky_floor(d);
	if (d->exec.mini.zoom != -1)
		ft_draw_map_tile(d, exec, &exec->mini, &exec->player);

	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
}
