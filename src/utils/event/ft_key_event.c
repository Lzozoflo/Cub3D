/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/23 13:50:52 by mlaussel         ###   ########.fr       */
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
	if (data->exec.keys.m)
	{
		if (*value == -1)
			*value = 0;
		else if (*value == 0)
			*value = 1;
		else
			*value = -1;
		data->exec.keys.m = 0;
	}
	return (0);
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

int	ft_handle_keys(void *param)
{
	t_data		*data;
	t_player	*p;

	data = (t_data *)param;
	p = &data->exec.player;
	if (ft_wasd(data, p) == -1)
		return (-1);
	if (data->exec.keys.left)
	{
		p->angle -= ROTATION;
		if (p->angle < 0)
			p->angle += 2 * PI;
	}
	if (data->exec.keys.right)
	{
		p->angle += ROTATION;
		if (p->angle >= 2 * PI)
			p->angle -= 2 * PI;
	}
	// if (data->exec.keys.up)
	// {
	// 	p->angle_x -= ROTATION;
	// 	if (p->angle_x < 0)
	// 		p->angle_x += 2 * PI;
	// }
	// if (data->exec.keys.down)
	// {
	// 	p->angle_x += ROTATION;
	// 	if (p->angle_x >= 2 * PI)
	// 		p->angle_x -= 2 * PI;
	// }
	ft_zoom_minimaps(data);
	ft_refresh_view(data);
	return (0);
}

int	ft_key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC)
		ft_clean_close(data, 0);
	if (keycode == W)
		data->exec.keys.w = 1;
	else if (keycode == A)
		data->exec.keys.a = 1;
	else if (keycode == S)
		data->exec.keys.s = 1;
	else if (keycode == D)
		data->exec.keys.d = 1;
	else if (keycode == LEFT)
		data->exec.keys.left = 1;
	else if (keycode == RIGHT)
		data->exec.keys.right = 1;
	else if (keycode == UP)
		data->exec.keys.up = 1;
	else if (keycode == DOWN)
		data->exec.keys.down = 1;
	else if (keycode == M)
		data->exec.keys.m = 1;
	return (1);
}

int	ft_key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == W)
		data->exec.keys.w = 0;
	else if (keycode == A)
		data->exec.keys.a = 0;
	else if (keycode == S)
		data->exec.keys.s = 0;
	else if (keycode == D)
		data->exec.keys.d = 0;
	else if (keycode == LEFT)
		data->exec.keys.left = 0;
	else if (keycode == RIGHT)
		data->exec.keys.right = 0;
	else if (keycode == UP)
		data->exec.keys.up = 0;
	else if (keycode == DOWN)
		data->exec.keys.down = 0;
	else if (keycode == M)
		data->exec.keys.m = 0;
	return (1);
}
