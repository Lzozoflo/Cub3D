/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:55:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/14 16:20:38 by fcretin          ###   ########.fr       */
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
 *-------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------
 *
 *
 */
# define DEBUG 0

/*
 *---------------src/debug/ft_debug_1.c
 */

void	debug_put_tab_d1(const char *str, char **tab, int f, int s);
void	debug_put_ptr_d1(const char *str, void *ptr, int f, int s);

//without debug == 1
void	debug_put_tab(const char *str, char **tab, int f, int s);
void	debug_put_ptr(const char *str, void *ptr, int f, int s);
void	debug_put_gnl_list(const char *str, t_gnl *tmp, int f, int s);

/*
 *---------------src/debug/ft_debug_2.c
 */

void	debug_put_str_d1(const char *str1, char *str2, int f, int s);
void	debug_put_int_d1(const char *str1, int value, int f, int s);

//without debug == 1
void	debug_put_str(const char *str1, char *str2, int f, int s);
void	debug_put_int(const char *str1, int value, int f, int s);

#endif
