/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:41:28 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 15:24:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
#include "libft.h"

static int	ft_open_texture(t_parsing *parsing)
{
	if (!ft_is_openable(parsing->texture_ea))
		return (ft_error_parsing("texture 'EA'", ERROR_OPEN));
	if (!ft_is_openable(parsing->texture_no))
		return (ft_error_parsing("texture 'NO'", ERROR_OPEN));
	if (!ft_is_openable(parsing->texture_so))
		return (ft_error_parsing("texture 'SO'", ERROR_OPEN));
	if (!ft_is_openable(parsing->texture_we))
		return (ft_error_parsing("texture 'WE'", ERROR_OPEN));
	return (0);
}

static int	ft_check_extension_texture(t_parsing *parsing)
{
	if (!ft_is_good_extension(parsing->texture_ea, ".xpm", 5))
		return (ft_error_parsing("texture 'EA'", ERROR_EXTENSION));
	if (!ft_is_good_extension(parsing->texture_no, ".xpm", 5))
		return (ft_error_parsing("texture 'NO'", ERROR_EXTENSION));
	if (!ft_is_good_extension(parsing->texture_so, ".xpm", 5))
		return (ft_error_parsing("texture 'SO'", ERROR_EXTENSION));
	if (!ft_is_good_extension(parsing->texture_we, ".xpm", 5))
		return (ft_error_parsing("texture 'WE'", ERROR_EXTENSION));
	return (0);
}

int	ft_check_param(t_parsing *parsing)
{
	if (ft_clear_parameters(parsing) != 0)
		return (1);
	if (ft_check_extension_texture(parsing) != 0)
		return (1);
	if (ft_open_texture(parsing) != 0)
		return (1);
	if (ft_check_format_save_color(parsing))
		return (1);
	return (0);
}
