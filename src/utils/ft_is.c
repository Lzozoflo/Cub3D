/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:16:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/13 10:24:25 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

int	ft_is_a_good_extension(char *scene_cub)
{
	size_t	len;

	len = ft_strlen(scene_cub);
	if (ft_strncmp(".cub", &scene_cub[len - 4], 5) == 0)
		return (1);
	ft_error_parsing(scene_cub, ": is not a good extension\n");//msg a revoir
	return (0);
}

int	ft_is_player_move(int keycode)
{
	if (keycode == A || keycode == W || keycode == D ||keycode == S)
		return (1);
	return (0);
}


int	ft_is_camera_move(int keycode)
{
	if (keycode == LEFT || keycode == UP || keycode == RIGHT || keycode == DOWN)
		return (1);
	return (0);
}
