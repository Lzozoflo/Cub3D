/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_radius.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:07:54 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/18 12:29:12 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <stdlib.h>
#include <math.h>

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
int	ft_calculate_all_radius(t_exec *e)
{
	int	i;
	int	j;

	i = 0;
	e->radius.ray = NULL;
	e->radius.ray = malloc(sizeof(t_ray *) * (WIN_SIZE / SCALE));
	if (e->radius.ray == NULL)
		return (-1);
	while (i < (WIN_SIZE / SCALE))
	{
		e->radius.ray[i] = malloc(sizeof(t_ray) * (WIN_SIZE / SCALE));
		if (e->radius.ray[i] == NULL)
			return (-1);
		j = 0;
		while (j < (WIN_SIZE / SCALE))
		{
			//ft_director_vector2(e, i, j);
			ft_director_vector(e, &e->player, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free_radius(t_radius *r)
{
	int	i;

	if (r->ray)
		return ;
	i = 0;
	while (i < (WIN_SIZE / SCALE))
	{
		if (r->ray[i])
			free(r->ray[i]);
		i++;
	}
	free(r->ray);
	r->ray = NULL;
}
