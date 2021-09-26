NAME = so_long
LIBFT = libft
LIB = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft/includes
COMP = ${CC} ${CFLAGS}
RM	 = rm -rf
CFILES = main.c

OBJS = ${addprefix ${OBJ_DIR}/,${CFILES:%.c=%.o}}
SRC_DIR  = ./srcs
OBJ_DIR  = ./objs

all: makelib ${NAME}

makelib:
	@make -C ${LIBFT}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} -no-pie -o $@ $<  ${LIB} ${INCLUDES}
	@echo "so_long created"

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} -o $@ -c $< ${INCLUDES}

clean:
	@${RM} ${OBJ_DIR}
	@make clean -C ${LIBFT}
	@echo "objs deleted"

fclean: clean
	@${RM} ${NAME}
	@make fclean -C ${LIBFT}
	@echo "libs and programs deleted"
			
re: fclean all

.PHONY: all clean fclean re