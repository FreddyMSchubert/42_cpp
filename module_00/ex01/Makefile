EXECUTABLE := "phonebook"

SRC := Contact.cpp main.cpp
OBJ := $(SRC:.cpp=.o)
FLAGS := -Wall -Wextra -Werror -std=c++17

all: linking

linking: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(EXECUTABLE) -fsanitize=address -g

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@ -fsanitize=address -g

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXECUTABLE)

re: fclean all