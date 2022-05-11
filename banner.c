/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   banner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:29:15 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/11 18:43:03 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

char	*ft_strjoin_3(char *s1, int moves, char *s2)
{
	char	*ret;
	char	*tmp;

	ret = ft_itoa(moves);
	tmp = ft_strjoin(s1, ret);
	free(ret);
	ret = ft_strjoin(tmp, s2);
	free(tmp);
	return (ret);
}

void	write_moves(t_vars *v)
{
	char	*spkr;
	char	*spch;

	spkr = "Jarvis: ";
	if (v->moves == 0)
		spch = "Mr. Stark, you've made no moves yet.";
	else if (v->moves == 1)
		spch = "Mr. Stark, you've made 1 move.";
	else
		spch = ft_strjoin_3("Mr. Stark, you've made ", v->moves, " moves.");
	mlx_string_put(v->mlx, v->win, 10, (v->map->rows * 64) + 20,
		0x00FF0000, spkr);
	mlx_string_put(v->mlx, v->win, 10, (v->map->rows * 64) + 35,
		0x00FFFFFF, spch);
	if (v->moves > 1)
		free(spch);
	if (v->status_en > 1)
	{
		if (v->status_en == 2)
			spkr = "He destroyed the drone!";
		else
			spkr = "The Stark drone is attacking him!";
		mlx_string_put(v->mlx, v->win, 10, (v->map->rows * 64) + 50,
			0x00FFFFFF, spkr);
	}
}

void	update_banner(t_vars *vars, int finish)
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
	if (finish == 0)
		write_moves(vars);
}

void	make_banner(t_vars *v)
{
	v->banner = (t_data *) malloc (sizeof(t_data));
	v->banner->img = mlx_new_image(v->mlx, 64 * v->map->cols, 128);
	v->banner->addr = mlx_get_data_addr(v->banner->img, &v->banner->bpp,
			&v->banner->l_length, &v->banner->endian);
	update_banner(v, 0);
	if (v->n_en > 1)
		mlx_string_put(v->mlx, v->win, 10, (v->map->rows * 64) + 50,
			0x00FFFFFF, "Thanos used his power to duplicate himself.");
}
