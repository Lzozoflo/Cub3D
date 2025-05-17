/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:26:06 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:04:09 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

static void	ft_init_parsing(t_parsing *parsing)
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
}
