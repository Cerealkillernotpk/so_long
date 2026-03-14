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

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

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

char		**parser(char **av, int ac);
int	 		flood_fill(char **map, int line);
int			flood_fill_checker(char **copy, t_vec *coord);
int			map_border_checker(char **map, int line);

/*Utils*/

void		free_map(char** map, int line);
int			line_number(char *filepath);

/*Test*/

void		print_map(char **map, int line);

#endif