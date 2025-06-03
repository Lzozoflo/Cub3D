/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:30 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 09:21:55 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>
#include <stdlib.h>

static void	ft_intersection_north(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 'n');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = 0xFFFFFF;
			}
		}
	}
}

static void	ft_intersection_east(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 'e');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = 0xFF0000;
			}
		}
	}
}

static void	ft_intersection_west(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 'w');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = 0x0000FF;
			}
		}
	}
}

static void	ft_intersection_south(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 's');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = 0xFF00FF;
			}
		}
	}
}

/**
 * @brief `if intersection, color + find the nearest t`
 *
 * p.25 :	t <= 0 to check if intersection point is behind us.
 * p.25 :	iz >= 0 and iz < 1 because wall have size 1.
 * 			size 1 thanks to tab**
 */
void	ft_choose_t(t_data *d, int i, int j)
{
	double	t;
	double	choosen_t;
	int		color;

	choosen_t = 1e30;
	color = 0;
	ft_intersection_north(d, &t, &choosen_t, &color);
	ft_intersection_east(d, &t, &choosen_t, &color);
	ft_intersection_west(d, &t, &choosen_t, &color);
	ft_intersection_south(d, &t, &choosen_t, &color);
	if (color != 0)
		ft_color_pixel(color, i, j, d);
}
