/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaussel <mlaussel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:02:49 by mlaussel          #+#    #+#             */
/*   Updated: 2025/06/04 15:29:51 by mlaussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_cub.h"
#include "ft_define.h"

/**
 * @brief `search north and south wall`
 *
 * p.30 : "The simplest way to navigate planes is
 * to start at the player position index (O),
 *  then increment or decrement this according
 * to the direction of the ray"
 */
void	ft_north_and_south_walls(t_data *d, char **tab)
{
	int	x;
	int	y;

	x = d->exec.player.pos_x;
	y = d->exec.player.pos_y;
	while (y > 0)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.n.a = d->exec.cardi.n[y].a;
			d->exec.s.n.b = d->exec.cardi.n[y].b;
			d->exec.s.n.c = d->exec.cardi.n[y].c;
			d->exec.s.n.d = d->exec.cardi.n[y].d;
			break ;
		}
		y--;
	}
	y = d->exec.player.pos_y;
	while (y < d->exec.max_height)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.s.a = d->exec.cardi.s[y].a;
			d->exec.s.s.b = d->exec.cardi.s[y].b;
			d->exec.s.s.c = d->exec.cardi.s[y].c;
			d->exec.s.s.d = d->exec.cardi.s[y].d;
			break ;
		}
		y++;
	}
}

/**
 * @brief `search east and south west`
 *
 * p.30 : "The simplest way to navigate planes is
 * to start at the player position index (O),
 *  then increment or decrement this according
 * to the direction of the ray"
 */
void	ft_east_and_west_walls(t_data *d, char **tab)
{
	int	x;
	int	y;

	x = d->exec.player.pos_x;
	y = d->exec.player.pos_y;
	while (x > 0)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.e.a = d->exec.cardi.e[x].a;
			d->exec.s.e.b = d->exec.cardi.e[x].b;
			d->exec.s.e.c = d->exec.cardi.e[x].c;
			d->exec.s.e.d = d->exec.cardi.e[x].d;
			break ;
		}
		x--;
	}
	x = d->exec.player.pos_x;
	while (x < d->exec.max_width)
	{
		if (tab[y][x] == '1')
		{
			d->exec.s.w.a = d->exec.cardi.w[x].a;
			d->exec.s.w.b = d->exec.cardi.w[x].b;
			d->exec.s.w.c = d->exec.cardi.w[x].c;
			d->exec.s.w.d = d->exec.cardi.w[x].d;
			break ;
		}
		x++;
	}
}


// void	ft_init_wall(t_wall *w)
// {
// 	// 1- Trouver la case où se trouve le joueur (int pour case)
// 	w->pos_x = (int)d->exec.player.pos_x;
// 	w->pos_y = (int)d->exec.player.pos_y;
// 	// 2- Direction du rayon
// 	w->dir_x = d->exec.player.dir_x;
// 	w->dir_y = d->exec.player.dir_y;
// 	// 3- Calculer la distance pour avancer d’une case sur X et Y
// 	w->dist_x = fabs(1 / w->dir_x);
// 	w->dist_y = fabs(1 / w->dir_y);
// 	// 4- Déterminer le pas (step) sur X et Y (1 ou -1)
// 	if (w->dir_x < 0)
// 		w->step_x = -1;
// 	else
// 		w->step_x = 1;
// 	if (w->dir_y < 0)
// 		w->step_y = -1;
// 	else
// 		w->step_y = 1;
// 	// 5- Calculer la distance entre la position du joueur et
// 	//la première frontière sur X et Y
// 	if (w->step_x == -1)
// 		w->side_x = (d->exec.player.pos_x - w->pos_x) * w->dist_x;
// 	else
// 		w->side_x = (w->pos_x + 1.0 - d->exec.player.pos_x) * w->dist_x;

// 	if (w->step_y == -1)
// 		w->side_y = (d->exec.player.pos_y - w->pos_y) * w->dist_y;
// 	else
// 		w->side_y = (w->pos_y + 1.0 - d->exec.player.pos_y) * w->dist_y;
// }

// /**
//  * @brief
//  *
//  * p.30 : "looking at the u sign" --> step_x and step_y 1 or -1
//  */
// void	ft_walls(t_data *d)
// {
// 	t_wall	w;

// 	ft_init_wall(&w);
// 	w.hit = 0;
// 	while (w.hit == 0)
// 	{
// 		if (w.side_x < w.side_y)
// 		{
// 			w.side_x += w.dist_x;
// 			w.pos_x += w.step_x;
// 			w.side = 0;
// 		}
// 		else
// 		{
// 			w.side_y += w.dist_y;
// 			w.pos_y += w.step_y;
// 			w.side = 1;
// 		}
// 		if (d->exec.tab[w.pos_y][w.pos_x] == '1')
// 			w.hit = 1;
// 	}
// }
