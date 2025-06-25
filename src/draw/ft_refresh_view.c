/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:25:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/25 10:49:59 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

void	ft_refresh_view(t_data *d)
{
	t_exec			*exec;
	t_minimap		*m;

	exec = &d->exec;
	m = &exec->mini;
	ft_start(exec, d);
	if (m->zoom != -1)
	{
		t_minimaps_set(m, &exec->player, m->zoom);
		ft_draw_minimap(d, m);
		ft_draw_circle(d, m);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
}
