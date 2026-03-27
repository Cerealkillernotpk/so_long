/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:34:57 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/27 20:42:43 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int line_number(char *filepath)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0; 	 
	fd = open(filepath, O_RDONLY);
	tmp = NULL;
	if (fd == -1)
		return(0);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (tmp)
			free(tmp);
		i++;
	}
	return(i);
}

static int	get_map(char *filepath, char **map)
{
	int		fd;
	int		i;
	char*	tmp;

	fd = 0;
	i = 0;
	fd = open(filepath, O_RDONLY);
	tmp = get_next_line(fd);
	while(tmp != NULL)
	{
		if (!tmp)
			map_error(map);
		map[i] = tmp;
		i++;
		tmp = get_next_line(fd);
	}
	return (1);
}

static int	check_map_name(char *name)
{
	size_t	len;
	size_t	i;
	char	*end;
	
	len = ft_strlen(name) - 4;
	i = 0;
	end = ".ber";
	while(name[len])
	{
		if (!(end[i] == name[len]))
			return(0);
		i++;
		len++;
	}
	return (1);
}

t_so_long	parser(char **av)
{
	t_so_long	map;

	if (!check_map_name(av[1]))
		file_error_message(1);
	map.line_number = line_number(av[1]);
	if (map.line_number == 0)
		file_error_message(4);
	map.map = malloc(sizeof(char*) * map.line_number);
	if (!map.map)
		malloc_error();
	get_map(av[1], map.map);
	if (!check_map(map.map, map.line_number))
		map_error(map.map);
	return(map);
}
