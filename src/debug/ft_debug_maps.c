/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:19:37 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:00:46 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "ft_cub.h"

static	void	ft_put_in_color(char c)
{
	if (c == '1')
		printf("%s%c%s", BLUE, c, RESET);
	else if (c == '0')
		printf("%s%c%s", GREEN, c, RESET);
	else if (c == 'X')
		printf("%s%c%s", RED, c, RESET);
	else
		printf("%s%c%s", YELLOW, c, RESET);
}

void	debug_put_parsing(char **tab, int f, int s)
{
	int	i;
	int	j;

	j = -1;
	if (DEBUG == f || DEBUG == s)
	{
		while (tab[++j])
		{
			i = -1;
			while (tab[j][++i])
				ft_put_in_color(tab[j][i]);
			printf("\n");
		}
	}
}
