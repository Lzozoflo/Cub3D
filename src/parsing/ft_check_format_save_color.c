/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_save_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 09:34:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 13:58:35 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_define.h"
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
	if (str[i] < '0' || str[i] > '9')
		*error = 1;
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

static int	ft_save_rgb(char **tab, unsigned int *color, char *str)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				error;

	if (!ft_is_str_digit(tab[0]) || !ft_is_str_digit(tab[1])
		|| !ft_is_str_digit(tab[2]))
		return (ft_error_parsing(ERROR_RGB_FORMAT, str));
	r = (unsigned char)ft_atoi_color(tab[0], &error);
	if (error)
		return (ft_error_parsing(ERROR_RGB_VALUE, str));
	g = (unsigned char)ft_atoi_color(tab[1], &error);
	if (error)
		return (ft_error_parsing(ERROR_RGB_VALUE, str));
	b = (unsigned char)ft_atoi_color(tab[2], &error);
	if (error)
		return (ft_error_parsing(ERROR_RGB_VALUE, str));
	*color = ft_rgb(r, g, b);
	return (0);
}

static int	ft_is_format_color(char *str, unsigned int *color)
{
	char	**tab;
	int		i;

	i = 0;
	if (ft_count_char(str, ',') != 2)
		return (ft_error_parsing(ERROR_RGB_FORMAT, str));
	tab = ft_split(str, ',');
	if (!tab)
		return (1);
	while (tab[i])
		i++;
	if (i != 3)
	{
		ft_freetab(tab, 0);
		return (ft_error_parsing(ERROR_RGB_FORMAT, str));
	}
	if (ft_save_rgb(tab, color, str))
	{
		ft_freetab(tab, 0);
		return (1);
	}
	ft_freetab(tab, 0);
	return (0);
}

int	ft_check_format_save_color(t_parsing *parsing)
{
	if (ft_is_format_color(parsing->str_floor, &parsing->floor))
		return (1);
	if (ft_is_format_color(parsing->str_sky, &parsing->sky))
		return (1);
	return (0);
}
