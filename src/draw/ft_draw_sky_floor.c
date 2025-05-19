/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sky_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:37:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 09:50:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

void	ft_draw_sky_floor(t_data *data)
{
	const unsigned int	colorsky = data->exec.sky;
	const unsigned int	colorfloor = data->exec.floor;
	const size_t		size = WIN_SIZE >> 1;
	size_t				y;
	int					x;

	y = 0;
	while (y <= size && y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
			ft_color_pixel(colorsky, x, y, data);
		y++;
	}
	while (y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
			ft_color_pixel(colorfloor, x, y, data);
		y++;
	}
}
