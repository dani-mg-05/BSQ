/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:58:48 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/26 12:59:26 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_H
# define SEARCH_H
# include "bsq.h"

int		found_sqr_in_map(t_map *s_map, t_point *starting_s_pt, int sq_size);
void	full_map_search(t_map *s_map);
t_point	*get_pt_wth_max_sqr_in_map(t_map *s_map);
void	fill_map_with_empty_chars(t_point *starting_s_pt, t_map	*s_map);

#endif