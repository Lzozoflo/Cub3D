/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:59:59 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 15:29:29 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

static int	ft_create_bordered_tab(t_maps *maps)
{
	const int	new_y = maps->max_height + 2;
	const int	new_x = maps->max_width + 2;
	int			i;

	maps->dup_check = ft_calloc(new_y + 1, sizeof(char *));
	if (!maps->dup_check)
		return (1);
	i = 0;
	while (i < new_y)
	{
		maps->dup_check[i] = malloc(sizeof(char) * (new_x + 1));
		if (!maps->dup_check[i] && i == 0)
		{
			free(maps->dup_check);
			maps->dup_check = NULL;
			return (1);
		}
		else if (!maps->dup_check[i])
			return (1);
		ft_memset(maps->dup_check[i], ' ', new_x);
		maps->dup_check[i++][new_x] = '\0';
	}
	return (0);
}

static int	ft_dup_format_and_check_maps(t_maps *maps, char **tab)
{
	int		i;
	int		new_y;

	new_y = maps->max_height;
	if (ft_create_bordered_tab(maps))
		return (1);
	i = -1;
	while (++i < new_y)
		ft_memcpy(&maps->dup_check[i + 1][1], tab[i], ft_strlen(tab[i]));
	debug_put_tab("maps with borde :", maps->dup_check, 37, 370);
	return (0);
}


static int	ft_check_all_char_in_maps(t_maps *maps, char *str)
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
	if (maps->max_width < i)
		maps->max_width = i;
	return (0);
}

static int	ft_check_all_string_in_maps(t_maps *maps, char **tab)
{
	int	v_return;
	int	j;

	j = -1;
	while (tab[++j])
	{
		v_return = ft_check_all_char_in_maps(maps, tab[j]);
		if (v_return)
			return (v_return);
	}
	maps->max_height = j;
	debug_put_int("max_height:", maps->max_height, 36, 360);
	debug_put_int("max_width:", maps->max_width, 36, 360);
	return (0);
}

int	ft_check_maps(t_maps *maps)
{
	const int	v_return = ft_check_all_string_in_maps(maps, maps->tab);

	if (v_return == 1)
		return (ft_error_parsing("unvalid char in the maps\n", NULL));
	else if (v_return == 2)
		return (ft_error_parsing("2 char to define a character\n", NULL));
	// if (ft_no_nl_in_maps())					//ici pour le test de la maps
	// 	return (1);
	if (ft_dup_format_and_check_maps(maps, maps->tab))
		return (1);
	if (ft_check_maps_closed(maps, maps->dup_check))
	{
		debug_put_maps(maps->dup_check, 38, 380);
		return (1);
	}












	return (0);
}
