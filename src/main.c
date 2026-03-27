/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:50:08 by adakhama          #+#    #+#             */
/*   Updated: 2026/03/27 21:26:30 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_so_long	map;

	if (ac != 2)
		file_error_message(0);
	map = parser(av);
	if (!map.map)
		malloc_error();
	// print_map(map.map, map.line_number);
	ft_printf("\n\n");
	flood_fill(map);
	ft_printf("\n\n");
	free_map(map.map);
}
