/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/23 12:43:06 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include <stdlib.h>

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 2 || !env[0])
		return (1);
	ft_init_data(&data);
	if (ft_parsing_cub(&data, av[1]))
	{
		ft_clear_parsing(&data.parsing);
		return (1);
	}
	if (!ft_init_mlx(&data))
		return (1);
	ft_print_settings();
	if (ft_init_start(&data.exec, &data) == -1)
	{
		return (-1);
	}
	t_minimap_set_color(&data.exec, &data.exec.mini);
	if (ft_refresh_view(&data) == -1)
	{
		ft_free_cardi(&data.exec);
		ft_free_radius(&data.exec.radius, data.win_scale);
		return (1);
	}
	mlx_loop_hook(data.mlx, ft_handle_keys, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, ft_key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, ft_key_release, &data);
	mlx_loop(data.mlx);
}
