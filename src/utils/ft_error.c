/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:22:18 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/17 17:22:14 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

int	ft_error_parsing(char *str, char *type)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (type)
		ft_putstr_fd(type, 2);
	return (1);
}
