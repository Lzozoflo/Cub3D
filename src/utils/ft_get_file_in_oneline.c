/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_in_oneline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:29:31 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 09:31:15 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

int	ft_get_all_file(t_data *data, int fd, int error)
{
	char	*tmp;
	char	*line;

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
