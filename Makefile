##
## EPITECH PROJECT, 2020
## bsg
## File description:
## libmy
##

MAIN		=	main.c
SRC			=	my_printf/my_printf.c		\
				my_printf/va_list_fct.c		\
				my_printf/va_list_nbrs_fct.c\
				my_printf/print_fcts.c		\
				my_printf/print_nbrs_fcts.c	\
				my_putchar.c				\
				my_putstr.c					\
				my_strlen.c					\
				my_put_nbr.c				\
				my_putnbr_base.c			\
				my_strcpy.c					\
				my_strdup.c					\
				my_strcmp.c
TESTS		=	./tests/tests.c
INC_DIR		=	./include/
CFLAGS 		+= -W -Wall -I$(INC_DIR)
MAIN_OBJ	=	$(MAIN:.c=.o)
OBJ			=	$(SRC:.c=.o)
TESTS_OBJ	=	$(TESTS:.c=.o)
NAME		=	libmy.a
NAME_MAIN	=	tests_main
NAME_TEST	=	tests_run

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -crs $(NAME) $(OBJ)

main:	$(NAME)	$(MAIN_OBJ)
	gcc -o $(NAME_MAIN) $(MAIN_OBJ) -I$(INC_DIR) -L. -lmy

tests_run:	CFLAGS += --coverage
tests_run:	clean	$(NAME)	$(TESTS_OBJ)
	gcc -o $(NAME_TEST) $(TESTS_OBJ) -I$(INC_DIR) -L. -lmy -lcriterion -lgcov
	./$(NAME_TEST)

clean:
	rm -rf $(OBJ)
	rm -f $(MAIN_OBJ)
	rm -rf $(TESTS_OBJ)
	rm -rf $(wildcard *.gcda)
	rm -rf $(wildcard **/*.gcda)
	rm -rf $(wildcard *.gcno)
	rm -rf $(wildcard **/*.gcno)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME_MAIN)
	rm -f $(NAME_TEST)

re: fclean all