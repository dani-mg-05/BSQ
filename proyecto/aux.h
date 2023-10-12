/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:59:09 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/26 18:17:15 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUX_H
# define AUX_H
# include "bsq.h"

void	print_matrix(char	**matrix);
int		get_map_row_count(char **matrix);
void	free_matrix(char	**matrix);
void	free_s_point_matrix(t_point **matrix, char **mtrix);
int		all_chars_in_map_valid(char	**matrix);
#endif