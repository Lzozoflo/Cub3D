/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_str_of_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:09:23 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:08:27 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

static void	ft_swap_ptr(char **str, char **tab)
{
	void	*ptr_tmp;

	debug_put_str("swap this str", *str, 34, 340);
	ptr_tmp = tab[1];
	tab[1] = *str;
	*str = ptr_tmp;
	if (DEBUG == 34)
		printf("by this one: [%s]\n", *str);
	ft_freetab(tab, 0);
}

static int	ft_check_one_parameters(char **str)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split_white_space(*str);
	if (!tab)
		return (-1);
	while (tab[i])
		i++;
	if (i != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(tab[0], 2);
		ft_putstr_fd(" has multiply parametes:\n", 2);
		i = 0;
		while (tab[++i])
		{
			ft_putstr_fd(tab[i], 2);
			ft_putstr_fd("\n", 2);
		}
		ft_freetab(tab, 0);
		return (-1);
	}
	ft_swap_ptr(str, tab);
	return (0);
}

int	ft_clear_parameters(t_parsing *parsing)
{
	if (ft_check_one_parameters(&parsing->texture_ea))
		return (1);
	if (ft_check_one_parameters(&parsing->texture_no))
		return (1);
	if (ft_check_one_parameters(&parsing->texture_so))
		return (1);
	if (ft_check_one_parameters(&parsing->texture_we))
		return (1);
	if (ft_check_one_parameters(&parsing->str_sky))
		return (1);
	if (ft_check_one_parameters(&parsing->str_floor))
		return (1);
	return (0);
}
