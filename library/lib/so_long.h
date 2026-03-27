/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:05:16 by adakhama          #+#    #+#             */
/*   Updated: 2026/01/10 16:25:10 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include "library/printf/ft_printf.h"
# include "library/libft/libft.h"
# include "library/get_next_line/get_next_line_bonus.h"

typedef struct s_stack
{
	void			*content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_so_long
{
	int		x;
	int		y;
	int		line_number;
	char	**map;
}t_so_long;


/*Librairie fonction de struct*/

int			ft_lstsize(t_stack *lst);
void		ft_lstiter(t_stack *lst, void (*f)(void *));
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstclear(t_stack **lst, void (*del)(void *));
void		ft_lstdelone(t_stack *lst, void (*del)(void*));
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));
t_stack		*ft_lstnew(void *content);
t_stack		*ft_lstnew_nbr(int content);

/*Parser*/

t_so_long	parser(char **av);
int	 		flood_fill(t_so_long map);
int			flood_fill_checker(char **copy, t_so_long *coord);
int			map_border_checker(char **map, int line);

/*Utils*/

void		free_map(char** map);
int			line_number(char *filepath);
int			go_to(t_so_long *coord, char **copy, char c);

/*Test*/

void		print_map(char **map, int line);
int			check_map(char	**map, int line);

/*Error*/

void	file_error_message(int error);
void	malloc_error(void);
void	map_error(char **map);
void	malloc_error_array(char *array);

#endif