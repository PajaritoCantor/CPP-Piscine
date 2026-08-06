# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/06 19:26:27 by jurodrig          #+#    #+#              #
#    Updated: 2026/08/06 19:32:51 by jurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = My_First_Class_In_Orthodox_Canonical_Form

SRC = main.cpp Fixed.cpp
OBJ_DIR = obj/

OBJS = $(SRC:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@echo "\033[32m[OK] Compiling $(NAME)\033[0m"

$(OBJ_DIR)%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)
		@echo "\033[33m[CLEAN] Removing object directory\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m[FCLEAN] Removing executable and test files\033[0m"

re: fclean all