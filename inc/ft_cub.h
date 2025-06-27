/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:01:01 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/27 12:00:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include "../minilibx-linux/mlx.h"
# include "ft_define.h"
# include <sys/types.h>

//typedef of all structure
typedef struct s_plane			t_plane;
typedef struct s_cardinals		t_cardinals;
typedef struct s_rgb			t_rgb;
typedef struct s_minimap		t_minimap;
typedef struct s_gnl			t_gnl;
typedef struct s_parsing		t_parsing;
typedef struct s_image			t_image;
typedef struct s_u_texture		t_u_texture;
typedef struct s_texture		t_texture;
typedef struct s_player			t_player;
typedef struct s_wall			t_wall;
typedef struct s_exec			t_exec;
typedef struct s_data			t_data;
typedef struct s_radius			t_radius;
typedef struct s_ray			t_ray;
typedef struct s_start			t_start;
typedef struct s_keys			t_keys;

struct		s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
};

struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};

struct		s_minimap
{
	unsigned int	color_minimap[5];
	int				zoom;
	int				tile_size;
	int				tab_start_x;
	int				tab_start_y;
	int				tab_end_x;
	int				tab_end_y;
	int				win_xy_min;
	int				win_xy_max;
	double			center;
	double			div;
	double			offset_x;
	double			offset_y;
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
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
	void	*texture_ea;
	void	*texture_no;
	void	*texture_so;
	void	*texture_we;
};

struct s_plane
{
	int	a;
	int	b;
	int	c;
	int	d;
};

struct s_cardinals
{
	t_plane	*n;
	t_plane	*w;
	t_plane	*e;
	t_plane	*s;
};

struct s_ray
{
	double		dir_y;
	double		dir_x;
	double		dir_z;
};

struct s_radius
{
	t_ray	**ray;
};

struct		s_player
{
	double			pos_z;
	double			pos_x;
	double			pos_y;
	char			pos;
	double			dir_y;
	double			dir_x;
	double			dir_z;
	double			angle;
	int				moove;
	t_data			*data;
};

struct s_start
{
	double			cx;
	double			cy;
	double			cz;
	double			ix;
	double			iy;
	double			iz;
	double			fov;
	double			rh;
	double			rv;
};

struct s_wall
{
	int		x_check;
	int		y_check;
	double	t_n;
	double	t_s;
	double	t_e;
	double	t_w;
	double	t_min;
	char	face;
};

struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	int		m;
};

struct		s_exec
{
	t_keys			keys;
	int				max_height;
	int				max_width;
	unsigned int	floor;
	unsigned int	sky;
	char			**tab;
	t_wall			wall;
	t_cardinals		cardi;
	t_radius		radius;
	t_radius		all_r;
	t_texture		texture;
	t_player		player;
	t_minimap		mini;
	t_start			s;
};

struct		s_data
{
	void		*mlx;
	void		*win;
	int			name;
	t_image		img;
	t_parsing	parsing;
	t_exec		exec;
	int			win_scale;
};

/*-----------------src/draw-----------------*/
//------------[  ft_draw_maps_2d.c  ]

void	ft_draw_circle(t_data *data, t_minimap *m);
void	ft_draw_minimap(t_data *data, t_minimap *m);

//------------[  ft_refresh_view.c  ]

void	ft_refresh_view(t_data *data);

/*-----------------src/draw/raycast-----------------*/
//------------[  ft_all_radius.c  ]
int		ft_calculate_all_radius(t_exec *e, int win_scale);
void	ft_free_radius(t_radius *r, int win_scale);

//------------[  ft_math_calculation_walls.c  ]
void	ft_intersection_coord(t_exec *e, double t, t_ray radius);
double	ft_find_plane_intersection_n_s(t_exec *e, t_plane *plane, t_ray radius);
double	ft_find_plane_intersection_e_w(t_exec *e, t_plane *plane, t_ray radius);

//------------[  ft_math_calculation.c  ]
void	ft_fov_h_and_v_ratio(t_exec *e, int win_scale);
void	ft_director_vector(t_exec *e, int i, int j, int win_scale);
void	ft_init_camera(t_exec *e);

//------------[  ft_move_rotate.c  ]
void	ft_free_rotate_radius(t_radius *all_r, int win_scale);
int		ft_rotate_radius(t_exec *e, int win_scale);
void	ft_move(t_exec *e);

//------------[  ft_planes.c  ]
int		ft_init_plane(t_exec *e);
void	ft_free_cardi(t_exec *e);
void	ft_group_all_planes(t_data *d);

//------------[  ft_shadow.c  ]
int		ft_color_shadow_floor(const unsigned int colorfloor, int y,
			const size_t half);
int		ft_color_shadow_ceiling(const unsigned int colorceiling,
			int y, const size_t half);
int		ft_shadow(int color, t_data *d);

//------------[  ft_start.c  ]
int		ft_init_start(t_exec *e, t_data *d);
void	ft_start(t_exec *e, t_data *d);

//------------[  ft_texture.c  ]
int		ft_texture(t_data *d, char c);

//------------[  ft_texture_utils.c  ]
void	ft_destroy_textures(t_data *d);
void	ft_cal_texture(t_data *d);

//------------[  ft_wall_intersection.c  ]
void	ft_north_wall(t_exec *e, int y, t_ray radius);
void	ft_south_wall(t_exec *e, int y, t_ray radius);
void	ft_east_wall(t_exec *e, int x, t_ray radius);
void	ft_west_wall(t_exec *e, int x, t_ray radius);

//------------[  ft_walls.c  ]
void	ft_walls(t_data *d, int i, int j, t_ray radius);

/*-----------------src/init-----------------*/
//------------[  ft_init_exec_struct.c  ]
void	ft_init_keys(t_exec *exec);
void	ft_init_textures_img(t_exec *exec);
void	ft_init_cardi(t_exec *exec);
void	ft_init_ray(t_exec *exec);

//------------[  ft_init_mlx.c  ]

int		ft_init_mlx(t_data *data);

//------------[  ft_init_planes.c  ]
void	ft_west_plane(t_cardinals *c, int x);
void	ft_east_plane(t_cardinals *c, int x);
void	ft_north_plane(t_cardinals *c, int y);
void	ft_south_plane(t_cardinals *c, int y);

//------------[  ft_init_struct.c  ]

void	ft_init_parsing(t_parsing *parsing);
void	ft_init_data(t_data *data);

//------------[  ft_init_textures.c  ]
void	ft_destroy_textures(t_data *d);
int		ft_init_textures(t_data *d);

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
//------------[  event/ft_wasd.c  ]
int		ft_w(t_player *player);
int		ft_s(t_player *player);
int		ft_a(t_player *player);
int		ft_d(t_player *player);
int		ft_wasd(t_data *data, t_player *p);

//------------[  event/ft_key_event.c  ]
int		ft_check_pos_colision(t_player *p, double x, double y);
int		ft_key_press(int keycode, void *param);
int		ft_key_release(int keycode, void *param);
int		ft_handle_keys(void *param);

//------------[  event/ft_is_event.c  ]

int		ft_is_player_move(int keycode);
int		ft_is_camera_move(int keycode);
int		ft_is_refresh_event(int keycode);

//------------[  ft_close.c  ]

int		ft_clean_close(t_data *data, int error);
int		ft_cross(t_data *data);

//------------[  ft_color.c  ]

void	ft_color_pixel(unsigned int color, int x, int y, t_data *data);

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

//------------[  t_minimap_set_color.c  ]
void	t_minimap_set_color(t_exec *exec, t_minimap *m);

//------------[  t_minimap.c  ]

void	t_minimaps_set(t_minimap *mini, t_player *p, int zoom);

#endif
