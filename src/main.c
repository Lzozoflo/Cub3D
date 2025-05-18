/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:58:30 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 14:03:38 by fcretin          ###   ########.fr       */
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

	ft_draw_map_2d(&data);
	// ft_draw_square_px(data, '1');
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	// ft_clean_close(&data, 0);
	mlx_loop(data.mlx);
}
