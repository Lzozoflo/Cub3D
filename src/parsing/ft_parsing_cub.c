/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:39:16 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/25 15:22:53 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "ft_define.h"
#include "libft.h"
#include <fcntl.h>

static void	ft_init_player_angle(t_player *player)
{
	if (player->pos == 'n')
		player->angle = 0;
	else if (player->pos == 's')
		player->angle = PI;
	else if (player->pos == 'e')
		player->angle = PI / 2;
	else if (player->pos == 'w')
		player->angle = -PI / 2;
}

static int	ft_keep_and_trash_parsing(t_parsing *parsing, t_exec *exec)
{
	exec->max_height = parsing->max_height;
	exec->max_width = parsing->max_width;
	exec->floor = parsing->floor;
	exec->sky = parsing->sky;
	exec->tab = ft_tabdup(parsing->tab);
	if (!exec->tab)
		return (1);
	exec->texture.texture_ea = ft_strdup(parsing->texture_ea);
	if (!exec->texture.texture_ea)
		return (1);
	exec->texture.texture_no = ft_strdup(parsing->texture_no);
	if (!exec->texture.texture_no)
		return (1);
	exec->texture.texture_so = ft_strdup(parsing->texture_so);
	if (!exec->texture.texture_so)
		return (1);
	exec->texture.texture_we = ft_strdup(parsing->texture_we);
	if (!exec->texture.texture_we)
		return (1);
	ft_find_player_pos(exec->tab, &exec->player);
	ft_init_player_angle(&exec->player);
	ft_clear_parsing(parsing);
	return (0);
}

static int	ft_parsing_param(t_parsing *parsing)
{
	int		i;
	int		j;

	i = -1;
	parsing->tab = ft_split(parsing->file_in_a_line, '\n');
	if (!parsing->tab)
		return (1);
	debug_put_tab("tab :", parsing->tab, 32, 320);
	while (i++ != 5)
	{
		j = 0;
		while (parsing->tab[i][j] && ft_is_white_space(parsing->tab[i][j]))
			j++;
		if (ft_find_line_texture(parsing, i, j) != 0)
			return (1);
	}
	debug_put_gnl_list("list", parsing->gnl, 33, 330);
	return (0);
}

static int	ft_core_parsing(t_data *data)
{
	if (ft_parsing_param(&data->parsing) != 0)
		return (-1);
	if (ft_check_param(&data->parsing) != 0)
		return (-1);
	if (ft_extract_map(&data->parsing) != 0)
		return (-1);
	debug_put_tab("extracted :", data->parsing.tab, 35, 350);
	if (ft_check_maps(&data->parsing) != 0)
		return (-1);
	if (ft_keep_and_trash_parsing(&data->parsing, &data->exec))
		return (1);
	return (0);
}

int	ft_parsing_cub(t_data *data, char *scene_cub)
{
	int		fd;

	if (!ft_is_good_extension(scene_cub, ".cub", 5))
		return (ft_error_parsing(scene_cub, ERROR_EXTENSION));
	fd = open(scene_cub, O_RDONLY);
	if (fd == -1)
		return (ft_error_parsing(scene_cub, ERROR_OPEN));
	if (ft_get_all_file(data, fd, 0) != 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	debug_put_str("ft_parsing_cub", data->parsing.file_in_a_line, 31, 310);
	if (ft_core_parsing(data) != 0)
		return (-1);
	return (0);
}
