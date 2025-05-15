/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_openable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:06:53 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 18:09:28 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fcntl.h"

int	ft_is_openable(char *file_path_name)
{
	int	fd;

	fd = open(file_path_name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (close(fd))
		return (0);
	return (1);
}
