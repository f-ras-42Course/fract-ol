# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fras <fras@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/14 13:28:13 by fras          #+#    #+#                  #
#    Updated: 2023/07/16 15:41:44 by fras          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = gcc
CFLAGS = -Werror -Wextra -Wall
INCLUDE = -I include -I $(EXTLIB_DIR)/include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(CLIENT_SOURCES:%.c=%.o))
RM = rm -f

# Libraries
LIB_DIR = lib
EXTLIB_DIR = $(LIB_DIR)/libs42 $(LIB_DIR)/MLX42
MLX42 = $(LIB_DIR)/libmlx42.a
LIBRARIES = $(addprefix $(LIB_DIR)/, libft.a libftprintf.a libftextended.a)

ifdef DEBUG
CFLAGS += -g
endif

ifdef FSAN
CFLAGS += -fsanitize=address -g
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

client: $(LIBRARIES) $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJECTS) $(LIBRARIES)
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

# Libraries
$(LIBRARIES): $(EXTLIB_DIR)/$(@F)
	$(MAKE) -C $(EXTLIB_DIR) $(@F)
	cp $(EXTLIB_DIR)/$(@F) $@

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) -r obj

fclean: clean
	$(MAKE) -C $(EXTLIB_DIR) $@
	$(RM) $(LIBRARIES)
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