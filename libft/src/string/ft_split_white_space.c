/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:34:46 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/15 17:24:50 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_word(const char *s)
{
	int	i;
	int	iw;

	i = 0;
	iw = 0;
	while (*s)
	{
		if (iw == 0 && !ft_is_white_space(*s))
		{
			iw = 1;
			i++;
		}
		else if (iw == 1 && ft_is_white_space(*s))
			iw = 0;
		s++;
	}
	return (i);
}

static int	ft_len_word(const char *str)
{
	int	i;

	i = 0;
	while (*str && !ft_is_white_space(*str))
	{
		str++;
		i++;
	}
	return (i);
}

char	**ft_split_white_space(char const *s)
{
	char	**str;
	int		i;
	int		nw;

	i = 0;
	nw = ft_num_word(s);
	str = (char **)malloc(sizeof(char *) * (nw + 1));
	if (!str)
		return (NULL);
	while (nw--)
	{
		while (*s && ft_is_white_space(*s))
			s++;
		str[i] = ft_substr(s, 0, ft_len_word(s));
		if (!str[i] && i != 0)
			return (ft_freetab(str, i));
		else if (!str[i] && i == 0)
			return (ft_free_null(str));
		s = s + ft_len_word(s);
		i++;
	}
	str[i] = NULL;
	return (str);
}
