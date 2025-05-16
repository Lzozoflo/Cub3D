/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:48:28 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/16 11:56:19 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**dup_tab;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_len_tab(tab);
	dup_tab = malloc(sizeof(char *) * (len + 1));
	if (!dup_tab)
		return (NULL);
	while (i != len)
	{
		dup_tab[i] = ft_strdup(tab[i]);
		if (!dup_tab[i] && i != 0)
			return (ft_freetab(dup_tab, i));
		else if (!dup_tab[i] && i == 0)
			return (ft_free_null(dup_tab));
		i++;
	}
	return (dup_tab);
}
