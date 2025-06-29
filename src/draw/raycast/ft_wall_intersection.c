/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:39:02 by mathildelau       #+#    #+#             */
/*   Updated: 2025/06/25 17:08:45 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"

/**
 * @brief `check north intersection`
 *
 * (p.30) : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 * --> t (p.23)
 * --> Iz (p.23)
 *
 * (p.31) - Checks in the map (cast int):
 * "After finding an intersection with a plan,
 * you need to look to see if there is a wall at that location on the map.
 * When looking North, you must check the box (Ix, Iy - 1)."
 *
 * (p.30) - Route of plans : "So, we just stop at the first wall
 * and compare the distance (t) of the nearest wall on the x-axis
 * with the one closest to the y-axis."
 */
void	ft_north_wall(t_exec *e, int y, t_ray radius)
{
	e->wall.t_n = ft_find_plane_intersection_n_s(e, &e->cardi.n[y], radius);
	if (e->wall.t_n > 0 && e->wall.t_n < MAX_D)
	{
		ft_intersection_coord(e, e->wall.t_n, radius);
		e->wall.x_check = (int)(e->s.ix);
		if (e->wall.x_check >= 0 && e->wall.x_check < e->max_width && y >= 0
			&& y < e->max_height && e->tab[y][e->wall.x_check] == '1')
		{
			if (e->wall.t_min < 0
				|| e->wall.t_n < e->wall.t_min)
			{
				e->wall.t_min = e->wall.t_n;
				e->wall.face = 'n';
			}
		}
	}
}

/**
 * @brief `check south intersection`
 *
 * (p.30) : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 * --> t (p.23)
 * --> Iz (p.23)
 *
 * (p.31) - Checks in the map (cast int):
 * "After finding an intersection with a plan,
 * you need to look to see if there is a wall at that location on the map.
 * When looking South, you must check the box (Ix, Iy)."
 *
 * (p.30) - Route of plans : "So, we just stop at the first wall
 * and compare the distance (t) of the nearest wall on the x-axis
 * with the one closest to the y-axis."
 */
void	ft_south_wall(t_exec *e, int y, t_ray radius)
{
	e->wall.t_s = ft_find_plane_intersection_n_s(e, &e->cardi.s[y], radius);
	if (e->wall.t_s > 0 && e->wall.t_s < MAX_D)
	{
		ft_intersection_coord(e, e->wall.t_s, radius);
		e->wall.x_check = (int)(e->s.ix);
		if (e->wall.x_check >= 0 && e->wall.x_check < e->max_width && y >= 0
			&& y < e->max_height && e->tab[y][e->wall.x_check] == '1')
		{
			if (e->wall.t_min < 0
				|| e->wall.t_s < e->wall.t_min)
			{
				e->wall.t_min = e->wall.t_s;
				e->wall.face = 's';
			}
		}
	}
}

/**
 * @brief `check east intersection`
 *
 * (p.30) : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 * --> t (p.23)
 * --> Iz (p.23)
 *
 * (p.31) - Checks in the map (cast int):
 * "After finding an intersection with a plan,
 * you need to look to see if there is a wall at that location on the map.
 * When looking East, you must check the box (Ix, Iy)."
 *
 * (p.30) - Route of plans : "So, we just stop at the first wall
 * and compare the distance (t) of the nearest wall on the x-axis
 * with the one closest to the y-axis."
 */
void	ft_east_wall(t_exec *e, int x, t_ray radius)
{
	e->wall.t_e = ft_find_plane_intersection_e_w(e, &e->cardi.e[x], radius);
	if (e->wall.t_e > 0 && e->wall.t_e < MAX_D)
	{
		ft_intersection_coord(e, e->wall.t_e, radius);
		e->wall.y_check = (int)(e->s.iy);
		if (x >= 0 && x < e->max_width && e->wall.y_check >= 0
			&& e->wall.y_check < e->max_height
			&& e->tab[e->wall.y_check][x] == '1')
		{
			if (e->wall.t_min < 0
				|| e->wall.t_e < e->wall.t_min)
			{
				e->wall.t_min = e->wall.t_e;
				e->wall.face = 'e';
			}
		}
	}
}

/**
 * @brief `check west intersection`
 *
 * (p.30) : "For an intersection to be considered valid,
 * t must be positive and Iz must be between 0 inclusive and 1."
 * --> t (p.23)
 * --> Iz (p.23)
 *
 * (p.31) - Checks in the map (cast int):
 * "After finding an intersection with a plan,
 * you need to look to see if there is a wall at that location on the map.
 * When looking West, you must check the box (Ix - 1, Iy)."
 *
 * (p.30) - Route of plans : "So, we just stop at the first wall
 * and compare the distance (t) of the nearest wall on the x-axis
 * with the one closest to the y-axis."
 */
void	ft_west_wall(t_exec *e, int x, t_ray radius)
{
	e->wall.t_w = ft_find_plane_intersection_e_w(e, &e->cardi.w[x], radius);
	if (e->wall.t_w > 0 && e->wall.t_w < MAX_D)
	{
		ft_intersection_coord(e, e->wall.t_w, radius);
		e->wall.y_check = (int)(e->s.iy);
		if (x >= 0 && x < e->max_width && e->wall.y_check >= 0
			&& e->wall.y_check < e->max_height
			&& e->tab[e->wall.y_check][x] == '1')
		{
			if (e->wall.t_min < 0
				|| e->wall.t_w < e->wall.t_min)
			{
				e->wall.t_min = e->wall.t_w;
				e->wall.face = 'w';
			}
		}
	}
}
