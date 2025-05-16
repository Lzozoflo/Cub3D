/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_maps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:00:09 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 15:16:13 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
// #include "ft_debug.h"
#include "libft.h"

int	ft_extract_map(t_maps *maps)
{
	char	**new_tab;

	if (!maps->tab[6])
		return (ft_error_parsing("no maps", NULL));
	new_tab = ft_tabdup(&maps->tab[6]);
	ft_freetab(maps->tab, 0);
	maps->tab = new_tab;
	return (!new_tab);
}
