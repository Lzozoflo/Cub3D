/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:25:27 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/23 08:32:26 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

int	ft_refresh_view(t_data *d)
{
	t_exec			*exec;
	t_minimap		*m;

	exec = &d->exec;
	m = &exec->mini;
	if (ft_start(exec, d) == -1)
		return (-1);
	if (m->zoom != -1)
	{
		t_minimaps_set(m, &exec->player, m->zoom);
		ft_draw_minimap(d, m);
		ft_draw_circle(d, m);
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img_ptr, 0, 0);
	return (1);
}
