/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:44:21 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 15:25:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"


void	t_pos_set_draw_max(t_pos *pos, int zoom, int x)
{
	if (!zoom)
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
			pos->size = WIN_SIZE / 10;
			pos->px_y = 100;
		}
		pos->px_x = 100;
	}
}
