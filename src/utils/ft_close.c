/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:46:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/23 12:41:50 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_clean_close(t_data *data, int error)
{
	ft_destroy_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_clear_parsing(&data->parsing);
	ft_clear_exec(&data->exec);
	ft_free_cardi(&data->exec);
	ft_free_radius(&data->exec.radius, data->win_scale);
	ft_free_rotate_radius(&data->exec.all_r, data->win_scale);
	printf("Exiting program.\n");
	exit(error);
}

int	ft_cross(t_data *data)
{
	mlx_loop_end(data->mlx);
	ft_clean_close(data, 0);
	exit (0);
}
