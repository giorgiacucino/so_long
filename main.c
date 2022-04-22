/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:37:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/22 16:05:14 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

int	action_key(int keycode, t_vars *var)
{
	int	i;

	if (keycode == 0)
		move_left(var);
	else if (keycode == 1)
		move_down(var);
	else if (keycode == 2)
		move_right(var);
	else if (keycode == 13)
		move_up(var);
	if (keycode == 53 || (var->pp[0] == var->pe[0] && var->pp[1] == var->pe[1]))
		close_win(var);
	if (var->n_coll == 0)
		var->setting[var->pe[0]][var->pe[1]] = set_image(var, "porta.xpm", var->pe[0], var->pe[1]);
	i = -1;
	while (++i < var->map->rows)
		printf("%s", var->map->data[i]);
	printf("\n");
	return (0);
}

t_data	set_image(t_vars *vars, char *file, int x, int y)
{
	t_data	img;
	int		img_width;
	int		img_height;

	img.img = mlx_xpm_file_to_image(vars->mlx, file, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, y * 64, x * 64);
	return (img);
}

void	set_background(t_vars *vars)
{
	int		i;
	int		j;

	i = -1;
	vars->setting = (t_data **) malloc (sizeof(t_data *) * vars->map->rows);
	while (++i < vars->map->rows)
	{
		vars->setting[i] = (t_data *) malloc (sizeof(t_data) * vars->map->cols);
		j = -1;
		while (++j < vars->map->cols)
		{
			if (vars->map->data[i][j] == '1')
				vars->setting[i][j] = set_image(vars, "sfondo.xpm", i, j);
			else
				vars->setting[i][j] = set_image(vars, "prova.xpm", i, j);
			if (vars->map->data[i][j] == 'P')
				vars->setting[i][j] = set_image(vars, "tizio.xpm", i, j);
			else if (vars->map->data[i][j] == 'N')
				vars->setting[i][j] = set_image(vars, "enemy.xpm", i, j);
			else if (vars->map->data[i][j] == 'C')
				vars->setting[i][j] = set_image(vars, "coll.xpm", i, j);
		}
	}
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		return (0);
	vars = (t_vars *) malloc (sizeof(t_vars));
	get_map(argv[1], vars);
	if (vars->map == NULL)
		return (0);
	if (check_map(vars) == 1)
	{
		free_map(vars->map);
		return (0);
	}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->map->cols) * 64,
			(vars->map->rows) * 64, "so_long");
	mlx_hook(vars->win, 2, 0, action_key, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	set_background(vars);
	mlx_loop(vars->mlx);
	return (0);
}
