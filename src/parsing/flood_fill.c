/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:18:15 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/27 21:32:01 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int count)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char*) * count);
	if (!copy)
		malloc_error();
	j = ft_strlen(map[i]);
	while (map[i] && i < count)
	{
		copy[i] = malloc(sizeof(char) * ft_strlen(map[i]));
		if (!copy[i])
			malloc_error();
		copy[i] = map [i];
		i++;
		// if (map[i][j] == '\0')
		// 	break ;
	}
	return(copy);
}

int	go_to(t_so_long *coord, char **copy, char c)
{
	int x;
	int	y;

	
	x = 0;
	y = 0;
	while (copy[x][y] || copy[x][y] != c)
	{
		y = 0;
		while (copy[x][y] != '\n' && copy[x][y] != c && copy[x][y] != '\0')
			y++;
		if (copy[x][y] == c || copy[x][y] == '\0')
			break;
		x++;
	}
	coord->x = x;
	coord->y = y;
	if (copy[x][y] != c)
		return (0);
	if (!(copy[x][y]))
		return (0);
	return (1);
}

static void flood(int x, int y, char **copy)
{
	if (copy[x][y] == 'X' || copy[x][y] == '1' || copy[x][y] == '\n')
		return ; 
	copy[x][y] = 'X';
	flood (x + 1, y, copy);
	flood (x - 1, y, copy);
	flood (x, y + 1, copy);
	flood (x, y - 1, copy);
} 

static int	fill(char **copy, t_so_long *coord)
{
	int		x;
	int		y;

	if (!go_to(coord, copy, 'P'))
		return (0);
	x = coord->x;
	y = coord->y;
	flood (x, y, copy);
	return(1);
}

int	flood_fill(t_so_long map)
{
	char	**copy;

	write(1, "Flood Fill\n", 11);
	map.x = 0;
	map.y = 0;
	copy = NULL;
	copy = malloc(sizeof(char *) * map.line_number);
	if (!copy)
		malloc_error();
	copy = copy_map(map.map, map.line_number); 
	if (!fill(copy, &map))
		map_error(map.map);
	if (!flood_fill_checker(copy, &map))
		map_error(map.map);
	print_map(copy, map.line_number);
	free_map(copy);
	return (1);
}
