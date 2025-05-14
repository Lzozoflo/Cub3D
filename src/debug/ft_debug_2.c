/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:42:03 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/14 15:31:05 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "ft_cub.h"

void	debug_put_str_d1(const char *str1, char *str2, int f, int s)
{
	if (DEBUG == 1 || DEBUG == f || DEBUG == s)
	{
		if (!str2)
			printf("\nDEBUG -> %s\n", str1);
		else
			printf("\nDEBUG -> %s: [%s]\n", str1, str2);
	}
}

void	debug_put_str(const char *str1, char *str2, int f, int s)
{
	if (DEBUG == f || DEBUG == s)
	{
		if (!str2)
			printf("\nDEBUG -> %s\n", str1);
		else
			printf("\nDEBUG -> %s: [%s]\n", str1, str2);
	}
}

void	debug_put_int_d1(const char *str1, int value, int f, int s)
{
	if (DEBUG == 1 || DEBUG == f || DEBUG == s)
	{
		printf("\nDEBUG -> %s: [%d]\n", str1, value);
	}
}

void	debug_put_int(const char *str1, int value, int f, int s)
{
	if (DEBUG == f || DEBUG == s)
	{
		printf("\nDEBUG -> %s: [%d]\n", str1, value);
	}
}

void	debug_put_gnl_list(const char *str, t_gnl *tmp, int f, int s)
{
	if (DEBUG == f || DEBUG == s)
	{
		printf("----------------------------------------------------------\n");
		if (str)
		{
			while (tmp)
			{
				printf("DEBUG -> %s: %s", str, tmp->str);
				tmp = tmp->next;
			}
		}
		else
		{
			while (tmp)
			{
				printf("DEBUG -> : %s", tmp->str);
				tmp = tmp->next;
			}
		}
		printf("----------------------------------------------------------\n");
	}

}
