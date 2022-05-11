/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:11:29 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/11 15:26:38 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_buf(int fd)
{
	char	*buf;
	int		r;
	int		b_read;

	b_read = 0;
	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	while (b_read < BUFFER_SIZE)
	{
		r = read(fd, buf + b_read, BUFFER_SIZE - b_read);
		if (r == -1 || (r == 0 && b_read == 0))
		{
			free(buf);
			return (NULL);
		}
		else if (r == 0)
			break ;
		b_read += r;
	}
	buf[b_read] = '\0';
	return (buf);
}

char	*ft_strndup(char *str, int start, int end)
{
	char	*p;
	int		i;
	int		size;

	i = 0;
	size = end - start;
	if (size == 0)
		return (NULL);
	p = (char *) malloc ((size + 1) * sizeof(char));
	if (p == 0)
		return (NULL);
	while (i < size)
	{
		p[i] = str[i + start];
		i++;
	}
	p[i] = 0;
	return (p);
}

int	ft_strbuf(char **buf, int fd)
{
	char	*tmp;
	char	*tmp2;

	if (buf[fd] == NULL)
		return (handler_null(buf, fd));
	tmp = get_buf(fd);
	if (tmp == NULL)
		return (-1);
	tmp2 = (char *) malloc ((ft_strlen(buf[fd]) + ft_strlen(tmp) + 1)
			* sizeof(char));
	if (tmp2 == NULL)
		return (-1);
	fill_tmp(tmp2, buf[fd], tmp);
	free(tmp);
	free(buf[fd]);
	buf[fd] = ft_strndup(tmp2, 0, ft_strlen(tmp2));
	free(tmp2);
	return (1);
}

char	*get_next_token(char **src)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	while ((*src)[i] != '\0' && (*src)[i] != '\n')
		i++;
	if ((*src)[i] == '\0')
	{
		ret = ft_strndup(*src, 0, ft_strlen(*src));
		free(*src);
		*src = NULL;
		return (ret);
	}
	ret = ft_strndup(*src, 0, i + 1);
	tmp = ft_strndup(*src, i + 1, ft_strlen(*src));
	free(*src);
	if (tmp == NULL)
		*src = NULL;
	else
	{
		*src = ft_strndup(tmp, 0, ft_strlen(tmp));
		free(tmp);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*ret;
	static	char	*(buf[1024]);
	int				flag;

	flag = 1;
	if (fd < 0 || fd > 1023)
		return (NULL);
	if (buf[fd] == NULL)
		buf[fd] = get_buf(fd);
	if (buf[fd] == NULL)
		return (NULL);
	while (has_next(buf[fd]) == 0 && flag == 1)
		flag = ft_strbuf(buf, fd);
	ret = get_next_token(&buf[fd]);
	return (ret);
}
