/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/26 12:23:15 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include "X.h"
# include "mlx.h"

//typedef of all structure
typedef struct s_pos		t_pos;
typedef struct s_gnl		t_gnl;
typedef struct s_parsing	t_parsing;
typedef struct s_image		t_image;
typedef struct s_texture	t_texture;
typedef struct s_player		t_player;
typedef struct s_exec		t_exec;
typedef struct s_data		t_data;
typedef struct s_start		t_start;

struct		s_pos
{
	int	px_y;
	int	px_x;
	int	size;
};

struct		s_gnl
{
	char	*str;
	t_gnl	*prev;
	t_gnl	*next;
};

struct		s_parsing
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

struct		s_texture
{
	void	*texture_ea;
	void	*texture_no;
	void	*texture_so;
	void	*texture_we;
};

struct		s_player
{
	double		pos_y;
	double		pos_x;
	double			dir_y;
	double			dir_x;
	double			dir_z;
	double		angle;
	t_data		*data;
};

struct s_start
{
	int	nx, ny, sx, sy, ex, ey, ox, oy;
	int	nx2, ny2, sx2, sy2, ex2, ey2, ox2, oy2;
	int	px, py;
	double	cx, cy, cz, ix, iy, iz;
	double fov, rh, rv;
};

struct		s_exec
{
	int				max_height;
	int				max_width;
	unsigned int	floor;
	unsigned int	sky;
	char			**tab;
	t_texture		texture;
	t_player		player;
	t_pos			pos;
	t_start			s;
	int				zoom;
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
	void		*mlx;
	void		*win;
	int			name;
	t_image		img;
	t_parsing	parsing;
	t_exec		exec;
};


/*MATHS*/
int		ft_start(t_exec *e, t_data *d);
int		ft_intersection(t_exec *e, t_data *d, char c, int i, int j);
void	ft_init_point(t_exec *e);
void	ft_init_camera(t_exec *e);
void	ft_director_vector(t_exec *e, int i, int j, char c);
void	ft_fov_h_and_v_ratio(t_exec *e);
double	ft_find_t(t_exec *e, char c);
int		ft_left_right(int keycode, t_exec *e, t_data *d);







/*-----------------src/draw-----------------*/

//------------[  ft_draw_maps_2d.c  ]

void	ft_draw_map_tile(t_data *data);

//------------[  ft_draw_sky_floor.c  ]

void	ft_draw_sky_floor(t_data *data);

//------------[  ft_refresh_view.c  ]

void	ft_refresh_view(t_data *data);

/*-----------------src/init-----------------*/

//------------[  ft_init_struct.c  ]

void	ft_init_parsing(t_parsing *parsing);
void	ft_init_data(t_data *data);

//------------[  ft_init_mlx.c  ]

int		ft_init_mlx(t_data *data);

/*-----------------src/parsing-----------------*/
//------------[  ft_check_format_save_color.c  ]

int		ft_check_format_save_color(t_parsing *parsing);

//------------[  ft_check_maps_closed.c  ]

int		ft_check_maps_closed(t_parsing *parsing, char **tab);

//------------[  ft_check_maps.c  ]

int		ft_check_maps(t_parsing *parsing);

//------------[  ft_check_param.c  ]

int		ft_check_param(t_parsing *parsing);

//------------[  ft_clear_str_of_texture.c  ]

int		ft_clear_parameters(t_parsing *parsing);

//------------[  ft_find_param.c  ]

int		ft_find_line_texture(t_parsing *parsing, int i, int j);

//------------[  ft_compare_maps.c  ]

int		ft_check_no_nl_in_maps(t_parsing *parsing);

//------------[  ft_extract_map.c  ]

int		ft_extract_map(t_parsing *parsing);

//------------[  ft_find_player_pos.c  ]

void	ft_find_player_pos(char **tab, t_player *player);

//------------[  ft_parsing_cub.c  ]

int		ft_parsing_cub(t_data *data, char *scene_cub);

/*-----------------src/utils-----------------*/
//------------[  event/ft_key_event.c  ]

int		ft_key_press(int keycode, void *param);

//------------[  event/ft_is_event.c  ]

int		ft_is_player_move(int keycode);
int		ft_is_camera_move(int keycode);
int		ft_refresh_event(int keycode);

//------------[  ft_close.c  ]

int		ft_clean_close(t_data *data, int error);
int		ft_cross(t_data *data);

//------------[  ft_color.c  ]

void	ft_color_pixel(int color, int x, int y, t_data *data);

//------------[  ft_error.c  ]

int		ft_error_parsing(char *str, char *type);

//------------[  ft_get_file_in_oneline.c  ]

int		ft_get_all_file(t_data *data, int fd, int error);

//------------[  ft_is.c  ]

int		ft_is_player_char(int c);
int		ft_is_invalid_neighbor(char c);
int		ft_is_valid_char(int c);

//------------[  ft_print_settings.c  ]

void	ft_print_settings(void);

/*-----------------src/utils_struct-----------------*/

//------------[  ft_clear_struct.c  ]

void	ft_clear_exec(t_exec *exec);
void	ft_clear_parsing(t_parsing *parsing);

//------------[  t_gnl.c  ]

void	t_gnl_clear(t_parsing *parsing);
int		t_gnl_add_end(t_parsing *parsing, char *str);

//------------[  t_pos.c  ]

void	t_pos_set_draw_max(t_pos *pos, int zoom, int x);

#endif
