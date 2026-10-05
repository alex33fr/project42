CXX				:= c++
CXXFLAGS		:= -Wall -Wextra -Werror -std=c++98
BUILD_DIR		:= .obj

NAME			:= sedIsForLosers

SRC				:= main.cpp
TEST_FILE		:= test.txt
OBJ				:= $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

all: $(NAME) $(TEST_FILE)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(TEST_FILE):
	@printf "the cat sleeps\na black cat and a white cat\n" > $(TEST_FILE)
	@printf "catcat\nnothing here\n" >> $(TEST_FILE)

# Compile .cpp -> .o
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug: fclean
	@$(MAKE) CXXFLAGS="$(CXXFLAGS)" all

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME) $(TEST_FILE) $(TEST_FILE).replace

re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re