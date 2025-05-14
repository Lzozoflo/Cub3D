/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:06:37 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/14 14:14:01 by mlaussel         ###   ########.fr       */
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

static int	ft_is_backslash_n(char *str)
{
	int	i;

	i = 0;
	while (ft_is_white_space(str[i]))
		i++;
	if (str[i] == '\n')
		return (0);
	return (1);
}

static int	ft_compare_map(char	**map1, char **map2)
{
	int	i;
	int	j;
	int	len;

	i = ft_size_map(map1);
	j = ft_size_map(map2);
	while (ft_is_backslash_n(map2[j]))
		j--;
	while (i > 6)
	{
		len = ft_strlen(map1[i]);
		if (ft_strncmp(map1[i], map2[j], len) != 0)
		{
			debug_put_int_d1("DEBUG--> map ok : ", 0, 31, 310);
			return (0);
		}
		i--;
		j--;
	}
	debug_put_int_d1("DEBUG--> map ok : ", 1, 31, 310);
	return (1);
}

static void	ft_replace_n(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] && map[i + 1] == '\n')
		{
			i++;
			map[i] = -42;

			// if (map[i + 1])
			// 	i++;
		}
		i++;
	}
	debug_put_str("replace - 42 : ",map, 31, 310);
}

int	ft_split_and_replace(t_data *data)
{
	char	**map_1;
	char	**map_2;

	map_1 = ft_split(data->maps.file_in_a_line, '\n');
	if (map_1 == NULL)
		return (-1);
	debug_put_tab("split \\n :", map_1, 31, 310);
	ft_replace_n(data->maps.file_in_a_line);
	map_2 = ft_split(data->maps.file_in_a_line, '\n');
	if (map_2 == NULL)
		return (-1);
	debug_put_tab("split -42 :", map_1, 31, 310);
	ft_compare_map(map_1, map_2);
	return (1);
}


