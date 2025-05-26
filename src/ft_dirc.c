/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:04:03 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/26 16:36:22 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

void	ft_init_point(t_exec *e)
{
	e->s.n.a = 0;
	e->s.n.b= 1;
	e->s.n.c = 0;
	e->s.n.d = 3;
	e->s.e.a = 1;
	e->s.e.b = 0;
	e->s.e.c = 0;
	e->s.e.d = -3;
	e->s.w.a = 1;
	e->s.w.b = 0;
	e->s.w.c = 0;
	e->s.w.d = 3;
	e->s.s.a = 0;
	e->s.s.b = 1;
	e->s.s.c = 0;
	e->s.s.d = -3;
}
