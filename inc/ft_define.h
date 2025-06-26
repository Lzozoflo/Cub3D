/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:32:29 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/26 10:32:30 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINE_H
# define FT_DEFINE_H

// Mouvement speed
# define MS 0.02
# define ROTATION 0.02
# define RADIUSPLAYER 0.3

// Window params
# define SCALE 3
# define WIN_SIZE 1000
# define WIN_NAME "Cub3D"
# define MAX_D 10.0

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

// Color player minimaps px
# define PX_GRAY_DARK  0x444444

//	number of tile on the minimaps
# define MINIMAPS_SCREEN_TILES 10

//	Error message
# define ERROR_EXTENSION " has a bad extension."
# define ERROR_OPEN " can't be open."

# define ERROR_RGB_FORMAT "R,G,B Format is not correct: "
# define ERROR_RGB_VALUE "R,G,B Wrong value: "
# define ERROR_RGS_SPACE " has separate parametes.\n"

# define ERROR_INVALID_CHAR "Invalid char in the maps."
# define ERROR_ZERO_PLAYER "Zero player was define."
# define ERROR_TWO_PLAYER "Two player was define."
# define ERROR_MAP_SEPARATE "A new line in a maps was not accepted."
# define ERROR_MAP_CLOSE "Unplayable tile adjacent to a playable tile."

# define ERROR_MAPS_NULL "The maps was not found."
# define ERROR_DOUBLE_PARAM "This parameters was found 2 time: "
# define ERROR_BAD_PARAM "Unknown parameter."

# define PI 3.14159265358979323846

#endif
