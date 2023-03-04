# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 13:43:18 by okraus            #+#    #+#              #
#    Updated: 2023/01/27 16:52:09 by okraus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \
	ft_string_pointer.c \
	ft_printf_utils.c \
	ft_padding.c \
	ft_printformat.c \
	ft_string_basebig \
	ft_string_binocthex \
	ft_string_colour \
	ft_string_hexabig.c \
	ft_string_hexasmall.c \
	ft_string_integer.c \
	ft_string_string.c \
	ft_string_unsigned.c	
OBJ = $(SRC:.c=.o)
INCS = ft_printf.h
LIBC = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(INCS)
	@$(CC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
bonus: all

re: fclean all

.PHONY: all clean fclean re
