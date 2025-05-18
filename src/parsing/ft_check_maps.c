/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:59:59 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 14:46:35 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_parsing_error.h"
#include "libft.h"

static int	ft_create_bordered_tab(t_parsing *parsing)
{
	const int	new_y = parsing->max_height + 2;
	const int	new_x = parsing->max_width + 2;
	int			i;

	parsing->dup_check = ft_calloc(new_y + 1, sizeof(char *));
	if (!parsing->dup_check)
		return (1);
	i = 0;
	while (i < new_y)
	{
		parsing->dup_check[i] = malloc(sizeof(char) * (new_x + 1));
		if (!parsing->dup_check[i] && i == 0)
		{
			free(parsing->dup_check);
			parsing->dup_check = NULL;
			return (1);
		}
		else if (!parsing->dup_check[i])
			return (1);
		ft_memset(parsing->dup_check[i], ' ', new_x);
		parsing->dup_check[i++][new_x] = '\0';
	}
	return (0);
}

static int	ft_dup_and_format(t_parsing *parsing, char **tab)
{
	int		i;
	int		new_y;

	new_y = parsing->max_height;
	if (ft_create_bordered_tab(parsing))
		return (1);
	i = -1;
	while (++i < new_y)
		ft_memcpy(&parsing->dup_check[i + 1][1], tab[i], ft_strlen(tab[i]));
	debug_put_tab("parsing with borde :", parsing->dup_check, 37, 370);
	return (0);
}

static int	ft_check_all_char_in_maps(t_parsing *parsing, char *str)
{
	static int	player = 0;
	int			i;

	i = 0;
	while (ft_is_valid_char(str[i]))
	{
		if (ft_is_player_char(str[i++]))
		{
			if (player)
				return (2);
			else
				player = 1;
		}
	}
	if (str[i])
		return (1);
	if (parsing->max_width < i)
		parsing->max_width = i;
	if (!player)
		return (3);
	return (0);
}

static int	ft_check_all_string_in_maps(t_parsing *parsing, char **tab)
{
	int	v_return;
	int	j;

	j = -1;
	while (tab[++j])
	{
		v_return = ft_check_all_char_in_maps(parsing, tab[j]);
		if (v_return == 1 || v_return == 2)
			return (v_return);
	}
	parsing->max_height = j;
	debug_put_int("max_height:", parsing->max_height, 36, 360);
	debug_put_int("max_width:", parsing->max_width, 36, 360);
	if (v_return == 3)
		return (3);
	return (0);
}

int	ft_check_maps(t_parsing *parsing)
{
	const int	v_return = ft_check_all_string_in_maps(parsing, parsing->tab);

	if (v_return == 1)
		return (ft_error_parsing(ERROR_INVALID_CHAR, NULL));
	else if (v_return == 2)
		return (ft_error_parsing(ERROR_TWO_PLAYER, NULL));
	else if (v_return == 3)
		return (ft_error_parsing(ERROR_ZERO_PLAYER, NULL));
	if (ft_check_no_nl_in_maps(parsing))
		return (ft_error_parsing(ERROR_MAP_SEPARATE, NULL));
	if (ft_dup_and_format(parsing, parsing->tab))
		return (1);
	if (ft_check_maps_closed(parsing, parsing->dup_check))
	{
		debug_put_parsing(parsing->dup_check, 39, 390);
		return (ft_error_parsing(ERROR_MAP_CLOSE, NULL));
	}
	return (0);
}
