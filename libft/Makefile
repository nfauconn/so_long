NAME = libft.a
CC	 = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/
COMP = ${CC} ${CFLAGS} ${INCLUDES}
RM	 = rm -rf
SRC = ft_atoi.c \
ft_atoi_base.c\
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_nbrlen_base.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strcmp.c \
ft_strdup.c \
ft_strfdup.c \
ft_strfjoin.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_ulltoa_base.c \
get_next_line.c \
rev_int_tab.c \
sort_int_tab.c \
str_isdigit.c \
strfjoinchar.c \
conv_c.c\
conv_s.c\
conv_p.c\
conv_d_i.c\
conv_u.c\
conv_x.c\
conv_mx.c\
conv_percent.c\
convert.c\
fill_nb.c\
ft_isflagpf.c\
ft_printf.c\
init_printf.c\
insert_into_buffer.c\
main_loop.c\
parse_printf.c\

OBJS = ${addprefix ${OBJ_DIR}/,${SRC:.c=.o}}
SRC_DIR  = ./srcs
OBJ_DIR  = ./objs

all : ${NAME}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
	@echo "lib created"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	@echo create: ${@:%=%}
	@${CC} ${CFLAGS} ${INCLUDES} -o $@ -c $<

clean:
	@${RM} ${OBJ_DIR}

fclean: clean
	@${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re