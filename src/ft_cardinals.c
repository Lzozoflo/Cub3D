/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cardinals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:04:03 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/04 13:57:57 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"

/**
 * @brief `search north and south wall`
 *
 * p.30 : "The simplest way to navigate planes is
 * to start at the player position index (O),
 *  then increment or decrement this according
 * to the direction of the ray"
 */
void	ft_north_and_south_walls(t_data *d, char **tab)
{
	int	x;
	int	y;

	x = d->exec.player.pos_x;
	y = d->exec.player.pos_y;
	while (y > 0)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.n.a = d->exec.cardi.n[y].a;
			d->exec.s.n.b = d->exec.cardi.n[y].b;
			d->exec.s.n.c = d->exec.cardi.n[y].c;
			d->exec.s.n.d = d->exec.cardi.n[y].d;
			break ;
		}
		y--;
	}
	y = d->exec.player.pos_y;
	while (y < d->exec.max_height)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.s.a = d->exec.cardi.s[y].a;
			d->exec.s.s.b = d->exec.cardi.s[y].b;
			d->exec.s.s.c = d->exec.cardi.s[y].c;
			d->exec.s.s.d = d->exec.cardi.s[y].d;
			break ;
		}
		y++;
	}
}

/**
 * @brief `search east and south west`
 *
 * p.30 : "The simplest way to navigate planes is
 * to start at the player position index (O),
 *  then increment or decrement this according
 * to the direction of the ray"
 */
void	ft_east_and_west_walls(t_data *d, char **tab)
{
	int	x;
	int	y;

	x = d->exec.player.pos_x;
	y = d->exec.player.pos_y;
	while (x > 0)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.e.a = d->exec.cardi.e[x].a;
			d->exec.s.e.b = d->exec.cardi.e[x].b;
			d->exec.s.e.c = d->exec.cardi.e[x].c;
			d->exec.s.e.d = d->exec.cardi.e[x].d;
			break ;
		}
		x--;
	}
	x = d->exec.player.pos_x;
	while (x < d->exec.max_width)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.w.a = d->exec.cardi.w[x].a;
			d->exec.s.w.b = d->exec.cardi.w[x].b;
			d->exec.s.w.c = d->exec.cardi.w[x].c;
			d->exec.s.w.d = d->exec.cardi.w[x].d;
			break ;
		}
		x++;
	}
}
