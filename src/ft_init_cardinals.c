/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cardinals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:40:01 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 10:11:32 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "stdlib.h"

void	ft_west(t_cardinals *c, int x)
{
	c->w.a = 1;
	c->w.b = 0;
	c->w.c = 0;
	c->w.d = -x;
}

void	ft_east(t_cardinals *c, int x)
{
	c->e.a = 1;
	c->e.b = 0;
	c->e.c = 0;
	c->e.d = -(x + 1);
}

void	ft_north(t_cardinals *c, int y)
{
	c->n.a = 0;
	c->n.b = 1;
	c->n.c = 0;
	c->n.d = -y;
}

void	ft_south(t_cardinals *c, int y)
{
	c->s.a = 0;
	c->s.b = 1;
	c->s.c = 0;
	c->s.d = -(y + 1);
}
