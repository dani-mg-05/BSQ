/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:30:29 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/25 21:51:51 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "bsq.h"

char	**matrix_generator(char *map);
int		is_valid_map(char *map);
t_map	*s_map_genrtr(t_point	**s_pt_mtrx, char	**mtrx);
t_point	**s_point_matrix_generator(char **mtrx);
#endif