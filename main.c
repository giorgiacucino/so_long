/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:04:15 by gcucino           #+#    #+#             */
/*   Updated: 2022/03/24 19:04:15 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		height;
	char	**map;

	height = 0;
	i = 0;
	if (argc != 2)
		return(0);
	fd = open(argv[1], O_RDONLY);
    while (1)
		height++;
	close(fd);
	map = (char **) malloc (sizeof(char*) * height);
	fd = open(argv[1], O_RDONLY);
	while(i < height)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	i = 0;
	while (i < height)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}