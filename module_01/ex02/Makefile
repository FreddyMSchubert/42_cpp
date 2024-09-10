EXECUTABLE := hi_this_is_brain

SRC := main.cpp
OBJ := $(SRC:.cpp=.o)
FLAGS := -Wall -Wextra -Werror -std=c++98

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
