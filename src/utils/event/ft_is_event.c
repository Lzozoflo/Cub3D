/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:19:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/26 12:24:37 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_define.h"

int	ft_is_player_move(int keycode)
{
	return (keycode == A || keycode == W || keycode == D || keycode == S);
}

int	ft_is_camera_move(int keycode)
{
	return (keycode == LEFT || keycode == RIGHT);
}

int	ft_is_refresh_event(int keycode)
{
	return (ft_is_player_move(keycode) || ft_is_camera_move(keycode)
		|| keycode == M);
}
