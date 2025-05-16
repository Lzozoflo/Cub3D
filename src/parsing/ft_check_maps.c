/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:59:59 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 15:22:06 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
// #include "ft_debug.h"
#include "libft.h"

static int	ft_check_all_char_in_maps(char **tab)
{
	int	player;
	int	i;
	int	j;

	j = -1;
	player = 0;
	while (tab[++j])
	{
		i = 0;
		while (ft_is_valid_char(tab[j][i]))
		{
			if (ft_is_player_char(tab[j][i++]))
			{
				if (player)
					return (2);
				else
					player = 1;
			}
		}
		if (tab[j][i])
			return (1);
	}
	return (0);
}

int	ft_check_maps(t_maps *maps)
{
	const int	v_return = ft_check_all_char_in_maps(maps->tab);

	if (v_return == 1)
		return (ft_error_parsing("unvalid char in the maps", NULL));
	else if (v_return == 2)
		return (ft_error_parsing("2 char to define a character", NULL));
	// if (ft_no_nl_in_maps())					//ici pour le test de la maps
	// 	return (1);
	// if (ft_creat_good_tab_for_flood_fill())
	// 	return (1);
	// if (ft_flood_fill())
	// 	return (1);
	return (0);
}
