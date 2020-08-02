##
## Personnal C Library
## GuillaumeBgd - Advanced_C_Library
## File description:
## Makefile use for libmy compilation
##

SRC					=	__match.c								\
						__my_put_double.c						\
						__my_put_nbr_u.c						\
						__my_put_nbr.c							\
						__my_putchar.c							\
						my_is_alpha.c							\
						my_is_num.c								\
						my_mass_eq.c							\
						my_mass_str_eq_str.c					\
						my_strlen.c								\

override CFLAGS		=	-Wall -Wextra							\

override CPPFLAGS	+=	-I ./../../include/my					\

OBJ					=	$(SRC:.c=.o)							\

NAME				=	libmy.a									\

CP					=	cp										\

AR					=	ar										\

OBJ					=	$(SRC:.c=.o)							\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	$(CP) -u $(NAME) ../

debug:
	$(CC) -g -o ../../$@ ../../main.c $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../../debug
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all debug clean fclean re
