/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:48:13 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/05 12:24:42 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

// static void	ft_clear_image(t_image *img)
// {
// 	if (img->img_ptr)
// 		free();
// 	if (img->addr)

// }

static void	ft_clear_texture(t_texture *texture)
{
	if (texture->texture_ea)
		free(texture->texture_ea);
	if (texture->texture_no)
		free(texture->texture_no);
	if (texture->texture_so)
		free(texture->texture_so);
	if (texture->texture_we)
		free(texture->texture_we);
}

void	ft_clear_exec(t_exec *exec)
{
	if (exec->tab)
		ft_freetab(exec->tab, 0);
	ft_clear_texture(&exec->texture);
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
