/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_radius.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:07:54 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/25 12:23:42 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <stdlib.h>

static void	ft_free_ray(int i, t_exec *e)
{
	while (i > 0)
	{
		free(e->radius.ray[i]);
		e->radius.ray[i] = NULL;
		i--;
	}
	free(e->radius.ray);
	e->radius.ray = NULL;
}

/**
 * @brief `calculate all radius for opti`
 *
 * `(p.15) - double loop` :"To create our direction vectors,
 * we simply need to put an increment on the x (which we will call i)
 * and another for the y (j)."
 *
 * `(p.30) - Radius precalculation`
 * "First, it is very important to calculate the radii beforehand.
 * As shown here, radii can be calculated before the graph loop.
 * We therefore create them with a North orientation and then simply
 * turn the ray towards our direction just before using it in the algorithm.
 * This saves all the creation time during the loop."
 */
int	ft_calculate_all_radius(t_exec *e, int win_scale)
{
	int	i;
	int	j;

	i = 0;
	e->radius.ray = malloc(sizeof(t_ray *) * win_scale);
	if (e->radius.ray == NULL)
		return (-1);
	while (i < win_scale)
	{
		e->radius.ray[i] = malloc(sizeof(t_ray) * win_scale);
		if (e->radius.ray[i] == NULL)
		{
			ft_free_ray(i, e);
			return (-1);
		}
		j = 0;
		while (j < win_scale)
		{
			ft_director_vector(e, i, j, win_scale);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free_radius(t_radius *r, int win_scale)
{
	int	i;

	if (!r->ray)
		return ;
	i = 0;
	while (i < win_scale)
	{
		if (r->ray[i])
			free(r->ray[i]);
		i++;
	}
	free(r->ray);
	r->ray = NULL;
}
