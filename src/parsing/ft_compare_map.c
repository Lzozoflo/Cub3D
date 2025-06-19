/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:05:40 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/19 10:28:37 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>

static int	ft_size_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i -1);
}

static int	ft_compare_map(t_gnl *gnl, char **map)
{
	int	i;
	int	len;

	i = ft_size_map(map);
	while (gnl->next)
		gnl = gnl->next;
	while (ft_strcmp(map[i], gnl->str) != 0)
		gnl = gnl->prev;
	while (i > -1)
	{
		len = ft_strlen(map[i]);
		if (ft_strncmp(map[i], gnl->str, len) != 0)
		{
			debug_put_str(NULL, "map wrong", 38, 380);
			return (0);
		}
		i--;
		gnl = gnl->prev;
	}
	debug_put_str(NULL, "map ok", 38, 380);
	return (1);
}

int	ft_check_no_nl_in_maps(t_parsing *parsing)
{
	debug_put_tab("split \\n :", parsing->tab, 31, 310);
	if (ft_compare_map(parsing->gnl, parsing->tab) == 0)
		return (1);
	return (0);
}
