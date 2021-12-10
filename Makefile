

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98
FT_VEC_NAME = FtVector
STD_VEC_NAME = StdVector
VEC_HEADER = vector.hpp
VEC_SRC = main_vector.cpp

FT_MAP_NAME = FtMap
STD_MAP_NAME = StdMap
MAP_HEADER = map.hpp
MAP_SRC = main_map.cpp

FT_STACK_NAME = Ftstack
STD_STACK_NAME = Stdstack
STACK_HEADER = stack.hpp
STACK_SRC = main_stack.cpp

TDIR = ./test

all :
	@echo "make vector || make map || make stack"

#---------------------Vector--------------------------
vector: $(TDIR)/$(FT_VEC_NAME) $(TDIR)/$(STD_VEC_NAME)

$(TDIR)/$(FT_VEC_NAME) : $(VEC_SRC) $(VEC_HEADER)
	mkdir -p $(TDIR)
	$(CC) $(FLAGS) $< -D PH=ft -o $@

$(TDIR)/$(STD_VEC_NAME) : $(VEC_SRC) $(VEC_HEADER)
	$(CC) $(FLAGS) $< -D PH=std -o  $@

diffvec: vector
	@$(TDIR)/$(FT_VEC_NAME) > $(TDIR)/$(FT_VEC_NAME).txt
	@$(TDIR)/$(STD_VEC_NAME) > $(TDIR)/$(STD_VEC_NAME).txt
	diff $(TDIR)/$(FT_VEC_NAME).txt $(TDIR)/$(STD_VEC_NAME).txt

#---------------------Map--------------------------
map: $(TDIR)/$(FT_MAP_NAME) $(TDIR)/$(STD_MAP_NAME)

$(TDIR)/$(FT_MAP_NAME) : $(MAP_SRC) $(MAP_HEADER)
	mkdir -p $(TDIR)
	$(CC) $(FLAGS) $< -D PH=ft -o $@

$(TDIR)/$(STD_MAP_NAME) : $(MAP_SRC) $(MAP_HEADER)
	$(CC) $(FLAGS) $< -D PH=std -o  $@

diffmap: map
	@$(TDIR)/$(FT_MAP_NAME) > $(TDIR)/$(FT_MAP_NAME).txt
	@$(TDIR)/$(STD_MAP_NAME) > $(TDIR)/$(STD_MAP_NAME).txt
	diff $(TDIR)/$(FT_MAP_NAME).txt $(TDIR)/$(STD_MAP_NAME).txt

#---------------------Stack--------------------------
stack: $(TDIR)/$(FT_STACK_NAME) $(TDIR)/$(STD_STACK_NAME)

$(TDIR)/$(FT_STACK_NAME) : $(STACK_SRC) $(STACK_HEADER)
	mkdir -p $(TDIR)
	$(CC) $(FLAGS) $< -D PH=ft -o $@

$(TDIR)/$(STD_STACK_NAME) : $(STACK_SRC) $(STACK_HEADER)
	$(CC) $(FLAGS) $< -D PH=std -o  $@

diffstack: stack
	@$(TDIR)/$(FT_STACK_NAME) > $(TDIR)/$(FT_STACK_NAME).txt
	@$(TDIR)/$(STD_STACK_NAME) > $(TDIR)/$(STD_STACK_NAME).txt
	diff $(TDIR)/$(FT_STACK_NAME).txt $(TDIR)/$(STD_STACK_NAME).txt

fclean:
	@rm -rf $(TDIR)

re : fclean all