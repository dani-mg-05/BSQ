/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igcastil <igcastil@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:55:36 by igcastil          #+#    #+#             */
/*   Updated: 2023/07/25 21:58:31 by igcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_HEADER_H
# define PARSE_MAP_HEADER_H

char	get_filled_char(char **matrix);
char	get_obstacle_char(char **matrix);
char	get_empty_char(char **matrix);
int		is_map_charset_valid(char **matrix);
int		all_rows_same_length(char **matrix);

#endif