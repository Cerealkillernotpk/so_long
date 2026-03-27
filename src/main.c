/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:50:08 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/27 13:40:39 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char**argv)
{
	int		line;
	char	**map;

	map = parser(argv, argc);
	if (map == 0)
		return(0);
	line = line_number(argv[1]);
	map_border_checker(map, line);
	print_map(map, line);
	ft_printf("\n\n");
	flood_fill(map,line);
	ft_printf("\n\n");
	free_map(map, line);
}
