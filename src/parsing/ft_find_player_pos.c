/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:44:44 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/27 10:03:17 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"

static int	ft_search_player(char c, int y, int x, t_player *player)
{
	if (c == 'E')
	{
		player->dir_x = 1;
		player->pos = 'e';
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->pos = 'w';
	}
	else if (c == 'N')
	{
		player->dir_y = -1;
		player->pos = 'n';
	}
	else if (c == 'S')
	{
		player->dir_y = 1;
		player->pos = 's';
	}
	else
		return (0);
	player->pos_y = y + 0.5;
	player->pos_x = x + 0.5;
	return (1);
}

void	ft_find_player_pos(char **tab, t_player *player)
{
	int	y;
	int	x;

	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (ft_search_player(tab[y][x], y, x, player))
				return ;
		}
	}
}
