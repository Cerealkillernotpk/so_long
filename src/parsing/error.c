/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:08:47 by adakhama          #+#    #+#             */
/*   Updated: 2026/04/01 16:04:37 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error_message(int error)
{
	if (error == 0)
		ft_printf("Wrong argument number !!\n");
	else if (error == 1)
		ft_printf("Name extention is invalid !!\n");
	else if (error == 3)
		ft_printf("Name or filepath is invalid !!\n");
	else if (error == 4)
		ft_printf("Invalid map !!\n");
	exit (EXIT_FAILURE);
}

void	malloc_error(void)
{
	ft_printf("Malloc fail !!\n");
	exit (EXIT_FAILURE);
}

void	malloc_error_array(char *array)
{
	ft_printf("Malloc fail !!\n");
	free(array);
	exit (EXIT_FAILURE);
}

void	map_error(char **map)
{
	ft_printf("Map error or invalid map !!\n");
	free_map(map);	
	exit (EXIT_FAILURE);
}