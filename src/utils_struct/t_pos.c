/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:44:21 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 12:37:20 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

// t_pos	t_pos_set(int y, int x, int size)
// {
// 	t_pos	pos;

// 	pos.size = size;
// 	pos.px_x = x;
// 	pos.px_y = y;
// 	pos.while_x = 9;
// 	pos.while_y = 9;
// 	return (pos);
// }

void	t_pos_set_draw_max(t_pos *pos, int zoom, int x)
{
	if (!x)
		pos->while_y = 9;
	pos->while_x = 9;
	if (zoom)
	{
		if (!x)
		{
			pos->size = 20;
			pos->px_y = 50;
		}
		pos->px_x = 50;
	}
	else
	{
		if (!x)
		{
			pos->size = WIN_SIZE / 10;//
			pos->px_y = 100;
		}
		pos->px_x = 100;
	}
}
