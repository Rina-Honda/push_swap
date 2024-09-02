NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
# SANITIZE = -fsanitize=address	# !! segvチェック用(leaksチェック時は外す)

SRC =	ft_main.c \
		ft_parse_args.c \
		ft_stack_add_back.c \
		ft_new_node.c \
		ft_rotate_case_ab.c \
		ft_rotate_case_ba.c \
		ft_rotate_apply.c \
		ft_rotate_type.c \
		ft_stack_push.c \
		ft_stack_swap.c \
		ft_stack_rotate.c \
		ft_stack_rev_rotate.c \
		ft_checkdup.c \
		ft_checksorted.c \
		ft_error.c \
		ft_free.c \
		ft_stack_utils.c \
		ft_stack_utils2.c \
		ft_sort.c \
		ft_sort_three.c \
		ft_atoi.c \
		ft_putchar.c \
		ft_split.c

OBJ = ${SRC:.c=.o}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${SANITIZE}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME} ${SANITIZE}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


