/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:32:57 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 10:44:15 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

/**
 * @brief `check north wall`
 *
 * p.31 at the end :
 *
 * N(Ix, -d - 1)
 *
 * S(Ix, -d)
 *
 * E(-d, Iy)
 *
 * W(-d - 1, Iy).
 */
int	ft_check_north(t_data *d)
{
	int	x;
	int	y;

	x = (int)d->exec.s.ix;
	y = -((int)d->exec.cardi.n.d) - 1;
	if (x < 0 || x > d->exec.max_width || y < 0 || y > d->exec.max_height)
		return (0);
	return (1);
}

/**
 * @brief `check north wall`
 *
 * p.31 at the end :
 *
 * N(Ix, -d - 1)
 *
 * S(Ix, -d)
 *
 * E(-d, Iy)
 *
 * W(-d - 1, Iy).
 */
int	ft_check_south(t_data *d)
{
	int	x;
	int	y;

	x = (int)d->exec.s.ix;
	y = -((int)d->exec.cardi.s.d);
	if (x < 0 || x > d->exec.max_width || y < 0 || y > d->exec.max_height)
		return (0);
	return (1);
}

/**
 * @brief `check north wall`
 *
 * p.31 at the end :
 *
 * N(Ix, -d - 1)
 *
 * S(Ix, -d)
 *
 * E(-d, Iy)
 *
 * W(-d - 1, Iy).
 */
int	ft_check_east(t_data *d)
{
	int	x;
	int	y;

	x = -((int)d->exec.cardi.e.d);
	y = (int)d->exec.s.iy;
	if (x < 0 || x > d->exec.max_width || y < 0 || y > d->exec.max_height)
		return (0);
	return (1);
}

/**
 * @brief `check north wall`
 *
 * p.31 at the end :
 *
 * N(Ix, -d - 1)
 *
 * S(Ix, -d)
 *
 * E(-d, Iy)
 *
 * W(-d - 1, Iy).
 */
int	ft_check_west(t_data *d)
{
	int	x;
	int	y;

	x = -((int)d->exec.cardi.e.d) - 1;
	y = (int)d->exec.s.iy;
	if (x < 0 || x > d->exec.max_width || y < 0 || y > d->exec.max_height)
		return (0);
	return (1);
}
