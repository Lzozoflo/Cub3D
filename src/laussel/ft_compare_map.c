/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:06:37 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/14 15:57:53 by mlaussel         ###   ########.fr       */
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

	list = gnl;
	i = ft_size_map(map);
	while (list->next)
		list = list->next;
	while (ft_strcmp(map[i], list->str) != 0)
		list = list->prev;
	while (i > 6)
	{
		len = ft_strlen(map[i]);
		if (ft_strncmp(map[i], list->str, len) != 0)
		{
			debug_str("map wrong", 34, 340);
			return (0);
		}
		i--;
		list = list->prev;
	}
	debug_str("map ok", 34, 340);
	return (1);
}

int	ft_split_and_replace(t_maps *maps)
{
	char	**map;

	map = ft_split(maps->file_in_a_line, '\n');
	if (map == NULL)
		return (-1);
	debug_put_tab("\nsplit \\n :", map, 31, 310);
	ft_compare_map(maps->gnl, map);
	return (1);
}


