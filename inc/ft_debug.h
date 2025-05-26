/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:55:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/26 12:53:05 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

# include "ft_cub.h"
# include <stdio.h>

/*-------DEBUG Flags
 *
 *		if (DEBUG == 1 || DEBUG == "PART")
 *			printf("\nDEBUG -> ... :\n"");
 *-------------------------------------------------------------------------------
 *	0	=	Nothing.
 *-------------------------------------------------------------------------------
 *	1	=	All debug printed. (*!1* = flag 1 didnt print thit)
 *-------------------------------------------------------------------------------
 *	2	=	Event
 *		200	=	keycode.
 *		21	=	ft_key_event
 *		22	=
 *-------------------------------------------------------------------------------
 *	3	=	parsing
 *		31	=	read file
 *		32	=	tab
 *		33	=	list gnl
 *		34	=	swap ptr
 *		35	=	tab after format
 *		36	=	max_height && max_width
 *		37	=	maps bordered
 *		38	=	ft_check_no_nl_in_maps
 *		39	=	maps not closed
 *		40	=	Unknown parameter.
 *-------------------------------------------------------------------------------
 * 4 = maths
 * 		41 = fov, rh, rv
 *-------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------
 *
 *
 */
# define DEBUG 21

/*
 *---------------src/debug/ft_debug_tab_ptr.c
 */

void	debug_put_tab_d1(const char *str, char **tab, int f, int s);
void	debug_put_ptr_d1(const char *str, void *ptr, int f, int s);

//without debug == 1
void	debug_put_tab(const char *str, char **tab, int f, int s);
void	debug_put_ptr(const char *str, void *ptr, int f, int s);
void	debug_put_gnl_list(const char *str, t_gnl *tmp, int f, int s);

/*
 *---------------src/debug/ft_debug_str_int.c
 */

void	debug_put_str_d1(const char *str1, char *str2, int f, int s);
void	debug_put_int_d1(const char *str1, int value, int f, int s);

//without debug == 1
void	debug_put_str(const char *str1, char *str2, int f, int s);
void	debug_put_int(const char *str1, int value, int f, int s);

/*
 *---------------src/debug/ft_debug_maps.c
 */
void	debug_put_parsing(char **tab, int f, int s);

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN  "\033[32m"
# define BLUE  "\033[34m"
# define YELLOW "\033[33m"

#endif
