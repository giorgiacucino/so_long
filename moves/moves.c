/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:49:16 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/22 16:57:35 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(t_vars *vars)
{
	if (vars->map-> data[vars->pp[0]][vars->pp[1] - 1] == '1')
		return ;
	if (vars->map->data[vars->pp[0]][vars->pp[1] - 1] == 'C')
	{
		set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1] - 1);
		vars->n_coll--;
		vars->blocked = 2;
		set_image(vars, "mud_enemy.xpm", vars->pn[0], vars->pn[1]);
	}
	set_image(vars, "tizio.xpm", vars->pp[0], vars->pp[1] - 1);
	set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1]);
	vars->map->data[vars->pp[0]][vars->pp[1] - 1] = 'P';
	vars->map->data[vars->pp[0]][vars->pp[1]] = '0';
	vars->pp[1]--;
	if (vars->blocked <= 0)
		move_enemy(vars);
	if (vars->blocked == 1)
		set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1]);
	vars->blocked--;
}

void	move_up(t_vars *vars)
{
	if (vars->map-> data[vars->pp[0] - 1][vars->pp[1]] == '1')
		return ;
	if (vars->map->data[vars->pp[0] - 1][vars->pp[1]] == 'C')
	{
		set_image(vars, "prova.xpm", vars->pp[0] - 1, vars->pp[1]);
		vars->n_coll--;
		vars->blocked = 2;
		set_image(vars, "mud_enemy.xpm", vars->pn[0], vars->pn[1]);
	}
	set_image(vars, "tizio.xpm", vars->pp[0] - 1, vars->pp[1]);
	set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1]);
	vars->map->data[vars->pp[0] - 1][vars->pp[1]] = 'P';
	vars->map->data[vars->pp[0]][vars->pp[1]] = '0';
	vars->pp[0]--;
	if (vars->blocked <= 0)
		move_enemy(vars);
	if (vars->blocked == 1)
		set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1]);
	vars->blocked--;
}

void	move_down(t_vars *vars)
{
	if (vars->map-> data[vars->pp[0] + 1][vars->pp[1]] == '1')
		return ;
	if (vars->map->data[vars->pp[0] + 1][vars->pp[1]] == 'C')
	{
		set_image(vars, "prova.xpm", vars->pp[0] + 1, vars->pp[1]);
		vars->n_coll--;
		vars->blocked = 2;
		set_image(vars, "mud_enemy.xpm", vars->pn[0], vars->pn[1]);
	}
	set_image(vars, "tizio.xpm", vars->pp[0] + 1, vars->pp[1]);
	set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1]);
	vars->map->data[vars->pp[0] + 1][vars->pp[1]] = 'P';
	vars->map->data[vars->pp[0]][vars->pp[1]] = '0';
	vars->pp[0]++;
	if (vars->blocked <= 0)
		move_enemy(vars);
	if (vars->blocked == 1)
		set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1]);
	vars->blocked--;
}

void	move_right(t_vars *vars)
{
	int	flag;

	flag = 0;
	if (vars->map-> data[vars->pp[0]][vars->pp[1] + 1] == '1')
		return ;
	if (vars->map->data[vars->pp[0]][vars->pp[1] + 1] == 'C')
	{
		set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1] + 1);
		vars->n_coll--;
		vars->blocked = 2;
		set_image(vars, "mud_enemy.xpm", vars->pn[0], vars->pn[1]);
	}
	set_image(vars, "tizio.xpm", vars->pp[0], vars->pp[1] + 1);
	set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1]);
	vars->map->data[vars->pp[0]][vars->pp[1] + 1] = 'P';
	vars->map->data[vars->pp[0]][vars->pp[1]] = '0';
	vars->pp[1]++;
	if (vars->blocked <= 0)
		move_enemy(vars);
	if (vars->blocked == 1)
		set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1]);
	vars->blocked--;
}
