/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:44:44 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 10:22:29 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"

static int	ft_search_player(char c, int y, int x, t_player *player)
{
	if (c == 'E')
		player->dir_x = -1;
	else if (c == 'W')
		player->dir_x = 1;
	else if (c == 'N')
		player->dir_y = -1;
	else if (c == 'S')
		player->dir_y = 1;
	else
		return (0);
	player->pos_y = y;
	player->pos_x = x;
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
