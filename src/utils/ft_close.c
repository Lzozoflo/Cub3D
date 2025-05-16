/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:46:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 09:58:20 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_clear_maps(t_maps *maps)
{
	if (maps->file_in_a_line)
		free(maps->file_in_a_line);
	if (maps->str_floor)
		free(maps->str_floor);
	if (maps->str_sky)
		free(maps->str_sky);
	if (maps->tab)
		ft_freetab(maps->tab, 0);
	if (maps->texture_ea)
		free(maps->texture_ea);
	if (maps->texture_no)
		free(maps->texture_no);
	if (maps->texture_so)
		free(maps->texture_so);
	if (maps->texture_we)
		free(maps->texture_we);
	if (maps->gnl)
		t_gnl_clear(maps);
}


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
	ft_clear_maps(&data->maps);
	printf("Exiting program.\n");
	exit(error);
}

int	ft_cross(t_data *data)
{
	mlx_loop_end(data->mlx);
	ft_clean_close(data, 0);
	exit (0);
}
