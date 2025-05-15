/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:23:09 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 09:26:59 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

static int	ft_check_double(char **str, char *str_int_tab, char *find)
{
	if (*str)
		return (ft_error_parsing(find, "was found 2 time\n"));
	*str = ft_strdup(str_int_tab);
	if (!*str)
		return (1);
	return (0);
}

static int	ft_find_line_floor_sky_or_error(t_maps *maps, int i, int j)
{

	if (ft_strncmp(&maps->tab[i][j], "F ", 2) == 0)
	{
		if (ft_check_double(&maps->floor, maps->tab[i], "F "))
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "C ", 2) == 0)
	{
		if (ft_check_double(&maps->sky, maps->tab[i], "C "))
			return (1);
	}
	else
		return (ft_error_parsing("Bad paramaters\n", NULL));
	return (0);
}

int	ft_find_line_texture(t_maps *maps, int i, int j)
{
	if (ft_strncmp(&maps->tab[i][j], "EA ", 3) == 0)
	{
		if (ft_check_double(&maps->texture_ea, maps->tab[i], "EA "))
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "NO ", 3) == 0)
	{
		if (ft_check_double(&maps->texture_no, maps->tab[i], "NO "))
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "SO ", 3) == 0)
	{
		if (ft_check_double(&maps->texture_so, maps->tab[i], "SO "))
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "WE ", 3) == 0)
	{
		if (ft_check_double(&maps->texture_we, maps->tab[i], "WE "))
			return (1);
	}
	else if (ft_find_line_floor_sky_or_error(maps, i, j))
		return (1);
	return (0);
}
