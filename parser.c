/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:34:57 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/26 17:27:12 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int line_number(char *filepath)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return(0);
	while (get_next_line(fd) != NULL)
		i++;
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
		map[i] = malloc(sizeof(char) * ft_strlen(tmp));
		if (!map[i])
			return(0);
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

int	file_error_message(int ac, char *str, int line)
{
	if (ac != 2)
	{
		ft_printf("Wrong argument number");
		return (0);
	}
	if (check_map_name(str) == 0)
	{
		ft_printf("Name extemtion is invalid");
		return(0);
	}
	if (line == 0)
	{
		ft_printf("Name or filepath is invalid");
		return(0);
	}
	return(1);
}

char	**parser(char **av, int ac)
{
	char	**map;
	int		line;
	
	line = line_number(av[1]);
	if (file_error_message(ac,av[1], line) == 0)
		return(NULL);
	map = malloc(sizeof(char*) * line);
	if (!map)
		return(NULL);
	get_map(av[1], map);
	if (check_map(map, line) == 0)
	{
		ft_printf("Map error");
		return(0);		
	}
	return(map);
}
