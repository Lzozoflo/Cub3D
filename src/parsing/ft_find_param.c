/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:23:09 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 15:24:58 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include "libft.h"
#include <fcntl.h>

static int	ft_check_double(char **str, char *str_int_tab, char *find)
{
	if (*str)
		return (ft_error_parsing(ERROR_DOUBLE_PARAM, find));
	*str = ft_strdup(str_int_tab);
	if (!*str)
		return (1);
	return (0);
}

static int	ft_find_line_floor_sky_or_error(t_parsing *parsing, int i, int j)
{
	if (ft_strncmp(&parsing->tab[i][j], "F ", 2) == 0)
	{
		if (ft_check_double(&parsing->str_floor, parsing->tab[i], "F "))
			return (1);
	}
	else if (ft_strncmp(&parsing->tab[i][j], "C ", 2) == 0)
	{
		if (ft_check_double(&parsing->str_sky, parsing->tab[i], "C "))
			return (1);
	}
	else
		return (ft_error_parsing(ERROR_BAD_PARAM, NULL));
	return (0);
}

int	ft_find_line_texture(t_parsing *parsing, int i, int j)
{
	if (ft_strncmp(&parsing->tab[i][j], "EA ", 3) == 0)
	{
		if (ft_check_double(&parsing->texture_ea, parsing->tab[i], "EA "))
			return (1);
	}
	else if (ft_strncmp(&parsing->tab[i][j], "NO ", 3) == 0)
	{
		if (ft_check_double(&parsing->texture_no, parsing->tab[i], "NO "))
			return (1);
	}
	else if (ft_strncmp(&parsing->tab[i][j], "SO ", 3) == 0)
	{
		if (ft_check_double(&parsing->texture_so, parsing->tab[i], "SO "))
			return (1);
	}
	else if (ft_strncmp(&parsing->tab[i][j], "WE ", 3) == 0)
	{
		if (ft_check_double(&parsing->texture_we, parsing->tab[i], "WE "))
			return (1);
	}
	else if (ft_find_line_floor_sky_or_error(parsing, i, j))
		return (1);
	return (0);
}

// int	ft_type_param(t_parsing *maps, int i, int j)
// {
// 	ft_putstr(&maps->tab[i][j]);
// 	if (ft_strncmp(&maps->tab[i][j], "F ", 2) == 0)
// 	{
// 		if (maps->floor)
// 			return (ft_error_parsing("double F\n", NULL));
// 		maps->floor = ft_strdup(maps->tab[i]);
// 		if (!maps->floor)
// 			return (1);
// 	}
// 	else if (ft_strncmp(&maps->tab[i][j], "C ", 2) == 0)
// 	{
// 		if (maps->sky)
// 			return (ft_error_parsing("double C\n", NULL));
// 		maps->sky = ft_strdup(maps->tab[i]);
// 		if (!maps->sky)
// 			return (1);
// 	}
// 	else if (ft_strncmp(&maps->tab[i][j], "EA ", 3) == 0)
// 	{
// 		if (maps->texture_ea)
// 			return (ft_error_parsing("double EA\n", NULL));
// 		maps->texture_ea = ft_strdup(maps->tab[i]);
// 		if (!maps->texture_ea)
// 			return (1);
// 	}
// 	else if (ft_strncmp(&maps->tab[i][j], "NO ", 3) == 0)
// 	{
// 		if (maps->texture_no)
// 			return (ft_error_parsing("double NO\n", NULL));
// 		maps->texture_no = ft_strdup(maps->tab[i]);
// 		if (!maps->texture_no)
// 			return (1);
// 	}
// 	else if (ft_strncmp(&maps->tab[i][j], "SO ", 3) == 0)
// 	{
// 		if (maps->texture_so)
// 			return (ft_error_parsing("double SO\n", NULL));
// 		maps->texture_so = ft_strdup(maps->tab[i]);
// 		if (!maps->texture_so)
// 			return (1);
// 	}
// 	else if (ft_strncmp(&maps->tab[i][j], "WE ", 3) == 0)
// 	{
// 		if (maps->texture_we)
// 			return (ft_error_parsing("double WE\n", NULL));
// 		maps->texture_we = ft_strdup(maps->tab[i]);
// 		if (!maps->texture_we)
// 			return (1);
// 	}
// 	else
// 		return (ft_error_parsing("Bad paramaters\n", NULL));
// 	return (0);
// }
