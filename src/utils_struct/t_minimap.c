/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minimap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 09:44:21 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 09:20:49 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"

// void	t_minimap_set_draw_max(t_minimap *mini, int zoom, int x)
// {
// 	int	base_pos;

// 	if (zoom == 0)
// 		base_pos = WIN_SIZE * 0.015;
// 	else if (zoom == 1)
// 		base_pos = WIN_SIZE * 0.045;
// 	if (zoom == 0)
// 	{
// 		if (!x)
// 		{
// 			mini->size = WIN_SIZE * 0.03;
// 			mini->px_y = base_pos;
// 		}
// 		mini->px_x = base_pos;
// 	}
// 	else if (zoom == 1)
// 	{
// 		if (!x)
// 		{
// 			mini->size = WIN_SIZE * 0.1;
// 			mini->px_y = base_pos;
// 		}
// 		mini->px_x = base_pos;
// 	}
// }
