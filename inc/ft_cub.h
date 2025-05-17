/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 16:04:24 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include "X.h"
# include "mlx.h"

// Window params
# define WIN_SIZE 1000
# define WIN_NAME "Cub3D"

// Key_press
# define ESC 65307

// Key Code moving player
# define A 97
# define W 119
# define D 100
# define S 115

// Key Code moving camera
# define LEFT 65361
# define RIGHT 65363


//typedef of all structure
typedef struct s_data	t_data;
typedef struct s_image	t_image;
typedef struct s_maps	t_maps;
typedef struct s_gnl	t_gnl;

struct s_gnl
{
	char	*str;
	t_gnl	*prev;
	t_gnl	*next;
};

struct		s_maps
{
	t_gnl			*gnl;
	char			**tab;
	char			**dup_check;
	char			*file_in_a_line;
	char			*texture_ea;
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*str_floor;
	char			*str_sky;
	unsigned int	floor;
	unsigned int	sky;
	int				max_width;
	int				max_height;
};

struct		s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct		s_data
{
	void	*mlx;
	void	*win;
	int		name;
	t_image	img;
	t_maps	maps;
};


int	ft_split_and_replace(t_maps *maps);
/*	src/init	*/

//		ft_init_struct.c

void	ft_init_data(t_data *data);

//		ft_init_mlx.c
int		ft_init_mlx(t_data *data);

/*	src/parsing	*/
//		ft_check_format_save_color.c

int		ft_check_format_save_color(t_maps *maps);

//		ft_check_maps_closed.c

int		ft_check_maps_closed(t_maps *maps, char **tab);

//		ft_check_maps.c

int		ft_check_maps(t_maps *maps);

//		ft_check_param.c

int		ft_check_param(t_maps *maps);

//		ft_clear_str_of_texture.c

int		ft_clear_parameters(t_maps *maps);

//		ft_find_param.c

int		ft_find_line_texture(t_maps *maps, int i, int j);

//		ft_extract_map.c

int		ft_extract_map(t_maps *maps);

//		ft_parsing_cub.c

int		ft_parsing_cub(t_data *data, char *scene_cub);

/*	src/utils	*/

//		event/ft_key_event.c

int		ft_key_press(int keycode, void *param);

//		ft_close.c

void	ft_clear_maps(t_maps *maps);
int		ft_clean_close(t_data *data, int error);
int		ft_cross(t_data *data);

//		ft_error.c

int		ft_error_parsing(char *str, char *type);

//ft_get_file_in_oneline.c

int		ft_get_all_file(t_data *data, int fd, int error);

//		ft_is.c

int		ft_is_invalid_neighbor(char c);
int		ft_is_player_char(int c);
int		ft_is_valid_char(int c);
int		ft_is_player_move(int keycode);
int		ft_is_camera_move(int keycode);

/*	src/utils_struct	*/

//		t_gnl.c

void	t_gnl_clear(t_maps *maps);
int		t_gnl_add_end(t_maps *maps, char *str);

#endif
