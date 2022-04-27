/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:49:16 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/27 16:20:28 by gcucino          ###   ########.fr       */
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
	if (vars->pp[0] == vars->pe[0] && vars->pp[1] == vars->pe[1])
		you_won(vars);
	set_enemies(vars);
}
