.PHONY: all clean fclean re f fclear c clear libmlx libft

NAME			=	Cub3D
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
CFLAGSS			=	-Weverything -Wno-padded
RM				=	rm -fr
MLX_FLAG		=	-Lminilibx-linux -lmlx -lX11 -lXext


#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################


# Directories
D_SRC			=		src/
D_OBJ			=		object/
D_INC			=		inc/


# Source Directories
D_DEBUG			=		debug/
D_INIT			=		init/
D_UTILS			=		utils/
D_U_EVENT		=		event/


#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


INC				=		ft_cub.h			\
						ft_debug.h


SRC				=		main.c				\


SRC_DEBUG		=		ft_debug_1.c		\
						ft_debug_2.c


SRC_INIT		=		ft_init_maps.c		\
						ft_init_mlx.c		\
						ft_parsing_cub.c


SRC_UTILS		=		ft_close.c			\
						ft_error.c			\
						ft_is.c



SRC_U_EVENT		=		ft_key_event.c		\
						ft_mouse_event.c


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


# All src in his Src Directories
SRCS			=		$(addprefix $(D_SRC), $(SRC))								\
						$(addprefix $(D_SRC)$(D_DEBUG), $(SRC_DEBUG))				\
						$(addprefix $(D_SRC)$(D_INIT), $(SRC_INIT))					\
						$(addprefix $(D_SRC)$(D_UTILS), $(SRC_UTILS))				\
						$(addprefix $(D_SRC)$(D_UTILS)$(D_U_EVENT), $(SRC_U_EVENT))


# Changing all source directories to object directories
OBJS			=		$(subst $(D_SRC), $(D_OBJ), $(SRCS:.c=.o))


INCS			=		$(addprefix $(D_INC), $(INC))


#############################################################################################
#																							#
#										// COMPILATION										#
#																							#
#############################################################################################


all : libft libmlx $(NAME)


$(NAME)			:	libft $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAG) $(NAME_LIB) -o $(NAME)

$(D_OBJ)%.o		:	$(D_SRC)%.c Makefile $(INCS) $(NAME_LIB)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@ -I $(D_INC) -I $(D_INC_LIBFT)

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
			$(RM) $(D_OBJ)
			$(MAKE) -C minilibx-linux clean
			$(MAKE) -C libft clean


fclean			:
			$(RM) $(D_OBJ)
			$(RM) $(NAME)
			$(MAKE) -C minilibx-linux clean
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
