/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps_closed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:20:43 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:23:40 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
// #include "ft_debug.h"
#include "libft.h"

static int	check_surroundings(t_parsing *parsing, char **tab, int y, int x)
{
	const int	height = parsing->max_height + 2;
	const int	width = parsing->max_width + 2;

	if (y > 0 && ft_is_invalid_neighbor(tab[y - 1][x]))
	{
		tab[y - 1][x] = 'X';
		return (0);
	}
	if (y < height -1 && ft_is_invalid_neighbor(tab[y + 1][x]))
	{
		tab[y + 1][x] = 'X';
		return (0);
	}
	if (x > 0 && ft_is_invalid_neighbor(tab[y][x - 1]))
	{
		tab[y][x - 1] = 'X';
		return (0);
	}
	if (x < width -1 && ft_is_invalid_neighbor(tab[y][x + 1]))
	{
		tab[y][x + 1] = 'X';
		return (0);
	}
	return (1);
}

static int	ft_check_closed(t_parsing *parsing, char **tab, int x, int y)
{
	const int	height = parsing->max_height + 2;
	const int	width = parsing->max_width + 2;

	if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
		;
	else if (tab[y][x] == ' ')
	{
		if (!check_surroundings(parsing, tab, y, x))
			return (1);
	}
	else if (ft_is_player_char(tab[y][x]))
	{
		if (tab[y - 1][x] == ' ' || tab[y + 1][x] == ' ' ||
			tab[y][x - 1] == ' ' || tab[y][x + 1] == ' ')
			return (1);
	}
	return (0);
}

int	ft_check_maps_closed(t_parsing *parsing, char **tab)
{
	const int	height = parsing->max_height + 2;
	const int	width = parsing->max_width + 2;
	int			y;
	int			x;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if (ft_check_closed(parsing, tab, x, y))
				return (1);
		}
	}
	return (0);
}
