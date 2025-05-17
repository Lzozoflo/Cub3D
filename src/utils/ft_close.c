/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:46:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 19:03:48 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_clear_exec(t_exec *exec)
{
	if (exec->tab)
		ft_freetab(exec->tab, 0);
	if (exec->texture_ea)
		free(exec->texture_ea);
	if (exec->texture_no)
		free(exec->texture_no);
	if (exec->texture_so)
		free(exec->texture_so);
	if (exec->texture_we)
		free(exec->texture_we);
}

void	ft_clear_parsing(t_parsing *parsing)
{
	if (parsing->file_in_a_line)
		free(parsing->file_in_a_line);
	if (parsing->str_floor)
		free(parsing->str_floor);
	if (parsing->str_sky)
		free(parsing->str_sky);
	if (parsing->tab)
		ft_freetab(parsing->tab, 0);
	if (parsing->dup_check)
		ft_freetab(parsing->dup_check, 0);
	if (parsing->texture_ea)
		free(parsing->texture_ea);
	if (parsing->texture_no)
		free(parsing->texture_no);
	if (parsing->texture_so)
		free(parsing->texture_so);
	if (parsing->texture_we)
		free(parsing->texture_we);
	if (parsing->gnl)
		t_gnl_clear(parsing);
	ft_init_parsing(parsing);
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
