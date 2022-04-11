##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC     =	src/main.c								\
			src/mysh.c								\
			src/get_info/get_path.c					\
			src/get_info/get_prompt.c				\
			src/get_info/get_pwd.c					\
			src/exec_function/cd_function.c			\
			src/exec_function/env_function.c		\
			src/exec_function/exec_function.c		\
			src/exec_function/setenv_function.c		\
			src/exec_function/unsetenv_function.c	\
			src/exec_function/exit_function.c		\
			src/exec_function/exec_redirection.c	\
			src/utils/utils.c						\
			src/utils/utils2.c						\
			src/utils/utils3.c						\
			src/utils/key_utils.c					\
			src/utils/free_utils.c					\
			src/utils/redirection_utils.c			\
			src/utils/redirection_type_utils.c		\
			src/utils/redirection_filename_utils.c	\
			src/create/create_key.c					\
			src/create/create_function.c			\
			src/check/check_error.c					\
			src/check/check_argument.c				\

OBJ     =	$(SRC:.c=.o)

NAME    =	mysh

TEST_NAME	=	unit_tests

CFLAGS	=	-Wall -Wextra

CPPFLAGS	= -I include

LDFLAGS	=	-L. -lmy

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my
	$(RM) $(NAME)

debug: CPPFLAGS	+= -g3
debug:	re

tests_run:	LDFLAGS += --coverage -lcriterion
tests_run:
	$(MAKE) -C lib/my
	$(CC) -o $(TEST_NAME) $(OBJ) $(LDFLAGS)
	./$(TEST_NAME)

re:	fclean all

.PHONY:	all clean fclean tests_run re debug
