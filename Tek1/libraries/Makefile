##
## EPITECH PROJECT, 2020
## GuillaumeBgd - my_libraries
## File description:
## Makefile use for my_libraries compilation
##

SRC_LIBMY			=	lib/my										\

TESTS_LIBMY			=	tests/tests_libmy/test_my_match_shell.c		\
						tests/tests_libmy/test_my_strlen.c			\

NAME_LIBMY			=	-lmy										\

CRITERION_FLAGS		=	-lcriterion --coverage						\

override LDFLAGS	+=	-L./lib										\

override LDLIBS		+=	$(CRITERION_FLAGS)							\
						$(NAME_LIBMY)								\

override CPPFLAGS	+=	-I ./include/my								\

RM					=	rm -rf										\

MV					=	mv											\

MKDIR				=	mkdir										\

MAKE				=	make										\

CC					=	gcc											\

TESTS_DIR			=	tests/										\

COVERAGE_DIR		=	coverage/									\

UNIT_TESTS_BINARY	=	unit_tests									\

all:
	$(MAKE) -C $(SRC_LIBMY)

tests_run:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(MAKE) -C $(SRC_LIBMY)
	$(CC) -o $(UNIT_TESTS_BINARY) $(TESTS_LIBMY) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./$(UNIT_TESTS_BINARY)
	$(MKDIR) -p $(COVERAGE_DIR)
	$(MV) *.gcda $(COVERAGE_DIR)
	$(MV) *.gcno $(COVERAGE_DIR)
	$(RM) $(UNIT_TESTS_BINARY)

coverage:
	gcovr --exclude $(TESTS_DIR)
	gcovr --exclude $(TESTS_DIR) --branches

clean:
	$(MAKE) clean -C $(SRC_LIBMY)

fclean:
	$(MAKE) fclean -C $(SRC_LIBMY)
	$(RM) $(COVERAGE_DIR)

re:	fclean all

.NOTPARALLEL:
.PHONY: all tests_run coverage clean fclean re
