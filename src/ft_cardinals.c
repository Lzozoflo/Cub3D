/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cardinals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:04:03 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 10:10:18 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"

// e->s.n.a = 0;
// e->s.n.b = 1;
// e->s.n.c = 0;
// e->s.n.d = 3;
// e->s.e.a = 1;
// e->s.e.b = 0;
// e->s.e.c = 0;
// e->s.e.d = -3;
// e->s.w.a = 1;
// e->s.w.b = 0;
// e->s.w.c = 0;
// e->s.w.d = 3;
// e->s.s.a = 0;
// e->s.s.b = 1;
// e->s.s.c = 0;
// e->s.s.d = -3;

void	ft_init_point(t_exec *e)
{
	e->s.w.a = e->cardi.w.a;
	e->s.w.b = e->cardi.w.b;
	e->s.w.c = e->cardi.w.c;
	e->s.w.d = e->cardi.w.d;
	e->s.e.a = e->cardi.e.a;
	e->s.e.b = e->cardi.e.b;
	e->s.e.c = e->cardi.e.c;
	e->s.e.d = e->cardi.e.d;
	e->s.n.a = e->cardi.n.a;
	e->s.n.b = e->cardi.n.b;
	e->s.n.c = e->cardi.n.c;
	e->s.n.d = e->cardi.n.d;
	e->s.s.a = e->cardi.s.a;
	e->s.s.b = e->cardi.s.b;
	e->s.s.c = e->cardi.s.c;
	e->s.s.d = e->cardi.s.d;
}

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
			ft_north(&d->exec.cardi, y);
			break ;
		}
		y--;
	}
	y = d->exec.player.pos_y;
	while (y < d->exec.max_height)
	{
		if (tab[y][x] == '1')
		{
			ft_south(&d->exec.cardi, y);
			break ;
		}
		y++;
	}
}

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
			ft_west(&d->exec.cardi, x);
			break ;
		}
		x--;
	}
	x = d->exec.player.pos_x;
	while (x < d->exec.max_width)
	{
		if (tab[y][x] == '1')
		{
			ft_east(&d->exec.cardi, x);
			break ;
		}
		x++;
	}
}
