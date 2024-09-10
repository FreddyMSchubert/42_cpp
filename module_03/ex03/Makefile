EXECUTABLE := clappinAndScavvinAndFragginAndDiamondinAndTrappin

SRC := $(shell find . -name "*.cpp")
OBJ := $(SRC:.cpp=.o)
FLAGS := -Wall -Wextra -Werror -Wshadow -std=c++17

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
