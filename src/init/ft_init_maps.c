/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:26:06 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/14 13:29:36 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

void	ft_init_maps(t_maps *maps)
{
	maps->file_in_a_line = NULL;
	maps->tab = NULL;
	maps->texture_ea = NULL;
	maps->texture_no = NULL;
	maps->texture_so = NULL;
	maps->texture_we = NULL;
}
