/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:44:21 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 09:20:49 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"

void	t_pos_set_draw_max(t_pos *pos, int zoom, int x)
{
	int	cal;

	if (zoom == 0)
		cal = WIN_SIZE * 0.015;
	else if (zoom == 1)
		cal = WIN_SIZE * 0.045;
	if (zoom == 0)
	{
		if (!x)
		{
			pos->size = WIN_SIZE * 0.03;
			pos->px_y = cal;
		}
		pos->px_x = cal;
	}
	else if (zoom == 1)
	{
		if (!x)
		{
			pos->size = WIN_SIZE * 0.1;
			pos->px_y = cal;
		}
		pos->px_x = cal;
	}
}
