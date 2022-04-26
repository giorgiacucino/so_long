/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:56:33 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/26 14:30:44 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemy(t_vars *vars, t_enemy e, int x, int y)
{
	set_image(vars, "enemy.xpm", e.x + x, e.y + y);
	set_image(vars, "prova.xpm", e.x, e.y);
	vars->map->data[e.x + x][e.y + y] = 'N';
	vars->map->data[e.x][e.y] = '0';
	e.x += x;
	e.y += y;
}

// int	move_enemy_up(t_vars *vars)
// {
// 	if (vars->map->data[vars->pn[0] - 1][vars->pn[1]] == '1')
// 		return (0);
// 	set_image(vars, "enemy.xpm", vars->pn[0] - 1, vars->pn[1]);
// 	set_image(vars, "prova.xpm", vars->pn[0], vars->pn[1]);
// 	vars->map->data[vars->pn[0] - 1][vars->pn[1]] = 'N';
// 	vars->map->data[vars->pn[0]][vars->pn[1]] = '0';
// 	vars->pn[0]--;
// 	return (1);
// }

// int	move_enemy_down(t_vars *vars)
// {
// 	if (vars->map->data[vars->pn[0] + 1][vars->pn[1]] == '1')
// 		return (0);
// 	set_image(vars, "enemy.xpm", vars->pn[0] + 1, vars->pn[1]);
// 	set_image(vars, "prova.xpm", vars->pn[0], vars->pn[1]);
// 	vars->map->data[vars->pn[0] + 1][vars->pn[1]] = 'N';
// 	vars->map->data[vars->pn[0]][vars->pn[1]] = '0';
// 	vars->pn[0]++;
// 	return (1);
// }

// int	move_enemy_right(t_vars *vars)
// {
// 	if (vars->map->data[vars->pn[0]][vars->pn[1] + 1] == '1')
// 		return (0);
// 	set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1] + 1);
// 	set_image(vars, "prova.xpm", vars->pn[0], vars->pn[1]);
// 	vars->map->data[vars->pn[0]][vars->pn[1] + 1] = 'N';
// 	vars->map->data[vars->pn[0]][vars->pn[1]] = '0';
// 	vars->pn[1]++;
// 	return (1);
// }

void	get_enemies(t_vars *vars, int i, int j, int *n)
{
	vars->setting[i][j] = set_image(vars, "enemy.xpm", i, j);
	vars->enemies[*n].id = *n;
	vars->enemies[*n].x = i;
	vars->enemies[*n].y = j;
}

// void	move_enemy(t_vars *vars)
// {
// 	int	x;
// 	int	y;
// 	int	moved;

// 	moved = 0;
// 	x = 0;
// 	y = 0;
// 	// if (abs(x) >= abs(y) && x >= 0)
// 	// 	moved = move_enemy_down(vars);
// 	// else if (abs(x) >= abs(y))
// 	// 	moved = move_enemy_up(vars);
// 	// if (y >= 0 && moved == 0)
// 	// 	moved = move_enemy_right(vars);
// 	// else if (moved == 0)
// 	// 	moved = move_enemy_left(vars);
// }

int	can_go(t_map *map, t_enemy e, int x, int y)
{
	char	p;

	p = map->data[e.x + x][e.y + y];
	if (p == '0' || p == 'P')
		return (1);
	return (0);
}

void	choose_move_enemy(t_vars *vars, t_enemy e)
{
	int	dx;
	int	dy;

	dx = vars->pp[0] - (e.x);
	dy = vars->pp[1] - (e.y);
	if (abs(dx) >= abs(dy))
	{
		if (dx > 0 && can_go(vars->map, e, 1, 0))
			move_enemy(vars, e, 1, 0);
		else if (dx < 0 && can_go(vars->map, e, -1, 0))
			move_enemy(vars, e, -1, 0);
		else
		{
			if (dy > 0 && can_go(vars->map, e, 0, 1))
				move_enemy(vars, e, 0, 1);
			else if (dy < 0 && can_go(vars->map, e, 0, -1))
				move_enemy(vars, e, 0, -1);
			else if (can_go(vars->map, e, 1, 0))
				move_enemy(vars, e, 1, 0);
			else
				move_enemy(vars, e, 1, 0);
		}
	}
}
