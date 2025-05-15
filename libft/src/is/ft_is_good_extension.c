/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_good_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:48:25 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 09:57:44 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_good_extension(char *scene_cub, char *search, int len_search)
{
	size_t	len;

	len = ft_strlen(scene_cub) - len_search;
	if (ft_strncmp(search, &scene_cub[len + 1], len_search) == 0)
		return (1);
	return (0);
}
