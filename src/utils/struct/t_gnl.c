/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gnl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:30:32 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/14 15:05:11 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

static t_gnl	*t_gnl_new(char *str)
{
	t_gnl	*new;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(t_gnl));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->str = str;
	return (new);
}

int	t_gnl_add_end(t_maps *maps, char *str)
{
	t_gnl	*tmp;
	t_gnl	*new;

	new = t_gnl_new(str);
	if (new == NULL)
	{
		if (str)
			free(str);
		return (-1);
	}
	if (maps->gnl == NULL)
	{
		maps->gnl = new;
		return (0);
	}
	tmp = maps->gnl;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (0);
}

void	t_gnl_clear(t_maps *maps)
{
	t_gnl	*tmp;

	while (maps->gnl != NULL)
	{
		tmp = maps->gnl;
		maps->gnl = maps->gnl->next;
		if (tmp->str)
			free(tmp->str);
		free(tmp);
	}
}
