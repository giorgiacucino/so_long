/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:04:02 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/11 17:32:25 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map == NULL)
		return ;
	if (map->data != NULL)
	{
		while (++i < map->rows)
			free(map->data[i]);
		free(map->data);
	}
	free(map);
}

int	check_map2(t_vars *v, int i, int j, int check[2])
{
	char	cell;

	cell = v->map->data[i][j];
	if (cell == 'P')
	{
		v->pp[0] = i;
		v->pp[1] = j;
		check[0]++;
	}
	else if (cell == 'E')
	{
		v->pe[0] = i;
		v->pe[1] = j;
		check[1]++;
	}
	else if (cell == 'N')
		v->n_en++;
	else if (cell == 'C')
		v->n_coll++;
	else if (cell != '1' && cell != '0')
		return (1);
	return (0);
}

int	check_map(t_vars *v)
{
	int	i;
	int	j;
	int	check[2];

	i = -1;
	ft_bzero(check, 2 * sizeof(int));
	while (++i < v->map->rows)
	{
		j = -1;
		while (++j < v->map->cols)
		{
			if ((i == 0 || i == v->map->rows - 1) && v->map->data[i][j] != '1')
				return (1);
			if ((j == 0 || j == v->map->cols - 1) && v->map->data[i][j] != '1')
				return (1);
			if (check_map2(v, i, j, check) == 1)
				return (2);
		}
	}
	if (check[0] != 1)
		return (3);
	if (check[1] != 1)
		return (4);
	return (0);
}

int	get_h_l(char *input, t_map *map)
{
	int		fd;
	char	*tmp;

	fd = open(input, O_RDONLY);
	tmp = get_next_line(fd);
	while (!(!tmp))
	{
		if (map->cols == 0)
			map->cols = (int)ft_strlen(tmp);
		if (map->cols != (int)ft_strlen(tmp))
			return (1);
		map->rows++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	map->cols--;
	close(fd);
	if (map->rows <= 0 || map->cols <= 0)
		return (1);
	return (0);
}

void	get_map(char *input, t_vars *vars)
{
	int		fd;
	int		i;

	vars->map = (t_map *) malloc (sizeof(t_map));
	if (vars->map == NULL)
		return ;
	if (get_h_l(input, vars->map) != 0)
	{
		free(vars->map);
		vars->map = NULL;
		return ;
	}
	vars->map->data = (char **) malloc (sizeof(char *) * vars->map->rows);
	if (vars->map->data == NULL)
		return ;
	fd = open(input, O_RDONLY);
	i = -1;
	while (++i < vars->map->rows)
		vars->map->data[i] = get_next_line(fd);
	close(fd);
}
