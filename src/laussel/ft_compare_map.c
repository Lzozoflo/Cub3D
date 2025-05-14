/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:06:37 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/14 15:37:46 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

static int	ft_size_map(char **map)
{
	int	i;
	int	len;

	i = 6;
	len = 0;
	while (map[i])
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_compare_map(t_gnl *gnl, char **map)
{
	int	i;
	t_gnl	*list;
	int	len;

	i = ft_size_map(map);
	while (list->next)
		list = list->next;
	while (list->str == NULL)
		list = list->prev;
	while (i > 6)
	{
		len = ft_strlen(map[i]);
		if (ft_strncmp(map[i], list, len) != 0)
		{
			debug_put_int_d1("DEBUG--> map ok : ", 0, 31, 310);
			return (0);
		}
		i--;
		list = list->prev;
	}
	debug_put_int_d1("DEBUG--> map ok : ", 1, 31, 310);
	return (1);
}

int	ft_split_and_replace(t_data *data)
{
	char	**map_1;
	char	**map_2;

	map_1 = ft_split(data->maps.file_in_a_line, '\n');
	if (map_1 == NULL)
		return (-1);
	debug_put_tab("split \\n :", map_1, 31, 310);
	ft_compare_map(data->maps.gnl, map_1);
	return (1);
}


