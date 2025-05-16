/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:26:06 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 09:57:31 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

static void	ft_init_maps(t_maps *maps)
{
	maps->gnl = NULL;
	maps->file_in_a_line = NULL;
	maps->str_floor = NULL;
	maps->str_sky = NULL;
	maps->tab = NULL;
	maps->texture_ea = NULL;
	maps->texture_no = NULL;
	maps->texture_so = NULL;
	maps->texture_we = NULL;
}

void	ft_init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img.img_ptr = NULL;
	data->img.addr = NULL;
	ft_init_maps(&data->maps);
}
