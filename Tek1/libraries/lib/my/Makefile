##
## EPITECH PROJECT, 2019
## GuillaumeBgd - my_libraries
## File description:
## Makefile use for libmy compilation
##

SRC					=	my_match_shell.c						\
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

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY: all clean fclean re