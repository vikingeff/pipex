#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 11:26:07 by gleger            #+#    #+#              #
#    Updated: 2014/05/11 19:19:00 by gleger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pipex

CC = clang

SRCS = ft_check_things.c \
		ft_environ.c \
		ft_error.c \
		ft_pipe.c \
		ft_error_2.c \
		ft_puts.c \
		ft_tools.c \
		ft_other.c \
		main.c

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror -O3 -pedantic -I ./includes/

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	$(CC) $(FLAG) -o $@ $^ 
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

%.o: %.c ./includes/pipex.h
	@echo "\033[1;36;m[Compiling $<] \t\033[0m: " | tr -d '\n'
	$(CC) $(FLAG) -c $<

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJ)

fclean: clean
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
