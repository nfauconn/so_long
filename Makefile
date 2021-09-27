NAME = so_long
LIBFT = libft
LIB = libft/libft.a
SRC_DIR  = ./srcs
OBJ_DIR  = ./objs
CC = clang
CFLAGS = -Wall -Wextra -Werror -g# -fsanitize=address
LD_FLAGS = -L libft -L mlx
MLX_FLAGS = -lm -lmlx -lXext -lX11
INCLUDES = -I includes -I libft/includes -I mlx
COMP = ${CC} ${CFLAGS}
RM	 = rm -rf
SRCS = error.c hooks.c main.c start.c
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
	valgrind \
	--leak-check=full --tool=memcheck \
	--show-reachable=yes \
	--track-fds=yes \
	--errors-for-leak-kinds=all \
	--show-leak-kinds=all ./${NAME}

clean:
	@make clean -C libft
	@make clean -C mlx
	@rm -rf ${OBJS}
	@echo "objs deleted"

fclean: clean
	@make fclean -C libft
	@rm -rf ${NAME}
	@echo "libs and programs deleted"

re: fclean all

.PHONY: all clean fclean re
