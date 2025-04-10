/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:41:41 by fcretin           #+#    #+#             */
/*   Updated: 2025/03/08 11:07:36 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_tab(char **tab)
{
	char	*tmp;
	int		i;
	int		swapped;

	if (!tab || !tab[0])
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				swapped = 1;
			}
			i++;
		}
	}
}
