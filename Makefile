# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 22:08:48 by dximenes          #+#    #+#              #
#    Updated: 2025/07/26 13:25:45 by dximenes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

C_STD						= \033[0;39m
C_GRAY						= \033[0;90m
C_RED						= \033[0;91m
C_GREEN						= \033[0;92m
C_YELLOW					= \033[0;93m
C_BLUE						= \033[0;94m
C_MAGENTA					= \033[0;95m
C_CYAN						= \033[0;96m
C_WHITE						= \033[0;97m

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

EXEC						= fdf
TEST						= test
FTPRINTF					= $(FTPRINTF_PATH)libftprintf.a
LIBFT						= $(LIBFT_PATH)libft.a
GNL							= $(GNL_PATH)get_next_line.a
MLX							= $(MLX_PATH)libmlx.a

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

INCLUDE_PATH				= include
BUILD_PATH					= .build/
SRC							= src/

RENDERER_PATH				+= $(SRC)renderer/
RENDERER_DRAW_PATH			+= $(RENDERER_PATH)draw/
RENDERER_DRAW_AUX_PATH		+= $(RENDERER_DRAW_PATH)aux/
PARSE_PATH					+= $(SRC)parse/
PARSE_INITIALIZERS_PATH		+= $(PARSE_PATH)initializers/
UI_PATH						+= $(SRC)ui/
UI_ARTS_PATH				+= $(UI_PATH)arts/
AUX_PATH					+= $(SRC)aux/
AUX_GET_PATH				+= $(AUX_PATH)get/
CONTROLS_PATH				+= $(SRC)controls/
CONTROLS_EVENTS_PATH		+= $(CONTROLS_PATH)events/
CONTROLS_ACTIONS_PATH		+= $(CONTROLS_EVENTS_PATH)actions/

FTPRINTF_PATH				= $(INCLUDE_PATH)/ft_printf/
LIBFT_PATH					= $(FTPRINTF_PATH)$(INCLUDE_PATH)/libft/
GNL_PATH					= $(INCLUDE_PATH)/get_next_line/
MLX_PATH					= $(INCLUDE_PATH)/minilibx-linux/

# **************************************************************************** #
#                                    Files                                     #
# **************************************************************************** #

MAIN						= main

AUX_FILES					+= math
AUX_FILES					+= color
AUX_FILES					+= fps

AUX_GET_FILES				+= get_map_name

UI_FILES					+= menu

UI_ARTS_FILES				+= menu_arts
UI_ARTS_FILES				+= control_arts

RENDERER_FILES				+= render

RENDERER_DRAW_FILES			+= draw_map
RENDERER_DRAW_FILES			+= draw_art_menu

RENDERER_DRAW_AUX_FILES		+= bresenham
RENDERER_DRAW_AUX_FILES		+= image
RENDERER_DRAW_AUX_FILES		+= rotate

PARSE_FILES					+= load_map
PARSE_FILES					+= verify

PARSE_INITIALIZERS_FILES	+= initializers

CONTROLS_FILES				+= hooks
CONTROLS_FILES				+= transform

CONTROLS_EVENTS_FILES		+= keyboard
CONTROLS_EVENTS_FILES		+= mouse
CONTROLS_EVENTS_FILES		+= window

CONTROLS_ACTIONS_FILES		+= rotate_action
CONTROLS_ACTIONS_FILES		+= move_action
CONTROLS_ACTIONS_FILES		+= zoom_action

SRC_FILES					+= $(MAIN)
SRC_FILES					+= $(addprefix $(AUX_PATH), $(AUX_FILES))
SRC_FILES					+= $(addprefix $(AUX_GET_PATH), $(AUX_GET_FILES))
SRC_FILES					+= $(addprefix $(UI_PATH), $(UI_FILES))
SRC_FILES					+= $(addprefix $(UI_ARTS_PATH), $(UI_ARTS_FILES))
SRC_FILES					+= $(addprefix $(RENDERER_PATH), $(RENDERER_FILES))
SRC_FILES					+= $(addprefix $(RENDERER_DRAW_PATH), $(RENDERER_DRAW_FILES))
SRC_FILES					+= $(addprefix $(RENDERER_DRAW_AUX_PATH), $(RENDERER_DRAW_AUX_FILES))
SRC_FILES					+= $(addprefix $(PARSE_PATH), $(PARSE_FILES))
SRC_FILES					+= $(addprefix $(PARSE_INITIALIZERS_PATH), $(PARSE_INITIALIZERS_FILES))
SRC_FILES					+= $(addprefix $(CONTROLS_PATH), $(CONTROLS_FILES))
SRC_FILES					+= $(addprefix $(CONTROLS_EVENTS_PATH), $(CONTROLS_EVENTS_FILES))
SRC_FILES					+= $(addprefix $(CONTROLS_ACTIONS_PATH), $(CONTROLS_ACTIONS_FILES))

OBJ_FILES					+= $(MAIN)
OBJ_FILES					+= $(AUX_FILES)
OBJ_FILES					+= $(AUX_GET_FILES)
OBJ_FILES					+= $(UI_FILES)
OBJ_FILES					+= $(UI_ARTS_FILES)
OBJ_FILES					+= $(RENDERER_FILES)
OBJ_FILES					+= $(RENDERER_DRAW_FILES)
OBJ_FILES					+= $(RENDERER_DRAW_AUX_FILES)
OBJ_FILES					+= $(PARSE_FILES)
OBJ_FILES					+= $(PARSE_INITIALIZERS_FILES)
OBJ_FILES					+= $(CONTROLS_FILES)
OBJ_FILES					+= $(CONTROLS_EVENTS_FILES)
OBJ_FILES					+= $(CONTROLS_ACTIONS_FILES)

SRCS						= $(addprefix ./, $(addsuffix .c, $(SRC_FILES)))
OBJS						= $(addprefix $(BUILD_PATH), $(addsuffix .o, $(OBJ_FILES)))

# **************************************************************************** #
#                                    Git                                       #
# **************************************************************************** #

FTPRINTF_URL				= https://github.com/Denionline/ft_printf.git
GNL_URL						= https://github.com/Denionline/get_next_line.git
MLX_URL						= https://github.com/42paris/minilibx-linux.git

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC							= cc
CFLAGS						= -Werror -Wextra -Wall
MLXFLAGS					= -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz
MAKE						= make --no-print-directory

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
	@$(CC) $(CFLAGS) -I$(INCLUDE_PATH) $(OBJS) $(MLXFLAGS) $(FTPRINTF) $(GNL) $(MLX) -o $(EXEC)
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