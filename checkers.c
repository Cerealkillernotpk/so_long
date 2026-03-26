/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:08:47 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/26 17:35:53 by adakhama         ###   ########.fr       */
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
	while (coord.x < line)
	{
		while(coord.y <= len)
		{
			if ((coord.x > 0 && coord.x < line - 1))
			{
				if (map[coord.x][0] != '1' && map[coord.x][len] != '1')
					return (0);
			}
			else if (!(map[coord.x][coord.y] == '\n' || 
				map[coord.x][coord.y] == '1'|| map[coord.x][coord.y] == '\0'))
				return (0);
			coord.y++;
		}
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
	while (map[coord.x][line] != '\0')
	{
		if (ft_strlen(map[coord.x]) != ft_strlen(map[0]))
			return (0);
		coord.x++;
	}
	coord.x = 0;
	if (check_line(map, line, coord) == 0)
		return (0);
	return (1);
}

int	check_map(char	**map, int line)
{
	t_vec coord;
	int	len;
	int	bn;
	
	len = (int)ft_strlen(map[0]);
	coord.x = 0;
	coord.y = 0;
	bn = 0;
	if (map_border_checker(map, line) == 0)
		return(0);
	while(coord.x < line)
	{
		bn = 0;
		coord.y = 0;
		while(coord.y != len)
		{
			if (map[coord.x][coord.y] == '\n')
				bn++;
			if (ft_strchr("01CPE\n", map[coord.x][coord.y]) == 0 || bn > 1)
				return(0);
			coord.y++;
		}
		coord.x++;
	}
	return(1);
}
