# Variables

NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

# Rules

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
