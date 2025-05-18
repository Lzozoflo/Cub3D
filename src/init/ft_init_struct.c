/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:26:06 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 15:13:10 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

static void	ft_init_texture(t_texture *texture)
{
	texture->texture_ea = NULL;
	texture->texture_no = NULL;
	texture->texture_so = NULL;
	texture->texture_we = NULL;
}

static void	ft_init_player(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->pos_x = 0;
	player->pos_y = 0;
}

static void	ft_init_exec(t_exec *exec)
{
	exec->floor = 0;
	exec->max_height = 0;
	exec->max_width = 0;
	exec->zoom = -1;
	exec->sky = 0;
	exec->tab = NULL;
	ft_init_texture(&exec->texture);
	ft_init_player(&exec->player);
}

void	ft_init_parsing(t_parsing *parsing)
{
	parsing->gnl = NULL;
	parsing->file_in_a_line = NULL;
	parsing->str_floor = NULL;
	parsing->str_sky = NULL;
	parsing->tab = NULL;
	parsing->dup_check = NULL;
	parsing->texture_ea = NULL;
	parsing->texture_no = NULL;
	parsing->texture_so = NULL;
	parsing->texture_we = NULL;
	parsing->max_height = 0;
	parsing->max_width = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img.img_ptr = NULL;
	data->img.addr = NULL;
	ft_init_parsing(&data->parsing);
	ft_init_exec(&data->exec);
}
