/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 12:02:33 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 2 || !env[0])
		return (1);
	ft_init_data(&data);
	if (ft_parsing_cub(&data, av[1]))
	{
		ft_clear_maps(&data.maps);
		return (1);
	}
	if (!ft_init_mlx(&data))
		return (1);
	mlx_loop(data.mlx);
}
