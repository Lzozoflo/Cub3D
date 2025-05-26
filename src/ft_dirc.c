/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:04:03 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/26 12:23:52 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

void	ft_init_point(t_exec *e)
{
	e->s.nx = 0;
	e->s.ny = 1;
	e->s.nx2 = 0;
	e->s.ny2 = 3;
	e->s.ex = 1;
	e->s.ey = 0;
	e->s.ex2 = 0;
	e->s.ey2 = -3;
	e->s.ox = 1;
	e->s.oy = 0;
	e->s.ox2 = 0;
	e->s.oy2 = 3;
	e->s.sx = 0;
	e->s.sy = 1;
	e->s.sx2 = 0;
	e->s.sy2 = -3;
}
