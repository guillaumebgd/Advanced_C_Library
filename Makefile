##
## EPITECH PROJECT, 2020
## GuillaumeBgd - Advanced_C_Library
## File description:
## Makefile use for Advanced_C_Library compilation
##

SRC_LIBMY	=	lib/my/

all:
	$(MAKE) -C $(SRC_LIBMY)

debug:
	$(MAKE) debug -C $(SRC_LIBMY)

tests_run:
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	-$(MAKE) tests_run -C $(SRC_LIBMY)
	find -name "test_*.gcda" -delete
	find -name "test_*.gcno" -delete

coverage: tests_run
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete

clean:
	$(RM) -rf $(UNIT_TESTS_BINARY)
	$(RM) -rf $(TEST_COVERAGE_DIR)
	@find -name "*.gcda" -delete
	@find -name "*.gcno" -delete
	$(MAKE) clean -C $(SRC_LIBMY)

fclean: clean
	$(MAKE) fclean -C $(SRC_LIBMY)

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re
