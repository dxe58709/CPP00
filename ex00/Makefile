NAME = a.out

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -g -fsanitize=address
RM = rm -rf


FILES = main Fixed
SRC = $(FILES:=.cpp)

FILES_S = Fixed
HEADER = $(FILES_S:=.hpp)

OBJDIR = objzs
OBJ = $(addprefix $(OBJDIR)/, $(FILES:=.o))


LEAK = valgrind --tool=memcheck

$(NAME): $(OBJ) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

all: $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

echo:
	echo $(FILES) $(SRC) $(OBJ) $(HEADER)

test:
	@./$(NAME)

leak:
	$(LEAK) ./$(NAME)

.PHONY: all clean fclean re leak bonus
