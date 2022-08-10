/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanekim <hanekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 02:36:38 by hanekim           #+#    #+#             */
/*   Updated: 2022/06/09 01:48:52 by hanekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map_info {
	int		row;
	int		col;
	char	empty;
	char	obstacle;
	char	full;
}	t_map_info;

#endif