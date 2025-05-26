/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/26 13:44:41 by mlaussel         ###   ########.fr       */
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
		player->angle -= 0.1;
		printf("angle : %f\n", player->angle);
		debug_put_str("[LEFT] is pressed", NULL, 2, 21);
	}
	else if (keycode == RIGHT)
	{
		player->angle += 0.1;
		printf("angle : %f\n", player->angle);
		debug_put_str("[RIGHT] is pressed", NULL, 2, 21);
	}
	return (1);
}

static int	ft_check_pos_colision(t_player *p, double x, double y)
{
	const t_exec	*exec = (const t_exec *)&p->data->exec;
	const char		**tab = (const char **)exec->tab;
	const int		cx = (int)(floor(x));
	const int		cy = (int)(floor(y));

	if (y < 0 || x < 0 || y >= exec->max_height || x >= exec->max_width)
		return (1);
	return (tab[cy][cx] == '1');
}

static int	ft_wasd(int keycode, t_player *player)
{
	if (keycode == W)
	{
		debug_put_str("[w] is pressed", NULL, 2, 21);
		if (ft_check_pos_colision(player, player->pos_x, player->pos_y - MS))
			return (-1);
		player->pos_y -= MS;
	}
	else if (keycode == A)
	{
		debug_put_str("[a] is pressed", NULL, 2, 21);
		if (ft_check_pos_colision(player, player->pos_x - MS, player->pos_y))
			return (-1);
		player->pos_x -= MS;
	}
	else if (keycode == S)
	{
		debug_put_str("[s] is pressed", NULL, 2, 21);
		if (ft_check_pos_colision(player, player->pos_x , player->pos_y + MS))
			return (-1);
		player->pos_y += MS;
	}
	else if (keycode == D)
	{
		debug_put_str("[d] is pressed", NULL, 2, 21);
		if (ft_check_pos_colision(player, player->pos_x + MS, player->pos_y))
			return (-1);
		player->pos_x += MS;
	}
	// printf("pos y: %f, pos x %f\n", player->pos_y, player->pos_x);
	return (1);
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
	if (ft_is_camera_move(keycode) && ft_arrow(keycode, data, &data->exec.player) == -1)
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
