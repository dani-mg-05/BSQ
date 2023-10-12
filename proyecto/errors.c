/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:54:20 by damedina          #+#    #+#             */
/*   Updated: 2023/07/26 18:30:40 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "parse_map_header.h"
#include "ft_str.h"
#include "aux.h"

char	**matrix_generator(char *map_filename)
{
	int		i;
	int		fd;
	char	count;
	char	*buf;
	char	**matrix;

	i = 0;
	fd = open(map_filename, O_RDONLY);
	while (read(fd, &count, sizeof(count)) != 0)
		i++;
	close(fd);
	buf = (char *)malloc((i + 1) * sizeof(char));
	fd = open(map_filename, O_RDONLY);
	read(fd, buf, i);
	buf[i] = '\0';
	matrix = ft_split(buf, "\n");
	free(buf);
	close(fd);
	return (matrix);
}

int	is_valid_map(char *map_filename)
{
	int		i;
	char	**matrix;

	matrix = matrix_generator(map_filename);
	i = 0;
	while (matrix[i][0] != '\0' && matrix[i + 1][0] != '\0')
		i++;
	if (i != get_map_row_count(matrix))
	{
		free_matrix(matrix);
		return (0);
	}
	if (!is_map_charset_valid(matrix))
	{
		free_matrix(matrix);
		return (0);
	}
	if (!all_rows_same_length(matrix))
	{
		free_matrix(matrix);
		return (0);
	}
	free_matrix(matrix);
	return (1);
}

t_map	*s_map_genrtr(t_point	**s_pt_mtrx, char **mtrx)
{
	t_map	*s_map;

	s_map = (t_map *) malloc(sizeof(t_map));
	if (!s_map)
	{
		free(s_map);
		return (0);
	}
	s_map->rows = get_map_row_count(mtrx);
	s_map->cols = all_rows_same_length(mtrx);
	s_map->empty_char = get_empty_char(mtrx);
	s_map->obstacle_char = get_obstacle_char(mtrx);
	s_map->filled_char = get_filled_char(mtrx);
	s_map->max_square = 0;
	s_map->points_count = s_map->rows * s_map->cols;
	s_map->points = s_pt_mtrx;
	return (s_map);
}

t_point	**fill_s_point_matrix(t_point **s_pt_mtrix, char **mtrx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < get_map_row_count(mtrx))
	{
		j = -1;
		while (++j < all_rows_same_length(mtrx))
		{
			s_pt_mtrix[i][j].row = i;
			s_pt_mtrix[i][j].col = j;
			s_pt_mtrix[i][j].value = mtrx[i + 1][j];
			s_pt_mtrix[i][j].max_square_found = 0;
		}
	}
	return (s_pt_mtrix);
}

t_point	**s_point_matrix_generator(char **mtrx)
{
	t_point	**s_pt_mtrix;
	int		i;

	i = 0;
	s_pt_mtrix = (t_point **)malloc(get_map_row_count(mtrx)
			* sizeof(t_point *));
	if (!s_pt_mtrix)
	{
		free(s_pt_mtrix);
		return (0);
	}
	while (i < get_map_row_count(mtrx))
	{
		s_pt_mtrix[i] = (t_point *) malloc(all_rows_same_length(mtrx)
				* sizeof(t_point));
		if (!s_pt_mtrix[i++])
		{
			free_s_point_matrix(s_pt_mtrix, mtrx);
			return (0);
		}
	}	
	return (fill_s_point_matrix(s_pt_mtrix, mtrx));
}
