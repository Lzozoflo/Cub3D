/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:04:03 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/26 11:09:51 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>
#include <stdio.h> ////DELETE

void	ft_north(t_exec *e, t_data *d)
{
	(void)d;
	e->s.nx = 0;
	e->s.ny = 1;
	e->s.nx2 = 0;
	e->s.ny2 = 3;
}

void	ft_east(t_exec *e, t_data *d)
{
	(void)d;
	e->s.ex = 1;
	e->s.ey = 0;
	e->s.ex2 = 0;
	e->s.ey2 = -3;
}

void	ft_west(t_exec *e, t_data *d)
{
	(void)d;
	e->s.ox = 1;
	e->s.oy = 0;
	e->s.ox2 = 0;
	e->s.oy2 = 3;
}

void	ft_south(t_exec *e, t_data *d)
{
	e->s.sx = 0;
	e->s.sy = 1;
	e->s.sx2 = 0;
	e->s.sy2 = -3;
	(void)d;
}
