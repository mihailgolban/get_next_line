# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 02:00:01 by mgolban           #+#    #+#              #
#    Updated: 2016/11/28 15:14:48 by mgolban          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[0;32mLibrary $@ is created\033[0m"	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean

clean:
	@echo "\033[0;31mDelete C object files\033[0m" 
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	@echo "\033[0;31mDelete $(NAME)\033[0m"

re: fclean all
