/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/13 10:34:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

int	ft_parsing_scene(t_data *data, char *scene_cub)
{
	char	*line;
	int		fd;

	(void)data;
	if (!ft_is_a_good_extension(scene_cub))
		return (1);
	fd = open(scene_cub, O_RDONLY);
	line = get_next_line(fd);
	while (1)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			ft_putstr_fd("NULL", 2);
			break;
		}
	}
	close(fd);
	return (0);
}
