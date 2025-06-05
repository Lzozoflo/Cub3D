/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/05 13:02:32 by fcretin          ###   ########.fr       */
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
		ft_clear_parsing(&data.parsing);
		return (1);
	}
	if (!ft_init_mlx(&data))
		return (1);
	if (ft_init_textures(&data, &data.exec.texture) == -1)
		return (1);
	ft_print_settings();
	//mlx_hook(data.win, 2, 1L << 0, ft_left_right, &data);
	t_minimap_set_color(&data.exec, &data.exec.mini);
	ft_refresh_view(&data);
	mlx_loop(data.mlx);

}

	// ft_draw_map_2d(&data);
	// mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
