/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:16:51 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 15:35:20 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_player_char(int c)
{
	return (c == 'E' || c == 'N' || c == 'S' || c == 'W');
}

int	ft_is_invalid_neighbor(char c)
{
	return (c == '0' || ft_is_player_char(c));
}


int	ft_is_valid_char(int c)
{
	return (c != '\0' && (c == '1' || c == '0' || c == ' '
			|| ft_is_player_char(c)));
}
