/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:16:30 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/04 10:18:01 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

static int	ft_intersection_north(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 'n');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0 && ft_check_north(d) == 1)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = ft_texture(d, 'n');
				return (1);
			}
		}
	}
	return (0);
}

static int	ft_intersection_east(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 'e');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0 && ft_check_east(d) == 1)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = ft_texture(d, 'e');
				return (1);
			}
		}
	}
	return (0);
}

static int	ft_intersection_west(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 'w');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0 && ft_check_west(d) == 1)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = ft_texture(d, 'w');
				return (1);
			}
		}
	}
	return (0);
}

static int	ft_intersection_south(t_data *d, double *t, double *choosen_t,
		int *color)
{
	*t = ft_find_t(&d->exec, 's');
	if (*t > 0.0)
	{
		ft_intersection_coord(&d->exec, *t);
		if (d->exec.s.iz >= 0.0 && d->exec.s.iz < 1.0 && ft_check_south(d) == 1)
		{
			if (*t < *choosen_t)
			{
				*choosen_t = *t;
				*color = ft_texture(d, 's');
				return (1);
			}
		}
	}
	return (0);
}

/**
 * @brief `if intersection, color + find the nearest t`
 *
 * p.30 :	"So, simply stop at the first wall and compare
 * the distance (t) of the closest wall on the x-axis with
 * the one closest to the y-axis. We can therefore display
 * a different color/texture depending on the cardinal point."
 *
 * p.25 :	t <= 0 to check if intersection point is behind us.
 *
 * p.25 :	iz >= 0 and iz < 1 because wall have size 1.
 * 			size 1 thanks to tab**
 */
void	ft_choose_t(t_data *d, int i, int j)
{
	double	t;
	double	choosen_t;
	int		color;

	choosen_t = 1e30;
	if (ft_intersection_north(d, &t, &choosen_t, &color) == 1)
	{
		ft_color_pixel(color, i, j, d);
		return ;
	}
	if (ft_intersection_east(d, &t, &choosen_t, &color) == 1)
	{
		ft_color_pixel(color, i, j, d);
		return ;
	}
	if (ft_intersection_west(d, &t, &choosen_t, &color) == 1)
	{
		ft_color_pixel(color, i, j, d);
		return ;
	}
	if (ft_intersection_south(d, &t, &choosen_t, &color) == 1)
	{
		ft_color_pixel(color, i, j, d);
		return ;
	}
}
