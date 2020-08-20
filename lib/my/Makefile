##
## Personnal C Library
## GuillaumeBgd - Advanced_C_Library
## File description:
## Makefile use for libmy compilation
##

ROOT_DIR_PATH	=	../../

LIB_DIR_PATH	=	../

SRC_TESTS_LOCATION	=	$(addprefix $(ROOT_DIR_PATH), tests/tests_libmy/)

UNIT_TESTS_BINARY	=	$(addprefix $(ROOT_DIR_PATH), unit_tests)

MAIN	=	$(addprefix $(ROOT_DIR_PATH), main.c)

SRC	=	__my_convert_base.c	\
		__my_get_file_part.c	\
		__my_get_nbr.c	\
		__my_match.c	\
		__my_nbr_size.c	\
		__my_nbr_to_str.c	\
		__my_put_nbr.c	\
		__my_putchar.c	\
		__my_str_contains.c	\
		__my_strcpy.c	\
		__my_strdup.c	\
		__my_strlen.c	\
		get_next_line.c	\
		my_get_random_nbr.c	\
		my_is_alpha.c	\
		my_is_file_extension.c	\
		my_is_num.c	\
		my_mass_eq.c	\
		my_mass_str_eq_str.c	\
		my_memset.c	\
		my_strcat.c

SRC_TESTS	=	$(addprefix $(SRC_TESTS_LOCATION), test_get_next_line.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_convert_base.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_get_file_name.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_get_file_path.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_get_nbr.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_get_random_nbr.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_is_alpha.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_is_alphanum.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_is_file_extension.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_is_num.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_mass_eq.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_mass_str_eq_str.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_match_shell.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_match.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_memset.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_nbr_size.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_nbr_to_str.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_put_nbr.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_put_unsigned_nbr.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_putchar.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_str_contains.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_str_contains_index.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_str_contains_list.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_str_eq_str.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_strcat.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_strcpy.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_strdup.c)	\
				$(addprefix $(SRC_TESTS_LOCATION), test_my_strlen.c)	\

override CFLAGS	=	-Wall -Wextra

override CPPFLAGS	+=	-I $(addprefix $(ROOT_DIR_PATH), include/my/)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MV	=	mv

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	$(MV) $(NAME) $(LIB_DIR_PATH)

debug:
	$(CC) -g -o $(ROOT_DIR_PATH)$@ $(MAIN) $(SRC) $(CPPFLAGS)

tests_run:
	$(CC) -o $(UNIT_TESTS_BINARY) $(SRC) $(SRC_TESTS) $(CPPFLAGS) -lcriterion --coverage
	-./$(UNIT_TESTS_BINARY)
	-$(RM) $(UNIT_TESTS_BINARY)

clean:
	$(RM) $(OBJ)

fclean:	clean
	-$(RM) $(ROOT_DIR_PATH)debug
	-$(RM) $(NAME)
	-$(RM) $(LIB_DIR_PATH)$(NAME)

re:	fclean all

.PHONY: all debug clean fclean re
