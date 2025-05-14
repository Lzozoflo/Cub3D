/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/14 12:52:21 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

static int	ft_get_all_file(t_data *data, int fd)
{
	char	*tmp;
	char	*line;
	int		error;

	line = get_next_line(fd, &error);
	if (!line && error != 1)
		return (-1);
	data->maps.file_in_a_line = line;
	while (1)
	{
		line = get_next_line(fd, &error);
		if (!line && error == 0)
			break ;
		if (!line && error != 0)
			return (-1);
		tmp = ft_strjoin(data->maps.file_in_a_line, line);
		free(data->maps.file_in_a_line);
		free(line);
		if (!tmp)
			return (-1);
		data->maps.file_in_a_line = tmp;
	}
	debug_put_str("ft_parsing_scene", data->maps.file_in_a_line, 31, 310);
	close(fd);
	return (0);
}

int	ft_parsing_scene(t_data *data, char *scene_cub)
{
	int		fd;
	char	**tab;

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
	tab = ft_split(data->maps.file_in_a_line, '\n');
	debug_put_tab("test :", tab, 31, 310);
	return (0);
}
