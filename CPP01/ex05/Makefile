# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/03 18:15:07 by jurodrig          #+#    #+#              #
#    Updated: 2026/08/03 18:22:48 by jurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = harl

SRC = main.cpp Harl.cpp
OBJ_DIR = obj/

OBJS = $(SRC:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all