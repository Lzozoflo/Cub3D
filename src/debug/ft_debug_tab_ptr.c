/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_tab_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:37:07 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/18 13:09:58 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"

void	debug_put_tab_d1(const char *str, char **tab, int f, int s)
{
	int	i;

	i = -1;
	if (DEBUG == 1 || DEBUG == f || DEBUG == s)
	{
		printf("----------------------------------------------------------\n");
		if (str)
		{
			while (tab[++i])
			{
				printf("DEBUG -> %s[%d]: [%s]\n", str, i, tab[i]);
			}
		}
		else
		{
			while (tab[++i])
			{
				printf("DEBUG -> [%d]: [%s]\n", i, tab[i]);
			}
		}
		printf("----------------------------------------------------------\n");
	}
}

void	debug_put_tab(const char *str, char **tab, int f, int s)
{
	int	i;

	i = -1;
	if (DEBUG == f || DEBUG == s)
	{
		printf("----------------------------------------------------------\n");
		if (str)
		{
			while (tab[++i])
			{
				printf("%s[%d]: [%s]\n", str, i, tab[i]);
			}
		}
		else
		{
			while (tab[++i])
			{
				printf("[%d]: [%s]\n", i, tab[i]);
			}
		}
		printf("----------------------------------------------------------\n");
	}
}

void	debug_put_ptr_d1(const char *str, void *ptr, int f, int s)
{
	if (DEBUG == 1 || DEBUG == f || DEBUG == s)
	{
		printf("\nDEBUG -> %s: [%p]\n", str, ptr);
	}
}

void	debug_put_ptr(const char *str, void *ptr, int f, int s)
{
	if (DEBUG == f || DEBUG == s)
	{
		printf("\nDEBUG -> %s: [%p]\n", str, ptr);
	}
}
