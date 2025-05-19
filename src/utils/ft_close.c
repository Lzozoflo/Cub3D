/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:46:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 09:20:17 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_clean_close(t_data *data, int error)
{
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
	printf("Exiting program.\n");
	exit(error);
}

int	ft_cross(t_data *data)
{
	mlx_loop_end(data->mlx);
	ft_clean_close(data, 0);
	exit (0);
}
