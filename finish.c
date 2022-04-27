/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:06:20 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/27 19:12:12 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_enemies(t_vars *vars, char *img)
{
	int	i;

	i = -1;
	while (++i < vars->n_en)
	{
		set_image(vars, img, vars->enemies[i].x, vars->enemies[i].y);
	}
}

int	update_sprites(t_vars *vars)
{
	vars->frame++;
	if (vars->frame < 50)
	{
		set_image(vars, "xpms/player/player1.xpm", vars->pp[0], vars->pp[1]);
		update_enemies(vars, "xpms/enemy/enemy1.xpm");
	}
	else if (vars->frame < 100)
	{
		set_image(vars, "xpms/player/player2.xpm", vars->pp[0], vars->pp[1]);
		update_enemies(vars, "xpms/enemy/enemy2.xpm");
	}
	else if (vars->frame < 150)
	{
		set_image(vars, "xpms/player/player3.xpm", vars->pp[0], vars->pp[1]);
		update_enemies(vars, "xpms/enemy/enemy3.xpm");
	}
	else if (vars->frame < 200)
	{
		set_image(vars, "xpms/player/player4.xpm", vars->pp[0], vars->pp[1]);
		update_enemies(vars, "xpms/enemy/enemy4.xpm");
	}
	if (vars->frame == 200)
		vars->frame = 0;
	return (0);
}

void	set_black(t_vars *vars)
{
	int		i;
	int		j;

	i = -1;
	while (++i < vars->map->rows)
	{
		j = -1;
		while (++j < vars->map->cols)
		{
			vars->setting[i][j] = set_image(vars, "sfondo.xpm", i, j);
		}
	}
}

void	you_won(t_vars *vars)
{
	printf("hai vinto!\n");
	set_black(vars);
	close_win(vars);
}

void	you_lost(t_vars *vars)
{
	printf("hai perso!\n");
	set_black(vars);
	close_win(vars);
}
