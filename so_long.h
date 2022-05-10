/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:59:58 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/10 18:30:38 by gcucino          ###   ########.fr       */
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

typedef struct s_enemy
{
	int		id;
	int		x;
	int		y;
}				t_enemy;

typedef struct s_data {
	char	*str_id;
	void	*img;
	char	*addr;
	int		bpp;
	int		l_length;
	int		endian;
}				t_data;

typedef struct s_imgs {
	t_data	wall;
	t_data	null;
	t_data	coll;
	t_data	exit;
	t_data	*player;
	t_data	*enemy;
	t_data	escaping;
	t_data	blocked;
}				t_imgs;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		end;
	int		frame;
	int		moves;
	t_map	*map;
	t_imgs	*imgs;
	int		pp[2];
	int		pe[2];
	int		n_coll;
	int		n_en;
	t_enemy	*enemies;
	int		status_en;
	t_data	*banner;
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
void	set_image(t_vars *vars, t_data img, int x, int y);
void	get_enemies(t_vars *vars, int i, int j, int *n);
void	move_player(t_vars *vars, int x, int y);
void	choose_move_enemy(t_vars *vars, int id);
void	move_enemy(t_vars *vars, int id, int x, int y);
void	set_enemies(t_vars *vars);
void	free_matrix(void **matrix, int rows);
int		close_win(t_vars *vars);
void	end_game(t_vars *vars, int win);
int		update_sprites(t_vars *vars);
void	make_banner(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	update_banner(t_vars *vars, int finish);
void	display_moves(int vars);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin_3(char *s1, int moves, char *s2);
void	set_background(t_vars *vars);

#endif
