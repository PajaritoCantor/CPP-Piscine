CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I inc
CPPFLAGS = -Iinc

NAME = weapon

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ_DIR = obj/

OBJS = $(SRC:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)
		@echo "\033[32m[OK] Compiling $(NAME)\033[0m"

$(OBJ_DIR)%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
clean:
		@rm -rf $(OBJ_DIR)
		@echo "\033[33m[CLEAN] Removing object directory\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[31m[FCLEAN] Removing executable and test files\033[0m"

re: fclean all
