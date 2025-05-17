/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:09:25 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

static void	ft_keep_and_trash_params(t_parsing *parsing)
{
	if (parsing->file_in_a_line)
		free(parsing->file_in_a_line);
	if (parsing->str_floor)
		free(parsing->str_floor);
	if (parsing->str_sky)
		free(parsing->str_sky);
	if (parsing->gnl)
		t_gnl_clear(parsing);
	parsing->file_in_a_line = NULL;
	parsing->str_floor = NULL;
	parsing->str_sky = NULL;
	parsing->gnl = NULL;
}

static int	ft_parsing_param(t_parsing *parsing)
{
	int		i;
	int		j;

	i = -1;
	parsing->tab = ft_split(parsing->file_in_a_line, '\n');
	if (!parsing->tab)
		return (1);
	debug_put_tab("tab :", parsing->tab, 32, 320);
	while (i++ != 5)
	{
		j = 0;
		while (parsing->tab[i][j] && ft_is_white_space(parsing->tab[i][j]))
			j++;
		if (ft_find_line_texture(parsing, i, j) != 0)
			return (1);
	}
	debug_put_gnl_list("list", parsing->gnl, 33, 330);
	return (0);
}

static int	ft_core_parsing(t_data *data)
{
	if (ft_parsing_param(&data->parsing) != 0)
		return (-1);
	if (ft_check_param(&data->parsing) != 0)
		return (-1);
	if (ft_extract_map(&data->parsing) != 0)// miro rajoute
		return (-1);
	debug_put_tab(" extracted :", data->parsing.tab, 35, 350);
	if (ft_check_(&data->parsing) != 0)
		return (-1);
	ft_keep_and_trash_params(&data->parsing);
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
		if (data->parsing.file_in_a_line)
			free(data->parsing.file_in_a_line);
		return (-1);
	}
	close(fd);
	debug_put_str("ft_parsing_cub", data->parsing.file_in_a_line, 31, 310);
	if (ft_core_parsing(data) != 0)
		return (-1);
	return (0);
}
