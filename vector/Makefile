

CC = clang++
# FLAGS = -Wall -Wextra -Werror -std=c++98
FLAGS = -std=c++98
NAME = Vector
HEADER = vector.hpp
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp  $(HEADER)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re : fclean all