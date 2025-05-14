/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:22:18 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/14 13:58:08 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "ft_debug.h"
#include "libft.h"

// Si un problème de configuration de n’importe quel type est rencontré dans
// le fichier, le programme doit quitter et renvoyer "Error\n" suivi d’un message
// d’erreur explicite de votre choix.
// 9

int	ft_error_parsing(char *str, char *type)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (type)
		ft_putstr_fd(type, 2);
	return (1);
}
