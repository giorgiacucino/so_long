/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcucino <gcucino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:04:32 by gcucino           #+#    #+#             */
/*   Updated: 2022/05/09 18:04:07 by gcucino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

void	display_moves(int moves)
{
	write(1, "Moves: ", 8);
	ft_putnbr(moves);
	write(1, "\n", 1);
}

int	get_size(int n)
{
	int	ret;

	ret = 0;
	if (n <= 0)
	{
		n = -n;
		ret++;
	}
	while (n != 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		size;
	long	i;
	char	*ret;

	i = (long) n;
	size = get_size(n);
	ret = (char *) malloc ((size + 1) * sizeof(char));
	ret[size] = '\0';
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		i = - (long) n;
	}
	while (size--)
	{
		ret[size] = (i % 10) + 48;
		i = i / 10;
	}
	return (ret);
}
