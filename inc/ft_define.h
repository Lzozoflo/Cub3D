/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:32:29 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 13:50:32 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINE_H
# define FT_DEFINE_H

// Window params
# define WIN_SIZE 2000
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
// Key Code
# define M 109

// Color square px
	// Red
# define PX_RED 0x00FF0000
	// Green
# define PX_GREEN 0x0000FF00
	// Blue
# define PX_BLUE  0x000000FF
	// Red opaque
# define PX_REDO 0xFFFF0000
	// Blue opaque
# define PX_BLUEO 0xFF0000FF
	// Green opaque
# define PX_GREENO     0xFF00FF00
# define PX_GRAY_LIGHT 0xCCCCCC
# define PX_GRAY       0x888888
# define PX_GRAY_DARK  0x444444

// Mouvement speed
# define MS 1

# define ERROR_EXTENSION " has a bad extension."
# define ERROR_OPEN " can't be open."

# define ERROR_RGB_FORMAT "R,G,B Format is not correct: "
# define ERROR_RGB_VALUE "R,G,B Wrong value: "
# define ERROR_RGS_SPACE " has separate parametes.\n"

# define ERROR_INVALID_CHAR "Invalid char in the maps."
# define ERROR_ZERO_PLAYER "Zero player was define."
# define ERROR_TWO_PLAYER "Two player was define."
# define ERROR_MAP_SEPARATE "A new line in a maps was not accepted."
# define ERROR_MAP_CLOSE "A Player or a Ground not on the maps."

# define ERROR_MAPS_NULL "The maps was not found."
# define ERROR_DOUBLE_PARAM "This parameters was found 2 time: "
# define ERROR_BAD_PARAM "Unknown parameter."

#endif
