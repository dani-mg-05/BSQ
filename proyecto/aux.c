/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:53:06 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/26 18:24:28 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "parse_map_header.h"

void	print_matrix(char	**matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_putstr(matrix[i++]);
		ft_putstr("\n");
	}
}

int	get_map_row_count(char **matrix)
{
	int	i;
	int	row_count;

	i = 0;
	row_count = 0;
	while (i < (ft_strlen(matrix[0]) - 3)
		&& (matrix[0][i] >= '0' && matrix[0][i] <= '9'))
		row_count = (row_count * 10) + matrix[0][i++] - '0';
	return (row_count);
}

void	free_matrix(char	**matrix)
{
	int	i;

	i = 0;
	while (i < get_map_row_count(matrix) + 1)
	{
		free(matrix[i]);
		i++;
	}		
	free (matrix);
}

void	free_s_point_matrix(t_point **matrix, char	**mtrix)
{
	int	i;

	i = 0;
	while (i < get_map_row_count(mtrix))
	{
		free(matrix[i]);
		i++;
	}		
	free (matrix);
}

int	all_chars_in_map_valid(char	**matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != get_filled_char(matrix) && matrix[i][j] !=
				get_empty_char(matrix) && matrix[i][j] !=
					get_obstacle_char(matrix))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
