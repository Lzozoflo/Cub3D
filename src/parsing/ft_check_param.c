/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:41:28 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 09:48:52 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
// #include "ft_debug.h"
#include "libft.h"

static int	ft_open_texture(t_maps *maps)
{
	if (!ft_is_openable(maps->texture_ea))
		return (ft_error_parsing("texture 'EA' can't be open.\n", NULL));
	if (!ft_is_openable(maps->texture_no))
		return (ft_error_parsing("texture 'NO' can't be open.\n", NULL));
	if (!ft_is_openable(maps->texture_so))
		return (ft_error_parsing("texture 'SO' can't be open.\n", NULL));
	if (!ft_is_openable(maps->texture_we))
		return (ft_error_parsing("texture 'WE' can't be open.\n", NULL));
	return (0);
}

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
	if (ft_clear_parameters(maps) != 0)
		return (1);
	if (ft_check_extension_texture(maps) != 0)
		return (1);
	if (ft_open_texture(maps) != 0)
		return (1);
	if (ft_check_format_save_color(maps))
		return (1);
	return (0);
}
