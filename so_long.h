/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:59:58 by gcucino           #+#    #+#             */
/*   Updated: 2022/03/24 18:59:58 by gcucino          ###   ########.fr       */
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
# include <string.h>

char	*get_buf(int fd);
char	*get_next_line(int fd);
int		ft_strbuf(char **buf, int fd);
int		has_next(char *src);
char	*ft_strndup(char *str, int start, int end);
char	*get_next_token(char **src);
int		ft_strlen(char *s);
int		handler_null(char **buf, int fd);
void	fill_tmp(char *dest, char *s1, char *s2);

#endif