/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gnl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:30:32 by mlaussel          #+#    #+#             */
/*   Updated: 2025/05/17 17:07:48 by fcretin          ###   ########.fr       */
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

int	t_gnl_add_end(t_parsing *parsing, char *str)
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
	if (parsing->gnl == NULL)
	{
		parsing->gnl = new;
		return (0);
	}
	tmp = parsing->gnl;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (0);
}

void	t_gnl_clear(t_parsing *parsing)
{
	t_gnl	*tmp;

	while (parsing->gnl != NULL)
	{
		tmp = parsing->gnl;
		parsing->gnl = parsing->gnl->next;
		if (tmp->str)
			free(tmp->str);
		free(tmp);
	}
}
