/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:20:02 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 15:25:15 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"

void	ft_color_pixel(int color, int x, int y, t_data *data)
{
	t_image	img;
	int		index;

	if (x < 0 || y < 0 || x >= WIN_SIZE || y >= WIN_SIZE)
		return ;
	img = data->img;
	index = (y * img.line_len) + (x * (img.bpp));
	*(unsigned int *)(data->img.addr + index) = color;
}
