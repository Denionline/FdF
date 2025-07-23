# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 22:08:48 by dximenes          #+#    #+#              #
#    Updated: 2025/07/23 14:24:46 by dximenes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD = \033[0;39m
C_GRAY = \033[0;90m
C_RED = \033[0;91m
C_GREEN = \033[0;92m
C_YELLOW = \033[0;93m
C_BLUE = \033[0;94m
C_MAGENTA = \033[0;95m
C_CYAN = \033[0;96m
C_WHITE = \033[0;97m

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

EXEC			= fdf
TEST			= test
FTPRINTF		= $(FTPRINTF_PATH)libftprintf.a
LIBFT			= $(LIBFT_PATH)libft.a
GNL				= $(GNL_PATH)get_next_line.a
MLX				= $(MLX_PATH)libmlx.a

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

INCLUDE_PATH	= include
BUILD_PATH		= .build/
SRC				= src/

PARSE_PATH		+= parse/
CONTROLS_PATH	+= controls/
EVENTS_PATH		+= $(CONTROLS_PATH)events/

FTPRINTF_PATH	= $(INCLUDE_PATH)/ft_printf/
LIBFT_PATH		= $(FTPRINTF_PATH)$(INCLUDE_PATH)/libft/
GNL_PATH		= $(INCLUDE_PATH)/get_next_line/
MLX_PATH		= $(INCLUDE_PATH)/minilibx-linux/

# **************************************************************************** #
#                                    Files                                     #
# **************************************************************************** #

MAIN			= fdf.c

FILES			+= render
FILES			+= draw
FILES			+= bresenham
FILES			+= math
FILES			+= image
FILES			+= color
FILES			+= rotate
FILES			+= fps

PARSE_FILES		+= initializers
PARSE_FILES		+= load_map
PARSE_FILES		+= verify

CONTROLS_FILES	+= hooks
CONTROLS_FILES	+= transform

EVENTS_FILES	+= keyboard
EVENTS_FILES	+= mouse
EVENTS_FILES	+= window

SRC_FILES		+= $(FILES)
SRC_FILES		+= $(addprefix $(PARSE_PATH), $(PARSE_FILES))
SRC_FILES		+= $(addprefix $(EVENTS_PATH), $(EVENTS_FILES))
SRC_FILES		+= $(addprefix $(CONTROLS_PATH), $(CONTROLS_FILES))

OBJ_FILES		+= $(FILES)
OBJ_FILES		+= $(PARSE_FILES)
OBJ_FILES		+= $(EVENTS_FILES)
OBJ_FILES		+= $(CONTROLS_FILES)

SRCS		= $(addprefix $(SRC), $(addsuffix .c, $(SRC_FILES)))
OBJS		= $(addprefix $(BUILD_PATH), $(addsuffix .o, $(OBJ_FILES)))

# **************************************************************************** #
#                                    Git                                       #
# **************************************************************************** #

FTPRINTF_URL	= https://github.com/Denionline/ft_printf.git
GNL_URL			= https://github.com/Denionline/get_next_line.git
MLX_URL			= https://github.com/42paris/minilibx-linux.git

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Werror -Wextra -Wall
MLXFLAGS		= -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz
MAKE			= make --no-print-directory

# **************************************************************************** #
#                                  Commands                                    #
# **************************************************************************** #


all: verify_ftprintf $(FTPRINTF) verify_gnl $(GNL) verify_mlx $(MLX) $(EXEC)
	@printf "\n$(C_GREEN)Program is ready :D$(C_STD)\n"

$(FTPRINTF):
	@$(MAKE) -C $(FTPRINTF_PATH)

$(GNL):
	@$(MAKE) -C $(GNL_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(EXEC): | $(BUILD_PATH)
	@TOTAL=$$(echo $(SRCS) | wc -w); \
	CUR=1; \
	for SRC in $(SRCS); do\
		OBJ=$(BUILD_PATH)$$(basename $$SRC .c).o;\
		$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -I/usr/include -I$(MLX_PATH) -O3 -c $$SRC -o $$OBJ;\
		PERC=$$(printf "%d" $$((100 * CUR / TOTAL))); \
		FILLED=$$(printf "%0.f" $$((20 * PERC / 100))); \
		EMPTY=$$((20 - FILLED)); \
		BAR=$$(printf "$(C_GREEN)%*s$(C_STD)" $$FILLED "" | tr " " "#")$$(printf "%*s" $$EMPTY "" | tr " " "."); \
		printf "\rCompiling [%s] %3d%%" $$BAR $$PERC; \
		CUR=$$((CUR + 1)); \
	done; \
	printf "\n";
	@$(CC) $(CFLAGS) -I$(INCLUDE_PATH) $(OBJS) $(MAIN) $(MLXFLAGS) $(FTPRINTF) $(GNL) $(MLX) -o $(EXEC)
	@printf "\n$(C_GREEN)Success to created $(C_STD)$(EXEC)\n\n"

$(BUILD_PATH):
	@printf "\n$(C_CYAN)Building project...$(C_STD)\n"
	@mkdir $(BUILD_PATH)

# %.o: %.c
# 	@$(CC) -I$(INCLUDE_PATH) -c $< -o $@
# 	@printf "Compiling $(C_YELLOW)$<$(C_STD)...\n"

test:
	@$(CC) $(CFLAGS) $(OBJS) -g -pg $(MLXFLAGS) $(FTPRINTF) $(GNL) $(MLX) -o $(TEST)
	@printf "\n$(C_GREEN)Success to created $(C_STD)$(EXEC)\n\n"

clean:
	@rm -rf $(BUILD_PATH)

fclean: clean
	@rm -rf $(EXEC)

re: fclean all

t0:
	@./$(EXEC) maps/42.fdf
t1:
	@./$(EXEC) maps/elem-col.fdf
t2:
	@./$(EXEC) maps/10-2.fdf
v:
	@valgrind ./$(EXEC) maps/42.fdf

# libft processes
verify_ftprintf:
	@if test ! -d "$(FTPRINTF_PATH)"; then $(MAKE) get_ftprintf; \
		else printf "ft_printf: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_ftprintf:
	@echo "Cloning ftprintf"
	@git clone $(FTPRINTF_URL) $(FTPRINTF_PATH)
	@echo "ft_printf clone successfully downloaded"

# get_next_line processes
verify_gnl:
	@if test ! -d "$(GNL_PATH)"; then $(MAKE) get_gnl; \
		else printf "get_next_line: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_gnl:
	@printf "Cloning get_next_line\n"
	@git clone $(GNL_URL) $(GNL_PATH)
	@printf "\n$(C_GREEN)get_next_line$(C_STD) successfully downloaded\n"

# minilibx processes
verify_mlx:
	@if test ! -d "$(MLX_PATH)"; then $(MAKE) get_head; \
		else printf "minilibx: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_head:
	@printf "Cloning get_next_line\n"
	@git clone $(MLX_URL) $(MLX_PATH)
	@printf "\n$(C_GREEN)minilibx$(C_STD) successfully downloaded\n"

#general processes
update_modules:
	@git submodule init
	@git submodule update --recursive --remote