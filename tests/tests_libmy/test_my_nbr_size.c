/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_nbr_size() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_int_size, int_tests)
{
    const int max_int = ~(1 << (sizeof(int) * 8 - 1));
    const int min_int = max_int + 1;

    cr_expect_eq(my_int_size((int)1), 1);
    cr_expect_eq(my_int_size((int)0), 1);
    cr_expect_eq(my_int_size((int)1234), 4);
    cr_expect_eq(my_int_size((int)-1), 1);
    cr_expect_eq(my_int_size((int)-1234), 4);
    cr_expect_eq(my_int_size(max_int), 10);
    cr_expect_eq(my_int_size(min_int), 10);
}

Test(my_long_int_size, lint_tests)
{
    const long int max_lint = ~(1L << (sizeof(long int) * 8 - 1));
    const long int min_lint = max_lint + 1;

    cr_expect_eq(my_long_int_size((long int)1), 1);
    cr_expect_eq(my_long_int_size((long int)0), 1);
    cr_expect_eq(my_long_int_size((long int)1234), 4);
    cr_expect_eq(my_long_int_size((long int)-1), 1);
    cr_expect_eq(my_long_int_size((long int)-1234), 4);
    cr_expect_eq(my_long_int_size(max_lint), 19);
    cr_expect_eq(my_long_int_size(min_lint), 19);
}

Test(my_long_long_int_size, llint_tests)
{
    const long long int max_llint = ~(1LL << (sizeof(long long int) * 8 - 1));
    const long long int min_llint = max_llint + 1;

    cr_expect_eq(my_long_long_int_size((long long int)1), 1);
    cr_expect_eq(my_long_long_int_size((long long int)0), 1);
    cr_expect_eq(my_long_long_int_size((long long int)1234), 4);
    cr_expect_eq(my_long_long_int_size((long long int)-1), 1);
    cr_expect_eq(my_long_long_int_size((long long int)-1234), 4);
    cr_expect_eq(my_long_long_int_size(max_llint), 19);
    cr_expect_eq(my_long_long_int_size(min_llint), 19);
}

Test(my_ssize_t_size, ssize_t_tests)
{
    const ssize_t max_ssize_t = ~((ssize_t)1 << (sizeof(ssize_t) * 8 - 1));
    const ssize_t min_ssize_t = max_ssize_t + 1;

    cr_expect_eq(my_ssize_t_size((ssize_t)1), 1);
    cr_expect_eq(my_ssize_t_size((ssize_t)0), 1);
    cr_expect_eq(my_ssize_t_size((ssize_t)1234), 4);
    cr_expect_eq(my_ssize_t_size((ssize_t)-1), 1);
    cr_expect_eq(my_ssize_t_size((ssize_t)-1234), 4);
    cr_expect_eq(my_ssize_t_size(max_ssize_t), 19);
    cr_expect_eq(my_ssize_t_size(min_ssize_t), 19);
}

Test(my_uint_size, uint_tests)
{
    const unsigned int max_uint = ~(1U << (sizeof(unsigned int) * 8 - 1));

    cr_expect_eq(my_uint_size((int)1), 1);
    cr_expect_eq(my_uint_size((int)0), 1);
    cr_expect_eq(my_uint_size((int)1234), 4);
    cr_expect_eq(my_uint_size(max_uint), 10);
}

Test(my_long_uint_size, luint_tests)
{
    const long unsigned int max_luint = ~(1UL << (sizeof(long unsigned int) * 8 - 1));

    cr_expect_eq(my_long_uint_size((long int)1), 1);
    cr_expect_eq(my_long_uint_size((long int)0), 1);
    cr_expect_eq(my_long_uint_size((long int)1234), 4);
    cr_expect_eq(my_long_uint_size(max_luint), 19);
}

Test(my_long_long_uint_size, llint_tests)
{
    const long long unsigned int max_lluint = ~(1ULL << (sizeof(long long unsigned int) * 8 - 1));

    cr_expect_eq(my_long_long_uint_size((long long int)1), 1);
    cr_expect_eq(my_long_long_uint_size((long long int)0), 1);
    cr_expect_eq(my_long_long_uint_size((long long int)1234), 4);
    cr_expect_eq(my_long_long_uint_size(max_lluint), 19);
}

Test(my_size_t_size, size_t_tests)
{
    const size_t max_size_t = ~((size_t)1 << (sizeof(size_t) * 8 - 1));

    cr_expect_eq(my_size_t_size((size_t)1), 1);
    cr_expect_eq(my_size_t_size((size_t)0), 1);
    cr_expect_eq(my_size_t_size((size_t)1234), 4);
    cr_expect_eq(my_size_t_size(max_size_t), 19);
}
