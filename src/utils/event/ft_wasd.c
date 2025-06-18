/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wasd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:06:29 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 12:03:13 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "ft_define.h"
#include "ft_cub.h"
#include <math.h>

static int	ft_w(t_player *player)
{
	debug_put_str("[w] is pressed", NULL, 2, 21);
	if (ft_check_pos_colision(player, player->pos_x, player->pos_y - MS))
		return (-1);
	if (player->pos == 'n')
	{
		player->pos_x = player->pos_x + sin(player->angle) * MS;
		player->pos_y = player->pos_y - cos(player->angle) * MS;
	}
	else if (player->pos == 's')
	{
		player->pos_x = player->pos_x + sin(player->angle) * MS;
		player->pos_y = player->pos_y + cos(player->angle) * MS;
	}
	else if (player->pos == 'w')
	{
		player->pos_x = player->pos_x - cos(player->angle) * MS;
		player->pos_y = player->pos_y + sin(player->angle) * MS;
	}
	else if (player->pos == 'e')
	{
		player->pos_x = player->pos_x + cos(player->angle) * MS;
		player->pos_y = player->pos_y + sin(player->angle) * MS;
	}
	return (1);
}

static int	ft_a(t_player *player)
{
	debug_put_str("[a] is pressed", NULL, 2, 21);
	if (ft_check_pos_colision(player, player->pos_x - MS, player->pos_y))
		return (-1);
	if (player->pos == 'n' || player->pos == 's')
	{
		player->pos_x = player->pos_x - cos(player->angle) * MS;
		player->pos_y = player->pos_y - sin(player->angle) * MS;
	}
	else if (player->pos == 'w' || player->pos == 'e')
	{
		player->pos_x = player->pos_x - sin(player->angle) * MS;
		player->pos_y = player->pos_y - cos(player->angle) * MS;
	}
	return (1);
}

static int	ft_s(t_player *player)
{
	debug_put_str("[s] is pressed", NULL, 2, 21);
	if (ft_check_pos_colision(player, player->pos_x, player->pos_y + MS))
		return (-1);
	if (player->pos == 'n')
	{
		player->pos_x = player->pos_x + sin(player->angle) * MS;
		player->pos_y = player->pos_y + cos(player->angle) * MS;
	}
	else if (player->pos == 's')
	{
		player->pos_x = player->pos_x + sin(player->angle) * MS;
		player->pos_y = player->pos_y - cos(player->angle) * MS;
	}
	else if (player->pos == 'w')
	{
		player->pos_x = player->pos_x + cos(player->angle) * MS;
		player->pos_y = player->pos_y - sin(player->angle) * MS;
	}
	else if (player->pos == 'e')
	{
		player->pos_x = player->pos_x - cos(player->angle) * MS;
		player->pos_y = player->pos_y + sin(player->angle) * MS;
	}
	return (1);
}

static int	ft_d(t_player *player)
{
	debug_put_str("[d] is pressed", NULL, 2, 21);
	if (ft_check_pos_colision(player, player->pos_x + MS, player->pos_y))
		return (-1);
	if (player->pos == 'n' || player->pos == 's')
	{
		player->pos_x = player->pos_x + cos(player->angle) * MS;
		player->pos_y = player->pos_y + sin(player->angle) * MS;
	}
	else if (player->pos == 'w' || player->pos == 'e')
	{
		player->pos_x = player->pos_x - sin(player->angle) * MS;
		player->pos_y = player->pos_y + cos(player->angle) * MS;
	}
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
