/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cardinals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:04:03 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/27 15:56:30 by mlaussel         ###   ########.fr       */
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
	e->s.w.a = e->cardi.w[0].a;
	e->s.w.b = e->cardi.w[0].b;
	e->s.w.c = e->cardi.w[0].c;
	e->s.w.d = e->cardi.w[0].d;
	e->s.e.a = e->cardi.e[0].a;;
	e->s.e.b = e->cardi.e[0].a;;
	e->s.e.c = e->cardi.e[0].a;;
	e->s.e.d = e->cardi.e[0].a;;
	e->s.n.a = e->cardi.n[0].a;;
	e->s.n.b = e->cardi.n[0].a;;
	e->s.n.c = e->cardi.n[0].a;;
	e->s.n.d = e->cardi.n[0].a;;
	e->s.s.a = e->cardi.s[0].a;;
	e->s.s.b = e->cardi.s[0].a;;
	e->s.s.c = e->cardi.s[0].a;;
	e->s.s.d = e->cardi.s[0].a;;
}

void	ft_north_and_south_walls(t_data *d, char **tab)
{
	int	x;
	int	y;
	int	index;

	x = d->exec.player.pos_x;
	y = d->exec.player.pos_y;
	index = 0;
	while (y > 0)
	{
		if (tab[y][x] == '1')
		{
			ft_north(&d->exec.cardi, index, y);
			index++;
			break ;
		}
		y--;
	}
	index = 0;
	y = d->exec.player.pos_y;
	while (y < d->exec.max_height)
	{
		if (tab[y][x] == '1')
		{
			ft_south(&d->exec.cardi, index, y);
			index++;
			break ;
		}
		y++;
	}
}


void	ft_east_and_west_walls(t_data *d, char **tab)
{
	int	x;
	int	y;
	int	index;

	x = d->exec.player.pos_x;
	y = d->exec.player.pos_y;
	index = 0;
	while (x > 0)
	{
		if (tab[y][x] == '1')
		{
			ft_west(&d->exec.cardi, index, x);
			index++;
			break ;
		}
		x--;
	}
	index = 0;
	x = d->exec.player.pos_x;
	while (x < d->exec.max_width)
	{
		if (tab[y][x] == '1')
		{
			ft_east(&d->exec.cardi, index, x);
			index++;
			break ;
		}
		x++;
	}
}
















// void	ft_east_and_west_walls(t_data *d, char **tab)
// {
// 	int	y;
// 	int	x;
// 	int	index;

// 	y = 0;
// 	index = 0;
// 	while (y < d->exec.max_height)
// 	{
// 		x = d->exec.player.pos_x;
// 		while (x >= 0)
// 		{
// 			if (tab[y][x] == '1')
// 			{
// 				ft_west(d, index, x);
// 				index++;
// 				break ;
// 			}
// 			x--;
// 		}
// 		y++;
// 	}
// 	y = 0;
// 	index = 0;
// 	while (y < d->exec.max_height)
// 	{
// 		x = d->exec.player.pos_x;
// 		while (x < d->exec.max_width)
// 		{
// 			if (tab[y][x] == '1')
// 			{
// 				ft_east(d, index, x);
// 				index++;
// 				break ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	ft_north_and_south_walls(t_data *d, char **tab)
// {
// 	int	x;
// 	int	y;
// 	int	index;

// 	x = 0;
// 	index = 0;
// 	while (x < d->exec.max_width)
// 	{
// 		y = d->exec.player.pos_y;
// 		while (y >= 0)
// 		{
// 			if (tab[y][x] == '1')
// 			{
// 				ft_north(d, index, y);
// 				index++;
// 				break ;
// 			}
// 			y--;
// 		}
// 		x++;
// 	}
// 	x = 0;
// 	index = 0;
// 	while (x < d->exec.max_width)
// 	{
// 		y = d->exec.player.pos_y;
// 		while (y < d->exec.max_height)
// 		{
// 			if (tab[y][x] == '1')
// 			{
// 				ft_south(d, index, y);
// 				index++;
// 				break ;
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }





// void	ft_browse_walls(t_data *d, char **tab)
// {
// 	int	y;
// 	int	x;

// 	x = d->exec.player.pos_x;
// 	y = d->exec.player.pos_y;
// 	while (x >= 0)
// 	{
// 		if (tab[y][x] == '1')
// 		{
// 			ft_west(&d->exec.cardi, x);
// 			break ;
// 		}
// 		x--;
// 	}
// 	x = d->exec.player.pos_x;
// 	while (x < d->exec.max_width)
// 	{
// 		if (tab[y][x] == '1')
// 		{
// 			ft_east(&d->exec.cardi, x);
// 			break ;
// 		}
// 		x++;
// 	}
// 	while (y >= 0)
// 	{
// 		if (tab[y][x] == '1')
// 		{
// 			ft_north(&d->exec.cardi, y);
// 			break ;
// 		}
// 		y--;
// 	}
// 	y = d->exec.player.pos_y;
// 	while (y < d->exec.max_height)
// 	{
// 		if (tab[y][x] == '1')
// 		{
// 			ft_south(&d->exec.cardi, y);
// 			break ;
// 		}
// 		y++;
// 	}
// }
