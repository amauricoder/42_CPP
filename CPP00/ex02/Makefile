CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02
SRC = Account.cpp tests.cpp
OBJ_DIR = ./objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
#	$(CC) $(CFLAGS) main.cpp $(OBJ) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#USE THIS TO COMPARE THE FILES AND TEST IT
#SAVE THE OUTPUT AS 'file'
#diff <(sed 's/^[^ ]* //' file) <(sed 's/^[^ ]* //' 19920104_091532.log)