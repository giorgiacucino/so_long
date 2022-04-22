/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:59:58 by gcucino           #+#    #+#             */
/*   Updated: 2022/04/22 16:51:48 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <string.h>

typedef struct s_map
{
	char	**data;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	**setting;
	t_map	*map;
	int		pp[2];
	int		pe[2];
	int		pn[2];
	int		n_coll;
	int		blocked;
}				t_vars;

char	*get_buf(int fd);
char	*get_next_line(int fd);
int		ft_strbuf(char **buf, int fd);
int		has_next(char *src);
char	*ft_strndup(char *str, int start, int end);
char	*get_next_token(char **src);
int		ft_strlen(char *s);
int		handler_null(char **buf, int fd);
void	fill_tmp(char *dest, char *s1, char *s2);

void	get_map(char *input, t_vars *vars);
int		check_map(t_vars *v);
void	free_map(t_map *map);
int		get_h_l(char *input, t_map *map);
t_data	set_image(t_vars *vars, char *file, int x, int y);
void	move_up(t_vars *vars);
void	move_right(t_vars *vars);
void	move_left(t_vars *vars);
void	move_down(t_vars *vars);
void	move_enemy(t_vars *vars);

#endif
