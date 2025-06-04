/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_planes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:17 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/04 16:40:58 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "stdlib.h"

void	ft_west(t_cardinals *c, int x)
{
	c->w[x].a = 1;
	c->w[x].b = 0;
	c->w[x].c = 0;
	c->w[x].d = -x;
}

void	ft_east(t_cardinals *c, int x)
{
	c->e[x].a = 1;
	c->e[x].b = 0;
	c->e[x].c = 0;
	c->e[x].d = -(x + 1);
}

void	ft_north(t_cardinals *c, int y)
{
	c->n[y].a = 0;
	c->n[y].b = 1;
	c->n[y].c = 0;
	c->n[y].d = -y;
}

void	ft_south(t_cardinals *c, int y)
{
	c->s[y].a = 0;
	c->s[y].b = 1;
	c->s[y].c = 0;
	c->s[y].d = -(y + 1);
}
