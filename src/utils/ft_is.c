/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:16:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 09:47:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

int	ft_is_player_move(int keycode)
{
	if (keycode == A || keycode == W || keycode == D ||keycode == S)
		return (1);
	return (0);
}


int	ft_is_camera_move(int keycode)
{
	if (keycode == LEFT || keycode == RIGHT)
		return (1);
	return (0);
}
