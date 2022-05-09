/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:37:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/09 18:42:30 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->enemies != NULL)
		free(vars->enemies);
	if (vars->map != NULL)
		free_map(vars->map);
	if (vars->banner != NULL)
		free(vars->banner);
	free(vars);
	exit (0);
}

int	action_key(int keycode, t_vars *var)
{	
	if (keycode == 53)
		close_win(var);
	if (var->end == 1)
		return (0);
	if (keycode == 0 || keycode == 123)
		move_player(var, 0, -1);
	else if (keycode == 1 || keycode == 125)
		move_player(var, 1, 0);
	else if (keycode == 2 || keycode == 124)
		move_player(var, 0, 1);
	else if (keycode == 13 || keycode == 126)
		move_player(var, -1, 0);
	else if (keycode == 42)
		end_game(var, 1);
	if (var->n_coll == 0)
		set_image(var, var->imgs->exit, var->pe[0], var->pe[1]);
	return (0);
}

void	load_img(t_vars *vars, t_data *img, char *str)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(vars->mlx,
			str, &img_width, &img_height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->l_length, &img->endian);
}

void	load_imgs(t_vars *vars)
{
	int		i;
	char	*pl;
	char	*en;

	i = 0;
	load_img(vars, &vars->imgs->wall, "sfondo.xpm");
	load_img(vars, &vars->imgs->null, "prova.xpm");
	load_img(vars, &vars->imgs->coll, "coll.xpm");
	load_img(vars, &vars->imgs->exit, "porta.xpm");
	vars->imgs->enemy = (t_data *) malloc (sizeof(t_data) * 4);
	vars->imgs->player = (t_data *) malloc (sizeof(t_data) * 4);
	while (++i < 5)
	{
		pl = ft_strjoin_3("xpms/player/player", i, ".xpm");
		en = ft_strjoin_3("xpms/enemy/enemy", i, ".xpm");
		load_img(vars, &vars->imgs->player[i - 1], pl);
		load_img(vars, &vars->imgs->enemy[i - 1], en);
		free(en);
		free(pl);
	}
}

void	set_image(t_vars *vars, t_data img, int x, int y)
{
	// int		img_width;
	// int		img_height;

	// img.img = mlx_xpm_file_to_image(vars->mlx, file, &img_width, &img_height);
	// img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_length, &img.endian);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, y * 64, x * 64);
}

void	set_background(t_vars *vars)
{
	int		i;
	int		j;
	int		n;

	i = -1;
	n = 0;
	while (++i < vars->map->rows)
	{
		j = -1;
		while (++j < vars->map->cols)
		{
			if (vars->map->data[i][j] == '1')
				set_image(vars, vars->imgs->wall, i, j);
			else
				set_image(vars, vars->imgs->null, i, j);
			if (vars->map->data[i][j] == 'N')
				get_enemies(vars, i, j, &n);
			else if (vars->map->data[i][j] == 'C')
				set_image(vars, vars->imgs->coll, i, j);
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
	if (vars->map == NULL || check_map(vars) == 1)
	{
		free_map(vars->map);
		return (0);
	}
	if (vars->n_en != 0)
		vars->enemies = (t_enemy *) malloc (vars->n_en * (sizeof(t_enemy)));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->map->cols) * 64,
			(vars->map->rows + 1) * 64, "so_long");
	vars->frame = 0;
	vars->moves = 0;
	vars->end = 0;
	vars->imgs = (t_imgs *) malloc (sizeof(t_imgs));
	mlx_hook(vars->win, 2, 0, action_key, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	load_imgs(vars);
	mlx_loop_hook(vars->mlx, update_sprites, vars);
	set_background(vars);
	make_banner(vars);
	mlx_loop(vars->mlx);
	return (0);
}
