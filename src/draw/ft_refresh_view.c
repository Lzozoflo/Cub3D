/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:25:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/26 12:50:02 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

void	ft_refresh_view(t_data *d)
{
	const size_t	res = (size_t)(WIN_SIZE * WIN_SIZE * d->img.bpp);
	t_exec			*exec;
	t_minimap		*m;

	exec = &d->exec;
	m = &exec->mini;
	ft_bzero(d->img.addr, res);
	ft_draw_sky_floor(d);
	ft_start(&d->exec, d);
	if (m->zoom != -1){
		t_minimaps_set(m, &exec->player, m->zoom);
		ft_draw_minimap(d, m);
		ft_draw_circle(d, m);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
}
