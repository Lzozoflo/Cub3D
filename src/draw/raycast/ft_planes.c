/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_planes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:36:49 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/23 13:07:34 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <stdlib.h>

/**
 * @brief `malloc struct t_plane`
 *
 * p.30 : "Wall storage
 * To think about optimization now, it is best to create 4 plan tables,
 * 1 for each orientation (N, S, E and W).
 * There will therefore be 2 tables of size w + 1 (E and W)
 * and 2 tables of size h + 1 (N and S)"
 */
int	ft_init_plane(t_exec *e)
{
	e->cardi.n = malloc(sizeof(t_plane) * (e->max_height + 1));
	if (e->cardi.n == NULL)
		return (-1);
	e->cardi.s = malloc(sizeof(t_plane) * (e->max_height + 1));
	if (e->cardi.s == NULL)
		return (-1);
	e->cardi.e = malloc(sizeof(t_plane) * (e->max_width + 1));
	if (e->cardi.e == NULL)
		return (-1);
	e->cardi.w = malloc(sizeof(t_plane) * (e->max_width + 1));
	if( e->cardi.w == NULL)
		return (-1);
	return (1);
}

/**
 * @brief `free struct t_plane`
 *
 */
void	ft_free_cardi(t_exec *e)
{
	if (e->cardi.n != NULL)
		free(e->cardi.n);
	if (e->cardi.s != NULL)
		free(e->cardi.s);
	if (e->cardi.e != NULL)
		free(e->cardi.e);
	if (e->cardi.w != NULL)
		free(e->cardi.w);
	e->cardi.n = NULL;
	e->cardi.s = NULL;
	e->cardi.e = NULL;
	e->cardi.w = NULL;
}

/**
 * @brief `create all possible plane`
 *
 * p.30 : "Wall storage
 * To think about optimization now, it is best to create 4 plan tables,
 * 1 for each orientation (N, S, E and W).
 * There will therefore be 2 tables of size w + 1 (E and W)
 * and 2 tables of size h + 1 (N and S)"
 *
 */
void	ft_group_all_planes(t_data *d)
{
	int	p;

	p = 0;
	while (p < d->exec.max_height)
	{
		ft_north_plane(&d->exec.cardi, p);
		ft_south_plane(&d->exec.cardi, p);
		p++;
	}
	p = 0;
	while (p < d->exec.max_width)
	{
		ft_east_plane(&d->exec.cardi, p);
		ft_west_plane(&d->exec.cardi, p);
		p++;
	}
}
