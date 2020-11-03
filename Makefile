##
## EPITECH PROJECT, 2020
## bsg
## File description:
## libmy
##

MAIN		=	main.c
SRC			=	my_printf/my_printf.c		\
				my_printf/va_list_fct.c		\
				my_printf/print_fcts.c		\
				my_putchar.c				\
				my_putstr.c					\
				my_strlen.c					\
				my_put_nbr.c				\
				my_strcpy.c					\
				my_strdup.c					\
				my_str_isprintable.c
TESTS		=	tests.c
INC_DIR		=	./include/
CFLAGS		+=	-W -Wall -I$(INC_DIR)
MAIN_OBJ	=	$(MAIN:.c=.o)
OBJ			=	$(SRC:.c=.o)
TESTS_OBJ	=	$(TESTS:.c=.o)
NAME		=	libmy.a
NAME_MAIN	=	test_main
NAME_TEST	=	tests_run

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -crs $(NAME) $(OBJ)

main:	$(NAME)	$(MAIN_OBJ)
	gcc -o $(NAME_MAIN) $(MAIN_OBJ) -I$(INC_DIR) -L. -lmy

tests_run:	$(NAME)	$(TESTS_OBJ)
	gcc -o $(NAME_TEST) $(TESTS_OBJ) -I$(INC_DIR) -L. -lmy -lcriterion
	./$(NAME_TEST)

clean:
	rm -rf $(OBJ)
	rm -rf $(TESTS_OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)

re: fclean all