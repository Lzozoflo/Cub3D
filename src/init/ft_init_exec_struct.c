/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_exec_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:22:43 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/23 13:54:58 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

void	ft_init_keys(t_exec *exec)
{
	exec->keys.w = 0;
	exec->keys.a = 0;
	exec->keys.s = 0;
	exec->keys.d = 0;
	exec->keys.left = 0;
	exec->keys.right = 0;
	// exec->keys.up = 0; // ICI
	// exec->keys.down = 0;
	exec->keys.m = 0;
}

void	ft_init_textures_img(t_exec *exec)
{
	exec->texture.north.img_ptr = NULL;
	exec->texture.south.img_ptr = NULL;
	exec->texture.east.img_ptr = NULL;
	exec->texture.west.img_ptr = NULL;
}

void	ft_init_cardi(t_exec *exec)
{
	exec->cardi.n = NULL;
	exec->cardi.s = NULL;
	exec->cardi.w = NULL;
	exec->cardi.e = NULL;
}

void	ft_init_ray(t_exec *exec)
{
	exec->radius.ray = NULL;
	exec->all_r.ray = NULL;
}
