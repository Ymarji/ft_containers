

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
FLAGS = -std=c++98
FT_VEC_NAME = FtVector
STD_VEC_NAME = StdVector
VEC_HEADER = vector.hpp
VEC_SRC = main_vector.cpp
# OBJ = $(SRC:.cpp=.o)

all : $(FT_VEC_NAME) $(STD_VEC_NAME)

$(FT_VEC_NAME) : $(VEC_SRC) $(VEC_HEADER)
	$(CC) $(FLAGS) $(VEC_SRC) -D PH=ft -o ./test/$(FT_VEC_NAME)

$(STD_VEC_NAME) : $(VEC_SRC) $(VEC_HEADER)
	$(CC) $(FLAGS) $(VEC_SRC) -D PH=std -o ./test/$(STD_VEC_NAME)

test: test.cpp
	$(CC) test.cpp -o test

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	# rm a.out

re : fclean all