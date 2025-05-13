/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/13 09:53:11 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)av;
	if (ac != 2 || !env[0])
		return (1);
	if (ft_parsing_scene(&data, av[1]))
		return (1);
	if (!ft_init_mlx(&data))
		return (1);
	mlx_loop(data.mlx);
}
