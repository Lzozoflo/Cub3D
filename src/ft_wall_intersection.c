/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:39:02 by mathildelau       #+#    #+#             */
/*   Updated: 2025/06/11 15:39:11 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_north_wall(t_data *d, int y)
{
	d->exec.wall.t_n = ft_find_plane_intersection(&d->exec,
		&d->exec.cardi.n[y]);
	if (d->exec.wall.t_n > 0)
	{
		ft_intersection_coord(&d->exec, d->exec.wall.t_n);
		d->exec.wall.x_check = (int)(d->exec.s.ix);
		if (d->exec.wall.x_check >= 0 && d->exec.wall.x_check < d->exec.max_width && y >= 0
			&& y < d->exec.max_height && d->exec.tab[y][d->exec.wall.x_check] == '1')
		{
			if (d->exec.wall.t_min < 0
				|| d->exec.wall.t_n < d->exec.wall.t_min)
			{
				d->exec.wall.t_min = d->exec.wall.t_n;
				d->exec.wall.face = 'n';
			}
		}
	}
}

void	ft_south_wall(t_data *d, int y)
{
	d->exec.wall.t_s = ft_find_plane_intersection(&d->exec,
		&d->exec.cardi.s[y]);
	if (d->exec.wall.t_s > 0)
	{
		ft_intersection_coord(&d->exec, d->exec.wall.t_s);
		d->exec.wall.x_check = (int)(d->exec.s.ix);
		if (d->exec.wall.x_check >= 0 && d->exec.wall.x_check < d->exec.max_width && y >= 0
			&& y < d->exec.max_height && d->exec.tab[y][d->exec.wall.x_check] == '1')
		{
			if (d->exec.wall.t_min < 0
				|| d->exec.wall.t_s < d->exec.wall.t_min)
			{
				d->exec.wall.t_min = d->exec.wall.t_s;
				d->exec.wall.face = 's';
			}
		}
	}
}

void	ft_east_wall(t_data *d, int x)
{
	d->exec.wall.t_e = ft_find_plane_intersection(&d->exec,
		&d->exec.cardi.e[x]);
	if (d->exec.wall.t_e > 0)
	{
		ft_intersection_coord(&d->exec, d->exec.wall.t_e);
		d->exec.wall.y_check = (int)(d->exec.s.iy);
		if (x >= 0 && x < d->exec.max_width && d->exec.wall.y_check >= 0
			&& d->exec.wall.y_check < d->exec.max_height
			&& d->exec.tab[d->exec.wall.y_check][x] == '1')
		{
			if (d->exec.wall.t_min < 0
				|| d->exec.wall.t_e < d->exec.wall.t_min)
			{
				d->exec.wall.t_min = d->exec.wall.t_e;
				d->exec.wall.face = 'e';
			}
		}
	}
}

void	ft_west_wall(t_data *d, int x)
{
	d->exec.wall.t_w = ft_find_plane_intersection(&d->exec,
		&d->exec.cardi.w[x]);
	if (d->exec.wall.t_w > 0)
	{
		ft_intersection_coord(&d->exec, d->exec.wall.t_w);
		d->exec.wall.y_check = (int)(d->exec.s.iy);
		if (x >= 0 && x < d->exec.max_width && d->exec.wall.y_check >= 0
			&& d->exec.wall.y_check < d->exec.max_height
			&& d->exec.tab[d->exec.wall.y_check][x] == '1')
		{
			if (d->exec.wall.t_min < 0
				|| d->exec.wall.t_w < d->exec.wall.t_min)
			{
				d->exec.wall.t_min = d->exec.wall.t_w;
				d->exec.wall.face = 'w';
			}
		}
	}
}