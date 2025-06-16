/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap_set_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:51:48 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/05 10:58:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include <math.h>

unsigned char check_value(int value)
{
	if (value < 0)
		return (0);
	if (value > 255)
		return (255);
	return ((unsigned char)value);
}

int is_color_used(unsigned int color, t_minimap *m)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (m->color_minimap[i++] == color)
			return 1;
	}
	return 0;
}

unsigned int generate_next_variant(unsigned int b1, unsigned int b2, int i)
{
	t_rgb			base1;
	t_rgb			base2;
	unsigned char	r_new;
	unsigned char	g_new;
	unsigned char	b_new;

	base1.r = (b1>> 16) & 0xFF;
	base1.g = (b1>> 8) & 0xFF;
	base1.b = b1& 0xFF;
	base2.r = (b2>> 16) & 0xFF;
	base2.g = (b2>> 8) & 0xFF;
	base2.b = b2& 0xFF;
	r_new = check_value((((base1.r + base2.g) >> 1) + (i * 21)) % 256 & 0xFF);
	g_new = check_value((((base1.g + base2.b) >> 1) + (i * 42)) % 256 & 0xFF);
	b_new = check_value((((base1.b + base2.r) >> 1) + (i * 4)) % 256 & 0xFF);
	return (r_new << 16 | g_new << 8 | b_new);
}

unsigned int generate_unique_color(unsigned int base , unsigned int base2, t_minimap *m)
{
	unsigned int	variant;
	int				i;

	i = 0;
	while (i < __INT_MAX__)
	{
		variant = generate_next_variant(base, base2, i++);
		if (!is_color_used(variant, m))
			return (variant);
	}
	return (0xFFFFFF);
}

void	t_minimap_set_color(t_exec *exec, t_minimap *m)
{
	m->color_minimap[0] = generate_unique_color(exec->floor,exec->sky, m);
	m->color_minimap[1] = generate_unique_color(exec->floor,exec->sky, m);
	m->color_minimap[2] = generate_unique_color(exec->floor,exec->sky, m);
}
