# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 22:08:48 by dximenes          #+#    #+#              #
#    Updated: 2025/06/20 14:56:08 by dximenes         ###   ########.fr        #
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

EXEC		= FdF
LIBFT		= $(LIBFT_PATH)libft.a
GNL			= $(GNL_PATH)get_next_line.a
MLX			= $(MLX_PATH)libmlx.a

# **************************************************************************** #
#                                    Path's                                    #
# **************************************************************************** #

INC		= include

LIBFT_PATH		= $(INC)/libft/
GNL_PATH		= $(INC)/get_next_line/
MLX_PATH		= $(INC)/minilibx-linux/

# **************************************************************************** #
#                                    Files                                     #
# **************************************************************************** #

FILES	+= main
FILES	+= render
FILES	+= load_map

SRC	= $(addprefix ./, $(addsuffix .c, $(FILES)))
OBJ	= $(addprefix ./, $(addsuffix .o, $(FILES)))

# **************************************************************************** #
#                                    Git                                       #
# **************************************************************************** #

LIBFT_URL	= https://github.com/Denionline/Libft.git
GNL_URL		= https://github.com/Denionline/get_next_line.git
MLX_URL		= https://github.com/42paris/minilibx-linux.git

# **************************************************************************** #
#                                  Compiler                                    #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Werror -Wextra -Wall
MLXFLAGS	= -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -I$(MLX_PATH) -lXext -lX11 -lm -lz
MAKE		= make --no-print-directory

# **************************************************************************** #
#                                  Commands                                    #
# **************************************************************************** #

all: verify_libft verify_gnl verify_mlx $(LIBFT) $(GNL) $(MLX) $(EXEC)
	@printf "\n$(C_GREEN)Program is ready :D$(C_STD)\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(GNL):
	@$(MAKE) -C $(GNL_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(EXEC): $(OBJ)
	@$(CC) $(MLXFLAGS) $(OBJ) $(LIBFT) $(GNL) $(MLX) -o $(EXEC)
	@printf "\n$(C_GREEN)Success to created $(C_STD)$(EXEC)\n\n"

%.o: %.c
	@$(CC) -I$(INC) -I/usr/include -I$(MLX_PATH) -O3 -c $< -o $@
	@printf "Compiling $(C_YELLOW)$<$(C_STD)...\n"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(EXEC)

re: fclean all

t:
	@./FdF maps/test_maps/42.fdf
v:
	@valgrind ./FdF maps/test_maps/42.fdf

# libft processes
verify_libft:
	@if test ! -d "$(LIBFT_PATH)"; then $(MAKE) get_libft; \
		else printf "libft: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_libft:
	@echo "Cloning Libft"
	@git clone $(LIBFT_URL) $(LIBFT_PATH)
	@echo "Libft clone successfully downloaded"

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
	@if test ! -d "$(MLX_PATH)"; then $(MAKE) get_mlx; \
		else printf "minilibx: $(C_GREEN)✅$(C_STD)\n"; fi
	@$(MAKE) update_modules

get_mlx:
	@printf "Cloning get_next_line\n"
	@git clone $(MLX_URL) $(MLX_PATH)
	@printf "\n$(C_GREEN)minilibx$(C_STD) successfully downloaded\n"

#general processes
update_modules:
	@git submodule init
	@git submodule update --recursive --remote