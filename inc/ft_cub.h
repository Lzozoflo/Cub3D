/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/14 13:12:30 by fcretin          ###   ########.fr       */
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

struct		s_maps
{
	char	*file_in_a_line;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
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
	int		floor;
	int		sky;

};

///////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------|
//														|
//						src/utils						|
//														|
//------------------------------------------------------|

//
//--------------------------------------------------------------------------|
//		event/					ft_key_event.c								|
//--------------------------------------------------------------------------|

int		ft_key_press(int keycode, void *param);

//
//--------------------------------------------------------------------------|
//								ft_close.c									|
//--------------------------------------------------------------------------|

int		ft_clean_close(t_data *data, int error);
int		ft_cross(t_data *data);

//
//--------------------------------------------------------------------------|
//								ft_error.c									|
//--------------------------------------------------------------------------|

void	ft_error_parsing(char *str, char *type);

//
//--------------------------------------------------------------------------|
//								ft_is.c										|
//--------------------------------------------------------------------------|

int		ft_is_a_good_extension(char *scene_cub);
int		ft_is_player_move(int keycode);
int		ft_is_camera_move(int keycode);

//------------------------------------------------------|
//														|
//						src/init						|
//														|
//------------------------------------------------------|

//
//--------------------------------------------------------------------------|
//								ft_init_mlx.c								|
//--------------------------------------------------------------------------|

int		ft_init_mlx(t_data *data);

//
//--------------------------------------------------------------------------|
//								ft_init_mlx.c								|
//--------------------------------------------------------------------------|

int		ft_parsing_cub(t_data *data, char *scene_cub);



#endif
