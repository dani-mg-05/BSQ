/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:19:17 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/26 18:27:13 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "aux.h"

char	get_filled_char(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[0][i])
		i++;
	return (matrix[0][i - 1]);
}

char	get_obstacle_char(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[0][i])
		i++;
	return (matrix[0][i - 2]);
}

char	get_empty_char(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[0][i] != '\0')
		i++;
	return (matrix[0][i - 3]);
}

int	is_map_charset_valid(char **matrix)
{
	if (get_filled_char(matrix) == get_obstacle_char(matrix))
	{
		free_matrix(matrix);
		return (0);
	}
	if (get_filled_char(matrix) == get_empty_char(matrix))
	{
		free_matrix(matrix);
		return (0);
	}
	if (get_obstacle_char(matrix) == get_empty_char(matrix))
	{
		free_matrix(matrix);
		return (0);
	}
	return (1);
}

int	all_rows_same_length(char **matrix)
{
	int	row_length;
	int	rows;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[1][i] != '\0')
		i++;
	row_length = i;
	i = 2;
	rows = get_map_row_count(matrix);
	while (i <= rows)
	{
		while (matrix[i][j] != '\0')
			j++;
		if (j != row_length)
			return (0);
		j = 0;
		i++;
	}
	return (row_length);
}
