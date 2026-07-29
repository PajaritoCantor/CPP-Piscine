CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = braiiiiiiinnnzzzZ

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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

