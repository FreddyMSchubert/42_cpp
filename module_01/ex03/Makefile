EXECUTABLE := unnecessary_violence

SRC := main.cpp Human.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ := $(SRC:.cpp=.o)
FLAGS := -Wall -Wextra -Werror -std=c++98

all: linking

linking: $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXECUTABLE)

re: fclean all