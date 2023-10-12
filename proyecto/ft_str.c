/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:39:00 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/25 23:40:48 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb *(-1);
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	else
		ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

void	ft_print_s_map(t_map	*s_map)
{
	int	row;
	int	col;

	row = 0;
	while (row < s_map->rows)
	{
		col = 0;
		while (col < s_map->cols)
		{
			ft_putchar(s_map->points[row][col].value);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

int	ft_strlen(char *str)
{
	int	strlen;

	strlen = 0;
	while (*str != 0)
	{
		strlen++;
		str++;
	}
	return (strlen);
}
