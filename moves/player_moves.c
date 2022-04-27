/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:56:33 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/27 19:03:59 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemy(t_vars *vars, int id, int x, int y)
{
	set_image(vars, "prova.xpm", vars->enemies[id].x, vars->enemies[id].y);
	vars->map->data[vars->enemies[id].x + x][vars->enemies[id].y + y] = 'N';
	vars->map->data[vars->enemies[id].x][vars->enemies[id].y] = '0';
	vars->enemies[id].x += x;
	vars->enemies[id].y += y;
	if (vars->enemies[id].x == vars->pp[0] && vars->enemies[id].y == vars->pp[1])
		you_lost(vars);
}

void	get_enemies(t_vars *vars, int i, int j, int *n)
{
	vars->setting[i][j] = set_image(vars, "xpms/enemy/enemy1.xpm", i, j);
	vars->enemies[*n].id = *n;
	vars->enemies[*n].x = i;
	vars->enemies[*n].y = j;
	(*n)++;
}

void	set_enemies(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->n_en)
	{
		if (vars->status_en == 0)
			choose_move_enemy(vars, i);
		else if (vars->status_en == 1)
			set_image(vars, "xpms/enemy/enemy1.xpm", vars->enemies[i].x, vars->enemies[i].y);
		else if (vars->status_en == 2)
			set_image(vars, "xpms/enemy/enemy1.xpm", vars->enemies[i].x, vars->enemies[i].y);
	}
	if (vars->status_en != 0)
		vars->status_en--;
}

int	can_go(t_vars *vars, int id, int x, int y)
{
	char	p;

	p = vars->map->data[vars->enemies[id].x + x][vars->enemies[id].y + y];
	if (p == '0' || p == 'P')
		return (1);
	return (0);
}

void	choose_move_enemy(t_vars *vars, int id)
{
	int	dx;
	int	dy;

	dx = vars->pp[0] - (vars->enemies[id].x);
	dy = vars->pp[1] - (vars->enemies[id].y);
	if (vars->enemies[id].x == vars->pp[0] && vars->enemies[id].y == vars->pp[1])
		you_lost(vars);
	if (abs(dx) >= abs(dy))
	{
		if (dx > 0 && can_go(vars, id, 1, 0))
			move_enemy(vars, id, 1, 0);
		else if (dx < 0 && can_go(vars, id, -1, 0))
			move_enemy(vars, id, -1, 0);
		else
		{
			if (dy > 0 && can_go(vars, id, 0, 1))
				move_enemy(vars, id, 0, 1);
			else if (dy < 0 && can_go(vars, id, 0, -1))
				move_enemy(vars, id, 0, -1);
			else if (can_go(vars, id, 1, 0))
				move_enemy(vars, id, 1, 0);
			else
				move_enemy(vars, id, 1, 0);
		}
	}
	else
	{
		if (dy > 0 && can_go(vars, id, 0, 1))
			move_enemy(vars, id, 0, 1);
		else if (dy < 0 && can_go(vars, id, 0, -1))
			move_enemy(vars, id, 0, -1);
		else
		{
			if (dx > 0 && can_go(vars, id, 1, 0))
				move_enemy(vars, id, 1, 0);
			else if (dx < 0 && can_go(vars, id, -1, 0))
				move_enemy(vars, id, -1, 0);
			else if (can_go(vars, id, 0, -1))
				move_enemy(vars, id, 0, -1);
			else
				move_enemy(vars, id, 0, 1);
		}
	}
}
