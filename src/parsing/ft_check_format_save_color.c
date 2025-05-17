/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_save_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:34:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 13:13:49 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
// #include "ft_debug.h"
#include "libft.h"
#include <stdint.h>

int	ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

static int	ft_atoi_color(const char *str, int *error)
{
	long	res;
	int		i;

	i = 0;
	res = 0;
	*error = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' && (str[i] < '0' || str[i] > '9'))
		*error = 1;
	if (str[i] == '+' && !str[i + 1])
		*error = 1;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res > 255)
			*error = 1;
	}
	if (str[i])
		*error = 1;
	return ((int)res);
}

static int	ft_save_rgb(char **tab, unsigned int *color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				error;

	r = (unsigned char)ft_atoi_color(tab[0], &error);
	if (error)
		return (1);
	g = (unsigned char)ft_atoi_color(tab[1], &error);
	if (error)
		return (1);
	b = (unsigned char)ft_atoi_color(tab[2], &error);
	if (error)
		return (1);
	*color = ft_rgb(r, g, b);
	return (0);//!ft_error_parsing("Wrong value R,G,B: ", str)
}

static int	ft_is_format_color(char *str, unsigned int *color)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str, ',');
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	if (i != 3)
		return (0);
	if (ft_save_rgb(tab, color))
	{
		ft_freetab(tab, 0);
		return (0);//
	}
	ft_freetab(tab, 0);
	return (1);
}

int	ft_check_format_save_color(t_maps *maps)
{
	if (!ft_is_format_color(maps->str_floor, &maps->floor))
		return (ft_error_parsing("format rgb is not correct: ", maps->str_floor));
	if (!ft_is_format_color(maps->str_sky, &maps->sky))
		return (ft_error_parsing("format rgb is not correct: ", maps->str_sky));
	return (0);
}
