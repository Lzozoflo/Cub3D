/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cardinals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:40:01 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/03 09:54:51 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "stdlib.h"

void	ft_west(t_cardinals *c, int index, int x)
{
	c->w[index].a = 1;
	c->w[index].b = 0;
	c->w[index].c = 0;
	c->w[index].d = -x;
}

void	ft_east(t_cardinals *c, int index, int x)
{
	c->e[index].a = 1;
	c->e[index].b = 0;
	c->e[index].c = 0;
	c->e[index].d = -(x + 1);
}

void	ft_north(t_cardinals *c, int index, int y)
{
	c->n[index].a = 0;
	c->n[index].b = 1;
	c->n[index].c = 0;
	c->n[index].d = -y;
}

void	ft_south(t_cardinals *c, int index, int y)
{
	c->s[index].a = 0;
	c->s[index].b = 1;
	c->s[index].c = 0;
	c->s[index].d = -(y + 1);
}

int	ft_malloc_cardi(t_data *d)
{
	d->exec.cardi.n = malloc(sizeof(t_plane) * (d->exec.max_height) + 1);
	if (d->exec.cardi.n == NULL)
		return (-1);
	d->exec.cardi.s = malloc(sizeof(t_plane) * (d->exec.max_height) + 1);
	if (d->exec.cardi.s == NULL)
		return (-1);
	d->exec.cardi.w = malloc(sizeof(t_plane) * (d->exec.max_width) + 1);
	if (d->exec.cardi.w == NULL)
		return (-1);
	d->exec.cardi.e = malloc(sizeof(t_plane) * (d->exec.max_width) + 1);
	if (d->exec.cardi.e == NULL)
		return (-1);
	return (0);
}
