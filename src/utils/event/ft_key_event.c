/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:59:35 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/10 16:48:33 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

static int	ft_wasd(int keycode, t_data *data)
{
	if (keycode == W)
	{
		debug_put_str("[w] is pressed", NULL, 2, 21);
	}
	else if (keycode == A)
	{
		debug_put_str("[a] is pressed", NULL, 2, 21);
	}
	else if (keycode == S)
	{
		debug_put_str("[s] is pressed", NULL, 2, 21);
	}
	else if (keycode == D)
	{
		debug_put_str("[d] is pressed", NULL, 2, 21);
	}
	return (1);
}

int	ft_key_press(int keycode, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	debug_put_int("ft_key_press -> keycode", keycode, 21, 210);
	if (keycode == ESC)
	{
		mlx_loop_end(data->mlx);
		ft_clean_close(data, 0);
	}
	if (ft_wasd(keycode, data) == -1)
		return (-1);
	return (1);
}
