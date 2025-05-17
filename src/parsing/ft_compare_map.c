/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:06:37 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/17 16:37:20 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"
#include <fcntl.h>


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

static int    ft_size_map(char **map)
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
			debug_put_str(NULL, "map wrong", 34, 340);
			return (0);
		}
		i--;
		gnl = gnl->prev;
	}
	debug_put_str(NULL, "map ok", 34, 340);
	return (1);
}

int	ft_split_and_replace(t_maps *maps)
{
	debug_put_tab("split \\n :", maps->tab, 31, 310);
	if (ft_compare_map(maps->gnl, maps->tab) == 0)
		return (1);
	return (0);
}
