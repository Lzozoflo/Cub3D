/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/18 13:47:37 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "ft_define.h"
#include "libft.h"
#include "ft_cub.h"
#include <math.h>

static int	ft_zoom_minimaps(t_data *data)
{
	int	*value;

	value = &data->exec.mini.zoom;
	if (*value == -1)
		*value = 0;
	else if (*value == 0)
		*value = 1;
	else
		*value = -1;
	return (0);
}

static int	ft_arrow(int keycode, t_data *data, t_player *player)
{
	(void)data;
	if (keycode == LEFT)
	{
		player->angle -= ROTATION;
		debug_put_str("[LEFT] is pressed", NULL, 2, 21);
	}
	else if (keycode == RIGHT)
	{
		player->angle += ROTATION;
		debug_put_str("[RIGHT] is pressed", NULL, 2, 21);
	}
	while (player->angle < 0)
		player->angle += 2 * PI;
	while (player->angle >= 2 * PI)
		player->angle -= 2 * PI;
	return (1);
}

int	ft_check_pos_colision(t_player *p, double x, double y)
{
	const t_exec	*exec = (const t_exec *)&p->data->exec;
	const char		**tab = (const char **)exec->tab;
	const int		cx = (int)(floor(x));
	const int		cy = (int)(floor(y));

	if (y < 0 || x < 0 || y >= exec->max_height || x >= exec->max_width)
		return (1);
	return (tab[cy][cx] == '1');
}

int	ft_key_press(int keycode, void *param)
{
	t_data		*data;

	data = (t_data *)param;


	debug_put_int("ft_key_press -> keycode", keycode, 200, 200);
	if (keycode == ESC)
	{
		mlx_loop_end(data->mlx);
		ft_clean_close(data, 0);
	}
	if (ft_is_player_move(keycode) && ft_wasd(keycode, &data->exec.player) == 0)
		return (1);
	if (ft_is_camera_move(keycode)
		&& ft_arrow(keycode, data, &data->exec.player) == -1)
		return (1);
	if (keycode == M && ft_zoom_minimaps(data))
		return (1);
	if (ft_is_refresh_event(keycode))
	{
		ft_refresh_view(data);
		debug_put_str("ft_key_press -> refresh view", NULL, 2, 21);
	}
	return (1);
}
