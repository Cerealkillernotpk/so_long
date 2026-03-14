/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:08:47 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/14 18:36:06 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill_checker(char **copy, t_vec *coord)
{
	if (go_to(coord, copy, 'E') && go_to(coord, copy, 'C'))
		return (0);
	return(1);
}

int	check_line(char **map, int line, t_vec coord)
{
	int	len;
	
	len = (int)ft_strlen(map[0]);
	while (coord.x != line && coord.y != len)
	{
		while(coord.y != len)
		{
			if (coord.x != 0 && coord.x != line)
				if (map[coord.x][0] != 1 && map[coord.x][len] != 1)
					return (0);
			else
				if (map[coord.x][coord.y] != 1)
					return (0);
			coord.y++;
		}
		if (coord.x == line && coord.y == len)
			break;
		coord.y = 0;
		coord.x++;
	}
	return (1);
}

int		map_border_checker(char **map, int line)
{
	t_vec coord;

	coord.x = 0;
	coord.y = 0;
	while (coord.x != line)
	{
		if (ft_strlen(map[coord.x] != ft_strlen(map[0])))
			return (0);
		coord.x++;
	}
	if (check_line(map, line, coord) == 0)
		return (0);
}