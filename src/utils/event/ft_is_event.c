/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:19:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 15:35:50 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_define.h"

inline int	ft_is_player_move(int keycode)
{
	return (keycode == A || keycode == W || keycode == D || keycode == S);
}

inline int	ft_is_camera_move(int keycode)
{
	return (keycode == LEFT || keycode == RIGHT);
}
