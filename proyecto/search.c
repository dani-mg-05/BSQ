/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 23:52:03 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/26 13:28:17 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft_str.h"

/* busca en el mapa s_map desde el pto starting_s_pt,
hacia abajo y hacia la izquierda, un cuadrado de lado
sq_size . ret 1 si found. ret 0 not found*/
int	found_sqr_in_map(t_map *s_map, t_point *starting_s_pt, int sq_size)
{
	int	row;
	int	col;

	row = starting_s_pt->row;
	while (starting_s_pt->row + sq_size <= s_map->rows
		&& (row < starting_s_pt->row + sq_size))
	{
		col = starting_s_pt->col;
		while ((starting_s_pt->col + sq_size <= s_map->cols)
			&& (col < starting_s_pt->col + sq_size))
		{
			if (s_map->points[row][col].value == s_map->obstacle_char)
				return (0);
			col++;
		}
		row++;
	}
	starting_s_pt->max_square_found = sq_size;
	return (1);
}

void	full_map_search(t_map *s_map)
{
	int	row;
	int	col;
	int	sq_size;

	sq_size = 1;
	row = 0;
	while (row + sq_size <= s_map->rows)
	{
		col = 0;
		while (col + sq_size <= s_map->cols)
		{
			while (found_sqr_in_map (s_map,
					&(s_map->points[row][col]), sq_size))
			{
				sq_size++;
			}
			col++;
		}
		row++;
	}
}

t_point	*get_pt_wth_max_sqr_in_map(t_map *s_map)
{
	int		row;
	int		col;
	int		max_sq_size;
	t_point	*pt_wth_max_sqr;

	max_sq_size = 0;
	row = 0;
	while (row < s_map->rows)
	{
		col = 0;
		while (col < s_map->cols)
		{
			if (s_map->points[row][col].max_square_found > max_sq_size)
			{
				max_sq_size = s_map->points[row][col].max_square_found;
				pt_wth_max_sqr = &(s_map->points[row][col]);
			}
			col++;
		}
		row++;
	}
	return (pt_wth_max_sqr);
}

void	fill_map_with_empty_chars(t_point *starting_s_pt, t_map *s_map)
{
	int	row;
	int	col;
	int	max_sq_size;

	row = starting_s_pt->row;
	max_sq_size = starting_s_pt->max_square_found;
	while (row < (starting_s_pt->row + max_sq_size))
	{
		col = starting_s_pt->col;
		while (col < (starting_s_pt->col + max_sq_size))
		{
			s_map->points[row][col].value = s_map->filled_char;
			col++;
		}
		row++;
	}
}
