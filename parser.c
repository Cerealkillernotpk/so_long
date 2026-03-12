/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:34:57 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/12 18:28:53 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("/n");
}

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

int	get_map(char *filepath, char **map)
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
		map[i] = tmp;
		i++;
		tmp = get_next_line(fd);
	}
	return (1);
}

int	check_map_name(char *name)
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

int	parser(char **av, int ac)
{
	char	**map;
	int		line;
	
	line = 0;
	if (ac != 2)
	{
		ft_printf("Wrong argument number");
		return (0);
	}
	if (check_map_name(av[1]) == 0)
	{
		ft_printf("Name extemtion is invalid");
		return(0);
	}
	line = line_number(av[1]);
	if (line == 0)
	{
		ft_printf("Name or filepath is invalid");
		return(0);
	}
	map = malloc(sizeof(char*) * line);
	if (!map)
		return(0);
	get_map(av[1], map);
	print_map(map);
	return(1);
}
