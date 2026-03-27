/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:18:15 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/27 13:41:31 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	copy_map(char **map, char **copy, int line)
{
	int		i;

	i = 0;
	while (map[i] && i < line)
	{
		copy[i] = malloc(sizeof(char) * ft_strlen(map[i]));
		if (!copy[i])
			return(0);
		copy[i] = map [i];
		i++;
	}
	return(1);
}

int	go_to(t_vec *coord, char **copy, char c)
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

static int	fill(char **copy, t_vec *coord)
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

int	flood_fill(char **map, int line)
{
	char	**copy;
	t_vec	coord;

	write(1, "Flood Fill\n", 11);
	coord.x = 0;
	coord.y = 0;
	copy = malloc(sizeof(char *) * line);
	if (!copy)
		return (0);
	if (!copy_map(map, copy, line))
		return (0);
	if (!fill(copy, &coord))
	{
		ft_printf("Invalid map !!\n");
		return (0);
	}
	if (flood_fill_checker(copy, &coord) == 0)
	{
		ft_printf("Invalid map !!\n");
		return (0);
	}
	print_map(copy, line);
	free_map(copy, line);
	return (1);
}
