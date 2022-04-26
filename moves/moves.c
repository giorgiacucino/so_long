/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:49:16 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/26 14:55:19 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_vars *vars, int x, int y)
{
	if (vars->map-> data[vars->pp[0] + x][vars->pp[1] + y] == '1')
		return ;
	if (vars->map->data[vars->pp[0] + x][vars->pp[1] + y] == 'C')
	{
		set_image(vars, "prova.xpm", vars->pp[0] + x, vars->pp[1] + y);
		vars->n_coll--;
		//vars->blocked = 2;
		//set_image(vars, "mud_enemy.xpm", vars->pn[0], vars->pn[1]);
	}
	set_image(vars, "tizio.xpm", vars->pp[0] + x, vars->pp[1] + y);
	set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1]);
	vars->map->data[vars->pp[0] + x][vars->pp[1] + y] = 'P';
	vars->map->data[vars->pp[0]][vars->pp[1]] = '0';
	vars->pp[0] += x;
	vars->pp[1] += y;
	choose_move_enemy(vars, vars->enemies[0]);
	//if (vars->blocked <= 0)
	//	move_enemy(vars);
	//if (vars->blocked == 1)
	//	set_image(vars, "enemy.xpm", vars->pn[0], vars->pn[1]);
	//vars->blocked--;
}
