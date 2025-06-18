/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:06:29 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 16:40:23 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "ft_define.h"
#include "ft_cub.h"
#include <math.h>

static int	ft_w(t_player *player)
{
	double	pos_x;
	double	pos_y;

	debug_put_str("[w] is pressed", NULL, 2, 21);
	pos_x = player->pos_x + sin(player->angle) * MS;
	pos_y = player->pos_y - cos(player->angle) * MS;
	if (ft_check_pos_colision(player, pos_x, pos_y))
		return (-1);
	player->pos_x = pos_x;
	player->pos_y = pos_y;
	return (1);
}

static int	ft_a(t_player *player)
{
	double	pos_x;
	double	pos_y;

	debug_put_str("[a] is pressed", NULL, 2, 21);
	pos_x = player->pos_x - cos(player->angle) * MS;
	pos_y = player->pos_y - sin(player->angle) * MS;
	if (ft_check_pos_colision(player, pos_x, pos_y))
		return (-1);
	player->pos_x = pos_x;
	player->pos_y = pos_y;
	return (1);
}

static int	ft_s(t_player *player)
{
	double	pos_x;
	double	pos_y;

	debug_put_str("[s] is pressed", NULL, 2, 21);
	pos_x = player->pos_x - sin(player->angle) * MS;
	pos_y = player->pos_y + cos(player->angle) * MS;
	if (ft_check_pos_colision(player, pos_x, pos_y ))
		return (-1);
	player->pos_x = pos_x;
	player->pos_y = pos_y;
	return (1);
}

static int	ft_d(t_player *player)
{
	double	pos_x;
	double	pos_y;

	debug_put_str("[d] is pressed", NULL, 2, 21);
	pos_x = player->pos_x + cos(player->angle) * MS;
	pos_y = player->pos_y + sin(player->angle) * MS;
	if (ft_check_pos_colision(player, pos_x, pos_y))
		return (-1);
	player->pos_x = pos_x;
	player->pos_y = pos_y;
	return (1);
}

int	ft_wasd(int keycode, t_player *player)
{
	if (keycode == W && ft_w(player) == -1)
		return (-1);
	else if (keycode == A && ft_a(player) == -1)
		return (-1);
	else if (keycode == S && ft_s(player) == -1)
		return (-1);
	else if (keycode == D && ft_d(player) == -1)
		return (-1);
	return (1);
}
