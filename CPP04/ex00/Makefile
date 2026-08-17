# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/14 19:47:50 by jurodrig          #+#    #+#              #
#    Updated: 2026/08/17 02:04:54 by jurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I Inc/

NAME = polymorphism

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJ_DIR = obj/

OBJS = $(SRC:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[32m[OK] Compiling $(NAME)\033[0m"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[33m[CLEAN] Removing object directory\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@echo "\033[31m[FCLEAN] Removing executable and test files\033[0m"

re: fclean all

.PHONY: all clean fclean re