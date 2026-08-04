CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFLAGS = -Iinc

NAME = weapon

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ_DIR = obj/

OBJS = $(SRC:%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)
$(OBJ_DIR)%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
clean:
		rm -rf $(OBJ_DIR)
fclean: clean
		rm -f $(NAME)
re: fclean all
