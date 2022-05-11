/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:56:33 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/11 17:41:21 by gcucino          ###   ########.fr       */
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

void	choose_move_enemy_2(t_vars *vars, int id, int *dif)
{
	if (dif[0] >= 0 && can_go(vars, id, dif[2], dif[3]))
		move_enemy(vars, id, dif[2], dif[3]);
	else if (dif[0] <= 0 && can_go(vars, id, -dif[2], -dif[3]))
		move_enemy(vars, id, -dif[2], -dif[3]);
	else
	{
		if (dif[1] > 0 && can_go(vars, id, dif[3], dif[2]))
			move_enemy(vars, id, dif[3], dif[2]);
		else if (dif[1] < 0 && can_go(vars, id, -dif[3], -dif[2]))
			move_enemy(vars, id, -dif[3], -dif[2]);
		else if (can_go(vars, id, dif[2], dif[3]))
			move_enemy(vars, id, dif[2], dif[3]);
		else if (can_go(vars, id, -dif[2], -dif[3]))
			move_enemy(vars, id, -dif[2], -dif[3]);
		else if (can_go(vars, id, -dif[3], -dif[2]))
			move_enemy(vars, id, -dif[3], -dif[2]);
		else if (can_go(vars, id, dif[3], dif[2]))
			move_enemy(vars, id, dif[3], dif[2]);
	}
}

void	choose_move_enemy(t_vars *vars, int id)
{
	int	dx;
	int	dy;
	int	*dif;

	dx = vars->pp[0] - (vars->enemies[id].x);
	dy = vars->pp[1] - (vars->enemies[id].y);
	dif = (int *) malloc (sizeof(int) * 4);
	if (abs(dx) >= abs(dy))
	{
		dif[0] = dx;
		dif[1] = dy;
		dif[2] = 1;
		dif[3] = 0;
	}
	else
	{
		dif[0] = dy;
		dif[1] = dx;
		dif[2] = 0;
		dif[3] = 1;
	}
	choose_move_enemy_2(vars, id, dif);
	free(dif);
}
