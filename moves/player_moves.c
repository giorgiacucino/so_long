/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:56:33 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/22 17:14:09 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_enemy_left(t_vars *vars)
{
	if (vars->map->data[vars->pn[0]][vars->pn[1] - 1] == '1')
		return (0);
	set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1] - 1);
	set_image(vars, "prova.xpm", vars->pn[0], vars->pn[1]);
	vars->map->data[vars->pn[0]][vars->pn[1] - 1] = 'N';
	vars->map->data[vars->pn[0]][vars->pn[1]] = '0';
	vars->pn[1]--;
	return (1);
}

int	move_enemy_up(t_vars *vars)
{
	if (vars->map->data[vars->pn[0] - 1][vars->pn[1]] == '1')
		return (0);
	set_image(vars, "enemy.xpm", vars->pn[0] - 1, vars->pn[1]);
	set_image(vars, "prova.xpm", vars->pn[0], vars->pn[1]);
	vars->map->data[vars->pn[0] - 1][vars->pn[1]] = 'N';
	vars->map->data[vars->pn[0]][vars->pn[1]] = '0';
	vars->pn[0]--;
	return (1);
}

int	move_enemy_down(t_vars *vars)
{
	if (vars->map->data[vars->pn[0] + 1][vars->pn[1]] == '1')
		return (0);
	set_image(vars, "enemy.xpm", vars->pn[0] + 1, vars->pn[1]);
	set_image(vars, "prova.xpm", vars->pn[0], vars->pn[1]);
	vars->map->data[vars->pn[0] + 1][vars->pn[1]] = 'N';
	vars->map->data[vars->pn[0]][vars->pn[1]] = '0';
	vars->pn[0]++;
	return (1);
}

int	move_enemy_right(t_vars *vars)
{
	if (vars->map->data[vars->pn[0]][vars->pn[1] + 1] == '1')
		return (0);
	set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1] + 1);
	set_image(vars, "prova.xpm", vars->pn[0], vars->pn[1]);
	vars->map->data[vars->pn[0]][vars->pn[1] + 1] = 'N';
	vars->map->data[vars->pn[0]][vars->pn[1]] = '0';
	vars->pn[1]++;
	return (1);
}

void	move_enemy(t_vars *vars)
{
	int	x;
	int	y;
	int	moved;

	x = vars->pp[0] - vars->pn[0];
	y = vars->pp[1] - vars->pn[1];
	moved = 0;
	if (abs(x) >= abs(y) && x >= 0)
		moved = move_enemy_down(vars);
	else if (abs(x) >= abs(y))
		moved = move_enemy_up(vars);
	if (y >= 0 && moved == 0)
		moved = move_enemy_right(vars);
	else if (moved == 0)
		moved = move_enemy_left(vars);
}
