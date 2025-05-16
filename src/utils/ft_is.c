/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:16:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 14:35:50 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

inline int	ft_is_player_char(int c)
{
	return (c == 'E' || c == 'N' || c == 'S' || c == 'W');
}

inline int	ft_is_valid_char(int c)
{
	return (c != '\0' && (c == '1' || c == '0' || c == ' '
			|| ft_is_player_char(c)));
}

inline int	ft_is_player_move(int keycode)
{
	return (keycode == A || keycode == W || keycode == D ||keycode == S);
}


inline int	ft_is_camera_move(int keycode)
{
	return (keycode == LEFT || keycode == RIGHT);
}
