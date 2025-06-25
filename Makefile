.PHONY: all clean fclean re f fclear c clear libmlx libft

NAME			:=	Cub3D
INCLUDES		=	-I $(HEADERS_DIR) -I $(D_INC_LIBFT)
CC				:=	cc
FLAGFAST		:=	-march=native -ffast-math -flto -O3
CFLAGS			:=	-Wall -Wextra -Werror $(FLAGFAST)
CFLAGSS			:=	-Weverything -Wno-padded -Wno-reserved-id-macro -Wno-strict-prototypes $(FLAGFAST)
RM				:=	rm -fr
MLX_FLAG		:=	-Lminilibx-linux -lmlx -lX11 -lXext


#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################


# Directories
D_SRC			:=		./src/
HEADERS_DIR		:=		./inc/


# Source Directories
D_DEBUG			:=		debug/
D_DRAW			:=		draw/
D_INIT			:=		init/
D_UTILS			:=		utils/
D_PARSING		:=		parsing/
D_U_EVENT		:=		event/
D_STRUCT		:=		utils_struct/
D_RAYCAST		:=		raycast/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				:=		ft_cub.h						\
						ft_debug.h						\
						ft_define.h


SRC				:=		main.c


SRC_DEBUG		:=		ft_debug_maps.c					\
						ft_debug_str_int.c				\
						ft_debug_tab_ptr.c


SRC_DRAW		:=		ft_draw_maps_2d.c				\
						ft_refresh_view.c

SRC_RAYCAST		:=		ft_all_radius.c					\
						ft_math_calculation_walls.c		\
						ft_math_calculation.c			\
						ft_move_rotate.c				\
						ft_planes.c						\
						ft_shadow.c 					\
						ft_start.c						\
						ft_texture.c					\
						ft_textures_utils.c				\
						ft_wall_intersection.c			\
						ft_walls.c

SRC_INIT		:=		ft_init_exec_struct.c			\
						ft_init_mlx.c					\
						ft_init_planes.c				\
						ft_init_struct.c				\
						ft_init_textures.c


SRC_PARSING		:=		ft_check_format_save_color.c	\
						ft_check_maps_closed.c			\
						ft_check_maps.c					\
						ft_check_param.c				\
						ft_clear_str_of_texture.c		\
						ft_compare_map.c				\
						ft_find_param.c					\
						ft_extract_map.c				\
						ft_find_player_pos.c			\
						ft_parsing_cub.c


SRC_UTILS		:=		ft_close.c						\
						ft_color.c						\
						ft_error.c						\
						ft_get_file_in_oneline.c		\
						ft_is.c							\
						ft_print_settings.c


SRC_U_EVENT		:=		ft_is_event.c					\
						ft_key_event.c					\
						ft_mouse_event.c				\
						ft_wasd.c


SRC_STRUCT		:=		ft_clear_struct.c				\
						t_gnl.c							\
						t_minimap_set_color.c			\
						t_minimap.c


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(SRC)													\
						$(addprefix $(D_DEBUG), $(SRC_DEBUG))					\
						$(addprefix $(D_DRAW), $(SRC_DRAW))						\
						$(addprefix $(D_DRAW)$(D_RAYCAST), $(SRC_RAYCAST))		\
						$(addprefix $(D_INIT), $(SRC_INIT))						\
						$(addprefix $(D_PARSING), $(SRC_PARSING))				\
						$(addprefix $(D_UTILS), $(SRC_UTILS))					\
						$(addprefix $(D_UTILS)$(D_U_EVENT), $(SRC_U_EVENT))		\
						$(addprefix $(D_STRUCT), $(SRC_STRUCT))



INCS				=		$(addprefix $(HEADERS_DIR), $(INC))

OBJS_DIR			:=		.objs/
OBJS_FILES			:=		$(SRCS:.c=.o)
OBJS				:=		$(addprefix $(OBJS_DIR), $(OBJS_FILES))

DEPS_DIR			:=		deps/
DEPS_FILES			:=		$(OBJS_FILES:.o=.d)
DEPS				:=		$(addprefix $(DEPS_DIR), $(DEPS_FILES))

#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all : $(NAME)


$(NAME)				:	libmlx libft $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAG) $(NAME_LIB) -o $(NAME)  -lm

$(DEPS_DIR) 		:
		mkdir -p $(DEPS_DIR)

$(OBJS_DIR)%.o		:	$(D_SRC)%.c Makefile | $(DEPS_DIR)
			@mkdir -p $(dir $@)
			@mkdir -p $(dir $(DEPS_DIR)$*)
			$(CC) $(CFLAGS) $(INCLUDES) -MP -MMD -MF $(DEPS_DIR)$*.d -c $< -o $@

libmlx			:
			$(MAKE) -C minilibx-linux

#############################################################################################
#																							#
#										// LIBFT											#
#																							#
#############################################################################################


D_INC_LIBFT		=		./libft/inc/


NAME_LIB		=		./libft/libft.a


libft			:
			$(MAKE) -C libft


#############################################################################################
#																							#
#									// CLEAN  FCLEAN  RE									#
#																							#
#############################################################################################


clean			:
			$(RM) $(OBJS_DIR) $(DEPS_DIR)
			$(MAKE) -C minilibx-linux clean
			$(MAKE) -C libft clean


fclean			: clean
			$(RM) $(NAME)
			$(MAKE) -C libft fclean


re				:	 fclean all


#############################################################################################
#																							#
#										Allias												#
#																							#
#############################################################################################


c				:	clear
clear			:	clean

f				:	fclean
fclear			:	fclean

-include $(DEPS)
