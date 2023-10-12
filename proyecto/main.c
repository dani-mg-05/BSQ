/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:30:28 by damedina          #+#    #+#             */
/*   Updated: 2023/07/26 18:34:49 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "aux.h"
#include "errors.h"
#include "ft_str.h"
#include "parse_map_header.h"
#include "search.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	**matrix;
	t_map	*s_map;
	t_point	**s_points;

	i = 0;
	while (++i < argc)
	{
		if (!is_valid_map(argv[i]))
			ft_putstr("map error\n");
		else
		{
			matrix = matrix_generator(argv[i]);
			s_points = s_point_matrix_generator(matrix);
			s_map = s_map_genrtr(s_points, matrix);
			full_map_search (s_map);
			fill_map_with_empty_chars(get_pt_wth_max_sqr_in_map(s_map), s_map);
			ft_print_s_map(s_map);
			ft_putchar('\n');
			free(s_map);
			free_s_point_matrix(s_points, matrix);
			free_matrix(matrix);
		}
	}
	return (0);
}
