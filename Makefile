#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 11:26:07 by gleger            #+#    #+#              #
#    Updated: 2014/05/06 21:44:01 by drabahi          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = pipex

LIBNAME = libpipex.a

SRCS = srcs/ft_check_things.c \
		srcs/ft_environ.c \
		srcs/ft_error.c \
		srcs/ft_pipe.c \
		srcs/ft_error_2.c \
		srcs/ft_puts.c

OBJ = $(SRCS:.c=.o)

INCLUDE = includes/

INCLUDEPRINTF = srcs/printf/includes

INCLUDELIBFT = srcs/libft/

FLAG = -Wall -Wextra -Werror -ansi -pedantic

all: $(NAME)

$(NAME): $(LIBNAME)
	@gcc $(FLAG) -o $(NAME) main.c -L./ -lpipex -I$(INCLUDE)

$(LIBNAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(LIBNAME)

%.o: %.c
	@gcc $(FLAG) -c -o $@ $^ -I$(INCLUDE)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(LIBNAME)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all