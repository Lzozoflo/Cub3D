/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:00:39 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:21:43 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_is_white_space(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_is_str_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_white_space(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
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
