/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/14 13:26:49 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>



int	ft_parsing_param(t_maps *maps)
{
	int		i;

	i = 0;
	maps->tab = ft_split(maps->file_in_a_line, '\n');
	if (!maps->tab)
		return (-1);
	debug_put_tab("test :", maps->tab, 32, 320);
	while (i++ != 6)
	{

	}
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
	debug_put_str("ft_parsing_cub", data->maps.file_in_a_line, 31, 310);
	close(fd);
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
	if (ft_parsing_param(&data->maps) == -1)
		return (-1);
	return (0);
}
