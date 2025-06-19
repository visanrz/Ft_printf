# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victorsa <victorsa@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/04 14:17:30 by victorsa          #+#    #+#              #
#    Updated: 2025/06/04 14:17:30 by victorsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = libftprintf.a

# Source files and object files
SRC = ft_printf.c ft_printf_supplies.c

# Default rule that compiles everything
all: $(NAME)

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

# Rule to create the library
$(NAME): $(OBJS)
	ar rcs ${NAME} ${OBJS}

# Rule to delete all created .o object files
clean:
	rm -f $(OBJS)

# Delete all .o and .a files
fclean: clean
	rm -f $(NAME)

# Compile everything from scratch
re: fclean all

# Declaration of objectives that aren't files
.PHONY: all clean fclean re
