/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:22:54 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/11 14:42:39 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_vars *vars, t_data *img, char *str)
{
	int		img_width;
	int		img_height;

	img->img = mlx_xpm_file_to_image(vars->mlx,
			str, &img_width, &img_height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->l_length, &img->endian);
}

void	load_imgs(t_vars *vars)
{
	int		i;
	char	*pl;
	char	*en;

	i = 0;
	load_img(vars, &vars->imgs->wall, "xpms/wall.xpm");
	load_img(vars, &vars->imgs->null, "xpms/null.xpm");
	load_img(vars, &vars->imgs->coll, "xpms/coll.xpm");
	load_img(vars, &vars->imgs->exit, "xpms/porta.xpm");
	load_img(vars, &vars->imgs->escaping, "xpms/enemy_escaping.xpm");
	load_img(vars, &vars->imgs->blocked, "xpms/enemy_blocked.xpm");
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
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, y * 64, x * 64);
}

void	get_enemies(t_vars *vars, int i, int j, int *n)
{
	vars->enemies[*n].id = *n;
	vars->enemies[*n].x = i;
	vars->enemies[*n].y = j;
	(*n)++;
}

void	set_background(t_vars *vars)
{
	int		i;
	int		j;
	int		n;

	i = -1;
	n = 0;
	load_imgs(vars);
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
	make_banner(vars);
}
