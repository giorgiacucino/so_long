/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:29:15 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/04 16:23:57 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	update_banner(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (64 * vars->map->cols))
	{
		j = -1;
		while (++j < 64)
		{
			if ((i > 5 && i < (64 * vars->map->cols) - 5) && (j > 5 && j < 59))
				my_mlx_pixel_put(vars->banner, i, j, 0x00000000);
			else
				my_mlx_pixel_put(vars->banner, i, j, 0x00FFFFFF);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->banner->img, 0,
		64 * vars->map->rows);
}

void	make_banner(t_vars *vars)
{
	vars->banner->img = mlx_new_image(vars->mlx, 64 * vars->map->cols, 64);
	vars->banner->addr = mlx_get_data_addr(vars->banner->img, &vars->banner->bpp,
		&vars->banner->l_length, &vars->banner->endian);
	update_banner(vars);
	mlx_string_put(vars->mlx, vars->win, 10, (vars->map->rows * 64) + 20, 0x00FF0000, "Jarvis: ");
}