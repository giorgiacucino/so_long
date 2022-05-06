/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:49:16 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/06 16:09:51 by gcucino          ###   ########.fr       */
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
		vars->map->data[vars->pp[0] + x][vars->pp[1] + y] = '0';
		vars->n_coll--;
		vars->status_en = 2;
	}
	set_image(vars, "prova.xpm", vars->pp[0], vars->pp[1]);
	vars->map->data[vars->pp[0] + x][vars->pp[1] + y] = 'P';
	vars->map->data[vars->pp[0]][vars->pp[1]] = '0';
	vars->pp[0] += x;
	vars->pp[1] += y;
	vars->moves ++;
	update_banner(vars, 0);
	display_moves(vars->moves);
	if (vars->pp[0] == vars->pe[0] && vars->pp[1] == vars->pe[1]
		&& vars->n_coll == 0)
		end_game(vars, 1);
	else
		set_enemies(vars);
}
