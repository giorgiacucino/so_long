/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:37:31 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/11 18:43:18 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->imgs->player != NULL)
		free(vars->imgs->player);
	if (vars->imgs->enemy != NULL)
		free(vars->imgs->enemy);
	if (vars->imgs != NULL)
		free(vars->imgs);
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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		*p = '\0';
		p++;
		i++;
	}
}

void	error_map(t_vars *vars, int flag)
{
	write(1, "Error\n", 7);
	if (vars->map != NULL)
	{
		if (flag == 1)
			write(1, "There is a char different from 1 on the border\n", 48);
		if (flag == 2)
			write(1, "There is a char different from the standard ones\n", 50);
		if (flag == 3)
			write(1, "There is more than 1 player\n", 29);
		if (flag == 4)
			write(1, "There is more than 1 exit\n", 27);
		free(vars->map);
	}
	else
		write(1, "Error in the allocation of the map\n", 36);
	free(vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		return (0);
	vars = (t_vars *) malloc (sizeof(t_vars));
	ft_bzero(vars, sizeof(vars));
	get_map(argv[1], vars);
	if (vars->map == NULL || check_map(vars) != 0)
	{
		error_map(vars, check_map(vars));
		return (0);
	}
	if (vars->n_en != 0)
		vars->enemies = (t_enemy *) malloc (vars->n_en * (sizeof(t_enemy)));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, (vars->map->cols) * 64,
			(vars->map->rows + 1) * 64, "so_long");
	vars->imgs = (t_imgs *) malloc (sizeof(t_imgs));
	mlx_hook(vars->win, 2, 0, action_key, vars);
	mlx_hook(vars->win, 17, 0, close_win, vars);
	mlx_loop_hook(vars->mlx, update_sprites, vars);
	set_background(vars);
	mlx_loop(vars->mlx);
	return (0);
}
