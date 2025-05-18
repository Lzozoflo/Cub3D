/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:07:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 16:18:44 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"

void	ft_draw_circle(t_data *data, int cx, int cy, int radius)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				ft_color_pixel(PX_GRAY_DARK, cx + x, cy + y, data);
			x++;
		}
		y++;
	}
}



void	ft_draw_player(t_data *data)
{
	const int	center = WIN_SIZE >> 1;




}

