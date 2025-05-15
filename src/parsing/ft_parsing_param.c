/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:41:28 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 11:44:10 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

static int	ft_check_extension_texture(t_maps *maps)
{
	if (!ft_is_good_extension(maps->texture_ea, ".xpm", 5))
		return (ft_error_parsing("texture 'EA' has a bad extension.\n", NULL));
	if (!ft_is_good_extension(maps->texture_no, ".xpm", 5))
		return (ft_error_parsing("texture 'NO' has a bad extension.\n", NULL));
	if (!ft_is_good_extension(maps->texture_so, ".xpm", 5))
		return (ft_error_parsing("texture 'SO' has a bad extension.\n", NULL));
	if (!ft_is_good_extension(maps->texture_we, ".xpm", 5))
		return (ft_error_parsing("texture 'WE' has a bad extension.\n", NULL));
	return (0);
}

int	ft_check_param(t_maps *maps)
{
	if (ft_check_extension_texture(maps) != 0)
		return (1);
	// if (ft_open_texture(maps) != 0)
	// 	return (1);
	// if (ft_check_rgb(maps))
	// 	return (1);
	return (0);
}

int	ft_parsing_param(t_maps *maps)
{
	int		i;
	int		j;

	i = -1;
	maps->tab = ft_split(maps->file_in_a_line, '\n');
	if (!maps->tab)
		return (1);
	debug_put_tab("test :", maps->tab, 32, 320);
	while (i++ != 5)
	{
		j = 0;
		while (maps->tab[i][j] && ft_is_white_space(maps->tab[i][j]))
			j++;
		if (ft_find_line_texture(maps, i, j) != 0)
			return (1);
	}
	debug_put_gnl_list("list", maps->gnl, 33, 330);
	return (0);
}
