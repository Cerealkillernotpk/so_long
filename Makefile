# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 13:50:46 by adakhama          #+#    #+#              #
#    Updated: 2026/03/27 15:01:27 by adakhama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g #//

NAME = so_long

SRC := $(shell find src library/get_next_line library/struct -type f -name "*.c")
	
INCLUDES_DIR = -Ilibrary/ -Ilibrary/lib/
INCLUDES = $(INCLUDES_DIR)
	
OBJ = $(SRC:%.c=build/%.o)

all: $(NAME)

$(NAME):$(OBJ)
	@make -C library/printf -s
	@make -C library/libft -s
	$(CC) $(OBJ) -o $(NAME) -Llibrary/libft -Llibrary/printf -l:libft.a -l:libftprintf.a

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf build
	make -C library/printf clean -s
	make -C library/libft clean -s

fclean: clean
	-rm -f $(NAME)
	make -C library/printf fclean -s
	make -C library/libft	fclean -s

re: fclean all
	make -C library/printf re -s
	make -C library/libft re -s

# .SILENT:
.PHONY: all clean fclean re
