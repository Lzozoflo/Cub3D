/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 15:23:00 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

static void	ft_keep_and_trash_params(t_maps *maps)
{
	if (maps->file_in_a_line)
		free(maps->file_in_a_line);
	if (maps->str_floor)
		free(maps->str_floor);
	if (maps->str_sky)
		free(maps->str_sky);
	if (maps->gnl)
		t_gnl_clear(maps);
	maps->file_in_a_line = NULL;
	maps->str_floor = NULL;
	maps->str_sky = NULL;
	maps->gnl = NULL;
}

static int	ft_parsing_param(t_maps *maps)
{
	int		i;
	int		j;

	i = -1;
	maps->tab = ft_split(maps->file_in_a_line, '\n');
	if (!maps->tab)
		return (1);
	debug_put_tab("tab :", maps->tab, 32, 320);
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

static int	ft_core_parsing(t_data *data)
{
	if (ft_parsing_param(&data->maps) != 0)
		return (-1);
	if (ft_check_param(&data->maps) != 0)
		return (-1);
	if (ft_extract_map(&data->maps) != 0)
		return (-1);
	debug_put_tab("maps extracted :", data->maps.tab, 35, 350);
	if (ft_check_maps(&data->maps) != 0)
		return (-1);
	ft_keep_and_trash_params(&data->maps);
	return (0);
}


int	ft_parsing_cub(t_data *data, char *scene_cub)
{
	int		fd;

	if (!ft_is_good_extension(scene_cub, ".cub", 5))
		return (ft_error_parsing(scene_cub, " has a bad extension.\n"));
	fd = open(scene_cub, O_RDONLY);
	if (fd == -1)
		return (ft_error_parsing("can't open", scene_cub));
	if (ft_get_all_file(data, fd, 0) != 0)
	{
		close(fd);
		if (data->maps.file_in_a_line)
			free(data->maps.file_in_a_line);
		return (-1);
	}
	close(fd);
	debug_put_str("ft_parsing_cub", data->maps.file_in_a_line, 31, 310);
	if (ft_core_parsing(data) != 0)
		return (-1);
	return (0);
}
