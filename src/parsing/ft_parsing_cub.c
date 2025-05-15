/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 10:43:06 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>


static int	ft_core_parsing(t_maps *maps)
{
	if (ft_parsing_param(maps) != 0)
		return (-1);
	if (ft_check_param(maps) != 0)
		return (-1);
	// if (ft_check_maps(maps) != 0)
	// 	return (-1);					//ici pour le test de la maps
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
	if (ft_get_all_file(data, fd, 0) != 0)
	{
		close(fd);
		if (data->maps.file_in_a_line)
			free(data->maps.file_in_a_line);
		return (-1);
	}
	close(fd);
	debug_put_str("ft_parsing_cub", data->maps.file_in_a_line, 31, 310);
	if (ft_core_parsing(&data->maps) != 0)
		return (-1);
	return (0);
}
