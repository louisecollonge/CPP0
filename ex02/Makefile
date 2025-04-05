# Variables

NAME = Accounting
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

OBJ_DIR = obj

SRC =	Account.cpp \
		tests.cpp


OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
