CXX				:= c++
CXXFLAGS		:= -Wall -Wextra -Werror -std=c++98
BUILD_DIR		:= .obj

NAME			:= megaphone

SRC				:= megaphone.cpp
OBJ				:= $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Compil .cpp -> .o
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug: fclean
	@$(MAKE) CXXFLAGS="$(CXXFLAGS)" all

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re