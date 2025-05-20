/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:04:03 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/20 15:27:19 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>
#include <stdio.h> ////DELETE

void	ft_north(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	e->s.nx = 0;
	e->s.ny = 1;
	e->s.nx2 = 0;
	e->s.ny2 = 3;
	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_radius(e, i, j, 'n');
			ft_intersection(e, d, 'n');
			j++;
		}
		i++;
	}
}

void	ft_east(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	e->s.ex = -1;
	e->s.ey = 0;
	e->s.ex2 = 0;
	e->s.ey2 = 3;
	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_radius(e, i, j, 'e');
			ft_intersection(e, d, 'e');
			j++;
		}
		i++;
	}
}

void	ft_west(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	e->s.ox = -1;
	e->s.oy = 0;
	e->s.ox2 = 0;
	e->s.oy2 = -3;
	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_radius(e, i, j, 'w');
			ft_intersection(e, d, 'w');
			j++;
		}
		i++;
	}
}

void	ft_south(t_exec *e, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	e->s.sx = 0;
	e->s.sy = 1;
	e->s.sx2 = 0;
	e->s.sy2 = -3;
	ft_init_camera(e);
	ft_fov_h_and_v_ratio(e);
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			ft_radius(e, i, j, 's');
			ft_intersection(e, d, 's');
			j++;
		}
		i++;
	}
}
