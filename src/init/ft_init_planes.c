/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_planes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathildelaussel <mathildelaussel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:17 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/11 15:12:47 by mathildelau      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_west_plane(t_cardinals *c, int x)
{
	c->w[x].a = 1;
	c->w[x].b = 0;
	c->w[x].c = 0;
	c->w[x].d = -x;
}

void	ft_east_plane(t_cardinals *c, int x)
{
	c->e[x].a = 1;
	c->e[x].b = 0;
	c->e[x].c = 0;
	c->e[x].d = -(x + 1);
}

void	ft_north_plane(t_cardinals *c, int y)
{
	c->n[y].a = 0;
	c->n[y].b = 1;
	c->n[y].c = 0;
	c->n[y].d = -y;
}

void	ft_south_plane(t_cardinals *c, int y)
{
	c->s[y].a = 0;
	c->s[y].b = 1;
	c->s[y].c = 0;
	c->s[y].d = -(y + 1);
}
