/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:40:12 by damedina          #+#    #+#             */
/*   Updated: 2023/07/26 13:25:39 by damedina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_point
{
	int		row;
	int		col;
	char	value;
	int		max_square_found;
}	t_point;

typedef struct s_map
{
	int				rows;
	int				cols;
	char			filled_char;
	char			obstacle_char;
	char			empty_char;
	int				max_square;
	int				points_count;
	t_point			**points;
}	t_map;

void	ft_putstr(char *str);
char	**ft_split(char *str, char *charset);
int		is_valid_map(char	*map);

#endif
