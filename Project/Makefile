# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 13:32:03 by nfauconn          #+#    #+#              #
#    Updated: 2024/01/26 13:32:04 by nfauconn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = libft
LIB = libft/libft.a
SRC_DIR  = ./srcs
OBJ_DIR  = ./objs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g# -fsanitize=address
LD_FLAGS = -L libft -L mlx
MLX_FLAGS = -lm -lmlx -lXext -lX11
INCLUDES = -I includes -I libft/includes -I mlx
COMP = ${CC} ${CFLAGS}
RM	 = rm -rf
SRCS = color.c check_map.c close_window.c draw.c error.c find_tile_type.c free.c get_display_values.c hooks.c init_screen.c init_struct.c main.c parse_map.c start.c
OBJS = ${addprefix ${OBJ_DIR}/,${SRCS:.c=.o}}

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

$(NAME): ${OBJS}
	@make -C libft
	@make -C mlx
	@${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}
	@echo "so_long created"

all: ${NAME}

val: ${NAME}
	valgrind ./${NAME}

norm: ${NAME}
	norminette ${SRCS} includes/*.h ${LIBFT}

clean:
	@make clean -C libft
	@make clean -C mlx
	@rm -rf ${OBJ_DIR}
	@echo "objs deleted"

fclean: clean
	@make fclean -C libft
	@rm -rf ${NAME}
	@echo "libs and programs deleted"

re: fclean all

.PHONY: all clean fclean re
