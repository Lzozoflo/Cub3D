/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 10:01:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

int	ft_check_extension_texture(t_maps *maps)
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

static int	ft_check_param(t_maps *maps)
{
	if (ft_check_extension_texture(maps))
		return (1);
	return (0);
}

static int	ft_parsing_param(t_maps *maps)
{
	int		i;
	int		j;

	i = -1;
	maps->tab = ft_split(maps->file_in_a_line, '\n');
	if (!maps->tab)
		return (-1);
	debug_put_tab("test :", maps->tab, 32, 320);
	while (i++ != 5)
	{
		j = 0;
		while (maps->tab[i][j] && ft_is_white_space(maps->tab[i][j]))
			j++;
		if (ft_find_line_texture(maps, i, j))
			return (-1);
	}
	debug_put_gnl_list("list", maps->gnl, 33, 330);
	return (0);
}

static int	ft_core_parsing(t_maps *maps)
{
	if (ft_parsing_param(maps) == -1)
		return (-1);
	if (ft_check_param(maps))
		return (-1);
	//ici pour le test de la maps
	return (0);
}


int	ft_parsing_cub(t_data *data, char *scene_cub)
{
	int		fd;

	if (!ft_is_good_extension(scene_cub, ".cub", 5))
		return (-1);
	fd = open(scene_cub, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (ft_get_all_file(data, fd, 0) == -1)
	{
		close(fd);
		if (data->maps.file_in_a_line)
			free(data->maps.file_in_a_line);
		return (-1);
	}
	close(fd);
	debug_put_str("ft_parsing_cub", data->maps.file_in_a_line, 31, 310);
	if (ft_core_parsing(&data->maps) == -1)
		return (-1);
	return (0);
}


// int	ft_type_param(t_maps *maps, int i, int j)
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
