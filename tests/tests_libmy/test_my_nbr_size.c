/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_nbr_size() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_nbr_size, int_tests)
{
    const int max_int = ~(1 << (sizeof(int) * 8 - 1));
    const int min_int = max_int + 1;

    cr_expect_eq(my_nbr_size((int)1), 1);
    cr_expect_eq(my_nbr_size((int)0), 1);
    cr_expect_eq(my_nbr_size((int)1234), 4);
    cr_expect_eq(my_nbr_size((int)-1), 1);
    cr_expect_eq(my_nbr_size((int)-1234), 4);
    cr_expect_eq(my_nbr_size(max_int), 10);
    cr_expect_eq(my_nbr_size(min_int), 10);
}

Test(my_nbr_size, long_int_tests)
{
    const long int max_long_int = ~(1L << (sizeof(long int) * 8 - 1));
    const long int min_long_int = max_long_int + 1;

    cr_expect_eq(my_nbr_size((long int)1), 1);
    cr_expect_eq(my_nbr_size((long int)0), 1);
    cr_expect_eq(my_nbr_size((long int)1234), 4);
    cr_expect_eq(my_nbr_size((long int)-1), 1);
    cr_expect_eq(my_nbr_size((long int)-1234), 4);
    cr_expect_eq(my_nbr_size(max_long_int), 19);
    cr_expect_eq(my_nbr_size(min_long_int), 19);
}

Test(my_nbr_size, long_long_int_tests)
{
    const long long int max_long_long_int = ~(1LL << (sizeof(long long int) * 8 - 1));
    const long long int min_long_long_int = max_long_long_int + 1;

    cr_expect_eq(my_nbr_size((long long int)1), 1);
    cr_expect_eq(my_nbr_size((long long int)0), 1);
    cr_expect_eq(my_nbr_size((long long int)1234), 4);
    cr_expect_eq(my_nbr_size((long long int)-1), 1);
    cr_expect_eq(my_nbr_size((long long int)-1234), 4);
    cr_expect_eq(my_nbr_size(max_long_long_int), 19);
    cr_expect_eq(my_nbr_size(min_long_long_int), 19);
}

Test(my_nbr_size, ssize_t_tests)
{
    const ssize_t max_ssize_t = ~((ssize_t)1 << (sizeof(ssize_t) * 8 - 1));
    const ssize_t min_ssize_t = max_ssize_t + 1;

    cr_expect_eq(my_nbr_size((ssize_t)1), 1);
    cr_expect_eq(my_nbr_size((ssize_t)0), 1);
    cr_expect_eq(my_nbr_size((ssize_t)1234), 4);
    cr_expect_eq(my_nbr_size((ssize_t)-1), 1);
    cr_expect_eq(my_nbr_size((ssize_t)-1234), 4);
    cr_expect_eq(my_nbr_size(max_ssize_t), 19);
    cr_expect_eq(my_nbr_size(min_ssize_t), 19);
}

Test(my_unsigned_nbr_size, unsigned_int_tests)
{
    const unsigned int max_unsigned_int = ~(1U << (sizeof(unsigned int) * 8 - 1));

    cr_expect_eq(my_unsigned_nbr_size((unsigned int)1), 1);
    cr_expect_eq(my_unsigned_nbr_size((unsigned int)0), 1);
    cr_expect_eq(my_unsigned_nbr_size((unsigned int)1234), 4);
    cr_expect_eq(my_unsigned_nbr_size(max_unsigned_int), 10);
}

Test(my_unsigned_nbr_size, long_unsigned_int_tests)
{
    const long unsigned int max_long_unsigned_int = ~(1UL << (sizeof(long unsigned int) * 8 - 1));

    cr_expect_eq(my_unsigned_nbr_size((long unsigned int)1), 1);
    cr_expect_eq(my_unsigned_nbr_size((long unsigned int)0), 1);
    cr_expect_eq(my_unsigned_nbr_size((long unsigned int)1234), 4);
    cr_expect_eq(my_unsigned_nbr_size(max_long_unsigned_int), 19);
}

Test(my_unsigned_nbr_size, lluint_tests)
{
    const long long unsigned int max_long_long_unsigned_int = ~(1ULL << (sizeof(long long unsigned int) * 8 - 1));

    cr_expect_eq(my_unsigned_nbr_size((long long unsigned int)1), 1);
    cr_expect_eq(my_unsigned_nbr_size((long long unsigned int)0), 1);
    cr_expect_eq(my_unsigned_nbr_size((long long unsigned int)1234), 4);
    cr_expect_eq(my_unsigned_nbr_size(max_long_long_unsigned_int), 19);
}

Test(my_unsigned_nbr_size, size_t_tests)
{
    const size_t max_size_t = ~((size_t)1 << (sizeof(size_t) * 8 - 1));

    cr_expect_eq(my_unsigned_nbr_size((size_t)1), 1);
    cr_expect_eq(my_unsigned_nbr_size((size_t)0), 1);
    cr_expect_eq(my_unsigned_nbr_size((size_t)1234), 4);
    cr_expect_eq(my_unsigned_nbr_size(max_size_t), 19);
}

Test(my_nbr_size_binary, signed_binary_base)
{
    char expected[] = "1010";
    const ssize_t nb = 10;
    const size_t size = my_nbr_size_binary(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_nbr_size_octal, signed_octal_base)
{
    char expected[] = "226";
    const ssize_t nb = 150;
    const size_t size = my_nbr_size_octal(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_nbr_size_lower_hex, signed_lowercase_hexadecimal_base)
{
    char expected[] = "1F913";
    const ssize_t nb = 129299;
    const size_t size = my_nbr_size_lower_hex(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_nbr_size_upper_hex, signed_uppercase_hexadecimal_base)
{
    char expected[] = "2F19B";
    const ssize_t nb = 192923;
    const size_t size = my_nbr_size_upper_hex(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_nbr_size_base, signed_base)
{
    char expected[] = "FEFE";
    const ssize_t nb = 10;
    const size_t size = my_nbr_size_base(nb, "EF");

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_unsigned_nbr_size_binary, unsigned_binary_base)
{
    char expected[] = "1010";
    const size_t nb = 10;
    const size_t size = my_unsigned_nbr_size_binary(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_unsigned_nbr_size_octal, unsigned_octal_base)
{
    char expected[] = "226";
    const size_t nb = 150;
    const size_t size = my_unsigned_nbr_size_octal(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_unsigned_nbr_size_lower_hex, unsigned_lowercase_hexadecimal_base)
{
    char expected[] = "1F913";
    const size_t nb = 129299;
    const size_t size = my_unsigned_nbr_size_lower_hex(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_unsigned_nbr_size_upper_hex, unsigned_uppercase_hexadecimal_base)
{
    char expected[] = "2F19B";
    const size_t nb = 192923;
    const size_t size = my_unsigned_nbr_size_upper_hex(nb);

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_unsigned_nbr_size_base, unsigned_base)
{
    char expected[] = "FEFE";
    const size_t nb = 10;
    const size_t size = my_unsigned_nbr_size_base(nb, "EF");

    cr_assert_eq(size, my_strlen(expected));
}

Test(my_nbr_size_base, unary_base)
{
    const size_t nb = 10;
    const size_t size = my_unsigned_nbr_size_base(nb, "E");

    cr_assert_eq(size, 0);
}
