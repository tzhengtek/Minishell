##
## EPITECH PROJECT, 2021
## Maekfile
## File description:
## makefile
##

SRC     =	my_put_nbr.c			\
    		my_printf.c				\
			my_putchar.c			\
			my_putstr.c				\
			my_revstr.c				\
			my_strlen.c				\
			my_put_nbr_long.c		\
			my_printf2.c			\
			my_strcpy.c				\
			my_put_nbr_unsigned.c	\
			my_printf3.c			\
			my_printf4.c			\
			my_getnbr.c				\
			my_compute_power_it.c	\
			my_strcat.c				\
			my_strcmp.c				\
			open_file.c				\
			convert_base.c			\
			int_to_char.c			\
			my_memset.c				\
			my_strdup.c				\
			my_str_isnum.c			\
			my_str_isalpha.c		\
			print_error.c			\
			my_putarr.c				\
			str_to_array.c

OBJ	=		$(SRC:.c=.o)

NAME	=	libmy.a

all:	libmy.a

libmy.a:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../..

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../../$(NAME)

re:	fclean libmy.a
