NAME = PmergeMe

#Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

SOURCE_DIR = .
BUILD_DIR = build

CC = c++
CFLAGS = -std=c++98
CFLAGS += -MMD -g
CFLAGS += -Wall -Wextra -Werror
# CFLAGS += -fsanitize=address,undefined,leak

FILENAMES = PmergeMe.cpp \
			FjVector.cpp

SRC = $(addprefix $(SOURCE_DIR)/, $(FILENAMES))
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

$(BUILD_DIR)/%.o : %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -fr $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test
