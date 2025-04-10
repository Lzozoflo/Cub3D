/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/10 16:34:59 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include "X.h"
# include "mlx.h"

// Window params
# define WIN_SIZE 1000
# define WIN_NAME "Cub3D"

//		Key_press
# define ESC 65307

// Key Code moving
# define W 119
# define A 97
# define S 115
# define D 100

// //		Mouse_hook
// # define SCROLL_UP 5
// # define SCROLL_DOWN 4
// # define SCROLL_CLICK 2
// # define LEFT_CLICK 1
// # define RIGHT_CLICK 3

//typedef of all structure
typedef struct s_data	t_data;
typedef struct s_image	t_image;
typedef struct s_rgb	t_rgb;

struct		s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

struct		s_rgb
{
	int		red;
	int		green;
	int		blue;
};

struct		s_data
{
	void	*mlx;
	void	*win;
	int		name;
	t_image	img;
	t_rgb	ground;
	t_rgb	roof;
};

///////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------|
//														|
//						src/utils						|
//														|
//------------------------------------------------------|

//
//--------------------------------------------------------------------------|
//								ft_close.c									|
//--------------------------------------------------------------------------|

int		ft_clean_close(t_data *data, int error);
int		ft_cross(t_data *data);

//
//--------------------------------------------------------------------------|
//								ft_init_maps.c								|
//--------------------------------------------------------------------------|

//
//--------------------------------------------------------------------------|
//								ft_init_mlx.c								|
//--------------------------------------------------------------------------|

int		ft_init_mlx(t_data *data);

//
//--------------------------------------------------------------------------|
//		event/					ft_key_event.c								|
//--------------------------------------------------------------------------|

int		ft_key_press(int keycode, void *param);

#endif
