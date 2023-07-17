# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/14 13:28:13 by fras          #+#    #+#                  #
#    Updated: 2023/07/17 17:34:23 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = gcc
CFLAGS = -Werror -Wextra -Wall
MLX42_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
INCLUDE = -I include -I $(MLX42_DIR)/include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
RM = rm -f

# Libraries
LIB_DIR = lib
MLX42 = $(LIB_DIR)/libmlx42.a
MLX42_DIR = $(LIB_DIR)/MLX42
MLX42_BUILD = $(MLX42_DIR)/build

ifdef DEBUG
CFLAGS += -g -D DEBUG
MLX42_DEBUG = -DDEBUG=1
endif

ifdef FSAN
CFLAGS += -fsanitize=address -g
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

$(NAME): $(MLX42) $(OBJECTS)
	$(CC) $(CFLAGS) $(MLX42_FLAGS) $(INCLUDE) -o $@ $(OBJECTS) $(MLX42)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

# Libraries
$(MLX42):
	cmake -S $(MLX42_DIR) -B $(MLX42_BUILD) $(MLX42_DEBUG)
	make -C $(MLX42_BUILD) -j4
	cp $(MLX42_BUILD)/$(@F) $@
	@echo "\033[92mMLX library available in ./$(MLX42)\033[0m"

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) -r obj

fclean: clean
	$(RM) $(MLX42)
	$(RM) -rf $(MLX42_BUILD)
	$(RM) $(NAME)

re: fclean all

# Debugging
debug:
	$(MAKE) DEBUG=1 

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

# Info Message
message:
	@echo "\033[92m$(EXECUTABLE) is ready for usage!\033[0m"

# Submodule functions
initialize_submodules:
	git submodule update --init --recursive
	git submodule foreach --recursive git checkout master

update_submodules:
	git submodule update --recursive
	git submodule foreach --recursive git fetch
	git submodule foreach git merge origin master
