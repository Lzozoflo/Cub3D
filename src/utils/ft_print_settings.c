/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:52:32 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/19 09:20:24 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_define.h"
#include "ft_debug.h"

void	ft_print_settings(void)
{
	printf("                    %sWelcome on Cub3D%s\n\n", GREEN, RESET);
	printf("                   %sThis is our settings%s:\n\n", BLUE, RESET);
	printf("                      %sW%s: move forward\n", BLUE, RESET);
	printf("    %sA%s: strafe left", BLUE, RESET);
	printf("    %sS%s: move backward", BLUE, RESET);
	printf("    %sD%s: strafe right\n\n", BLUE, RESET);
	printf("           %s<%s: rotate left", BLUE, RESET);
	printf("           %s>%s: rotate right\n", BLUE, RESET);
}
