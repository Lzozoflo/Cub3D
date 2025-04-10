/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:00:39 by fcretin           #+#    #+#             */
/*   Updated: 2025/02/05 16:56:47 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_is_white_space(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_no_input(char **av)
{
	int	i;
	int	j;
	int	nothing_or_space;

	i = 1;
	while (av[i])
	{
		j = 0;
		nothing_or_space = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_is_white_space(av[i][j]))
			{
				nothing_or_space = 1;
				break ;
			}
			j++;
		}
		if (nothing_or_space == 0)
			return (1);
		i++;
	}
	return (0);
}
