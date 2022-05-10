/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:56:33 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/10 18:29:39 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemy(t_vars *vars, int id, int x, int y)
{
	set_image(vars, vars->imgs->null, vars->enemies[id].x, vars->enemies[id].y);
	vars->map->data[vars->enemies[id].x + x][vars->enemies[id].y + y] = 'N';
	vars->map->data[vars->enemies[id].x][vars->enemies[id].y] = '0';
	vars->enemies[id].x += x;
	vars->enemies[id].y += y;
	if (vars->enemies[id].x == vars->pp[0]
		&& vars->enemies[id].y == vars->pp[1])
		end_game(vars, 0);
}

void	set_enemies(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->status_en != 0)
		vars->status_en--;
	while (++i < vars->n_en)
	{
		if (vars->enemies[i].x == vars->pp[0]
			&& vars->enemies[i].y == vars->pp[1])
			end_game(vars, 0);
		else if (vars->status_en == 0)
			choose_move_enemy(vars, i);
	}
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
	if (abs(dx) >= abs(dy))
	{
		if (dx >= 0 && can_go(vars, id, 1, 0))
			move_enemy(vars, id, 1, 0);
		else if (dx <= 0 && can_go(vars, id, -1, 0))
			move_enemy(vars, id, -1, 0);
		else
		{
			if (dy > 0 && can_go(vars, id, 0, 1))
				move_enemy(vars, id, 0, 1);
			else if (dy < 0 && can_go(vars, id, 0, -1))
				move_enemy(vars, id, 0, -1);
			else if (can_go(vars, id, 1, 0))
				move_enemy(vars, id, 1, 0);
			else if (can_go(vars, id, -1, 0))
				move_enemy(vars, id, -1, 0);
			else if (can_go(vars, id, 0, -1))
				move_enemy(vars, id, 0, -1);
			else if (can_go(vars, id, 0, 1))
				move_enemy(vars, id, 0, 1);
		}
	}
	else
	{
		if (dy >= 0 && can_go(vars, id, 0, 1))
			move_enemy(vars, id, 0, 1);
		else if (dy <= 0 && can_go(vars, id, 0, -1))
			move_enemy(vars, id, 0, -1);
		else
		{
			if (dx > 0 && can_go(vars, id, 1, 0))
				move_enemy(vars, id, 1, 0);
			else if (dx < 0 && can_go(vars, id, -1, 0))
				move_enemy(vars, id, -1, 0);
			else if (can_go(vars, id, 0, -1))
				move_enemy(vars, id, 0, -1);
			else if (can_go(vars, id, 0, 1))
				move_enemy(vars, id, 0, 1);
			else if (can_go(vars, id, 1, 0))
				move_enemy(vars, id, 1, 0);
			else if (can_go(vars, id, -1, 0))
				move_enemy(vars, id, -1, 0);
		}
	}
}
