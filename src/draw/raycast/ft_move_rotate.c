/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:57:09 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/23 11:24:52 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <math.h>
#include <stdlib.h>

void	ft_free_rotate_radius(t_radius *all_r, int win_scale)
{
	int	i;

	i = 0;
	if (!all_r->ray)
		return ;
	while (i < win_scale)
	{
		free(all_r->ray[i]);
		i++;
	}
	free(all_r->ray);
	all_r->ray = NULL;
}

/**
 * @brief `calculate matrix z`
 *
 * p.29 : rotation matrix z
 *
 * cos𝜃	-sin𝜃	0
 * sin𝜃	cos𝜃	0
 * 0		0	  1
 *
 */
static void	ft_calculate_rotate_radius(int i, int j, t_exec *e)
{
	t_ray	base;

	base = e->radius.ray[i][j];
	e->all_r.ray [i][j].dir_x = base.dir_x * cos(e->player.angle)
		- base.dir_y * sin(e->player.angle);
	e->all_r.ray [i][j].dir_y = base.dir_x * sin(e->player.angle)
		+ base.dir_y * cos(e->player.angle);
	e->all_r.ray [i][j].dir_z = base.dir_z;
}

/**
 * @brief `rotate in place`
 *
 * p.29 : rotation matrix z
 *
 * cos𝜃	-sin𝜃	0
 * sin𝜃	cos𝜃	0
 * 0		0	  1
 *
 */
int	ft_rotate_radius(t_exec *e, int win_scale)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	e->all_r.ray = NULL;
	e->all_r.ray = malloc(sizeof(t_ray *) * win_scale);
	if (e->all_r.ray == NULL)
		return (-1);
	while (i < win_scale)
	{
		e->all_r.ray[i] = malloc(sizeof(t_ray) * win_scale);
		if (e->all_r.ray[i] == NULL)
			return (-1);
		j = 0;
		while (j < win_scale)
		{
			ft_calculate_rotate_radius(i, j, e);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief `move back and forth`
 */
void	ft_move(t_exec *e)
{
	e->player.dir_x = cos(e->player.angle);
	e->player.dir_y = sin(e->player.angle);
	e->s.cx = e->s.cx + e->player.dir_x * e->player.moove;
	e->s.cy = e->s.cy + e->player.dir_y * e->player.moove;
	e->player.moove = 0;
}
