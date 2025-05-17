/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:23:50 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:55:08 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
// #include "ft_debug.h"
#include "ft_parsing_error.h"
#include "libft.h"

int	ft_extract_map(t_parsing *parsing)
{
	char	**new_tab;

	if (!parsing->tab[6])
		return (ft_error_parsing(ERROR_MAPS_NULL, NULL));
	new_tab = ft_tabdup(&parsing->tab[6]);
	ft_freetab(parsing->tab, 0);
	parsing->tab = new_tab;
	return (!new_tab);
}
