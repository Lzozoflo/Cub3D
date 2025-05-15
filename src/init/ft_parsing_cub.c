/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 09:17:29 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

static int	ft_check_double(char **str, char *str_int_tab, char *find)
{
	if (*str)
		return (ft_error_parsing(find, " was found 2 time"));
	*str = ft_strdup(maps->tab[i]);
	if (!*str)
		return (1);
	return (0);
}

static int	ft_find_line_floor_sky_or_error(t_maps *maps, int i, int j)
{

	if (ft_strncmp(&maps->tab[i][j], "F ", 2) == 0)
	{
		if (ft_check_double(&maps->floor, maps->tab[i]), "F ")
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "C ", 2))
	{
		if (ft_check_double(&maps->sky, maps->tab[i]), "C ")
			return (1);
	}
	else
		return (ft_error_parsing("Bad paramaters\n", NULL));
	return (0);
}

static int	ft_find_line_texture(t_maps *maps, int i, int j)
{
	if (ft_strncmp(&maps->tab[i][j], "EA ", 3))
	{
		if (ft_check_double(&maps->texture_ea, maps->tab[i], "EA "))
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "NO ", 3))
	{
		if (ft_check_double(&maps->texture_no, maps->tab[i], "NO "))
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "SO ", 3))
	{
		if (ft_check_double(&maps->texture_so, maps->tab[i], "SO "))
			return (1);
	}
	else if (ft_strncmp(&maps->tab[i][j], "WE ", 3))
	{
		if (ft_check_double(&maps->texture_we, maps->tab[i], "WE "))
			return (1);
	}
	else if (ft_find_line_floor_sky_or_error(maps, i, j))
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
		if (ft_type_param(maps, i, j))
			return (-1);
	}
	debug_put_gnl_list("list", maps->gnl, 33, 330);
	//ici pour le test de la maps
	return (0);
}


static int	ft_get_all_file(t_data *data, int fd)
{
	char	*tmp;
	char	*line;
	int		error;

	line = get_next_line(fd, &error);
	if (!line && error != 1)
		return (-1);
	if (t_gnl_add_end(&data->maps, ft_strdup(line)) == -1)
		return (-1);
	data->maps.file_in_a_line = line;
	while (1)
	{
		line = get_next_line(fd, &error);
		if (!line && error == 0)
			break ;
		if (!line && error != 0)
			return (-1);
		if (t_gnl_add_end(&data->maps, line) == -1)
			return (-1);
		tmp = ft_strjoin(data->maps.file_in_a_line, line);
		if (!tmp)
			return (-1);
		free(data->maps.file_in_a_line);
		data->maps.file_in_a_line = tmp;
	}
	return (0);
}

int	ft_parsing_cub(t_data *data, char *scene_cub)
{
	int		fd;

	if (!ft_is_a_good_extension(scene_cub))
		return (-1);
	fd = open(scene_cub, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (ft_get_all_file(data, fd) == -1)
	{
		close(fd);
		if (data->maps.file_in_a_line)
			free(data->maps.file_in_a_line);
		return (-1);
	}
	debug_put_str("ft_parsing_cub", data->maps.file_in_a_line, 31, 310);
	close(fd);
	if (ft_parsing_param(&data->maps) == -1)
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
