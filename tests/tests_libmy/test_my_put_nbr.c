/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_put_nbr() function.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_put_nbr, simple_positive_decimal_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr(10), 2);
    cr_assert_stdout_eq_str("10");
}

Test(__my_put_nbr, simple_positive_decimal_no_count)
{
    cr_redirect_stdout();
    cr_expect(__my_put_nbr(10, DECIMAL_BASE, SIGNED | NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
    cr_assert_stdout_eq_str("10");
}

Test(my_put_nbr, simple_negative_decimal_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr(-10), 3);
    cr_assert_stdout_eq_str("-10");
}

Test(__my_put_nbr, simple_negative_decimal_no_count)
{
    cr_redirect_stdout();
    cr_expect(__my_put_nbr(-10, DECIMAL_BASE, SIGNED | NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
    cr_assert_stdout_eq_str("-10");
}

Test(__my_put_nbr, simple_negative_decimal_count_wrong_fd)
{
    cr_redirect_stderr();
    cr_expect_eq(__my_put_nbr(-130, DECIMAL_BASE, SIGNED | COUNT_PRINTED_CHAR, -1), 0);
    cr_assert_stderr_neq_str("-130");
}

Test(__my_put_nbr, simple_negative_decimal_no_count_wrong_fd)
{
    cr_redirect_stderr();
    cr_expect_eq(__my_put_nbr(-130, DECIMAL_BASE, SIGNED | NO_COUNT_PRINTED_CHAR, -1), 0);
    cr_assert_stderr_neq_str("-130");
}

Test(my_put_nbr, hard_positive_decimal_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr(2147483647), 10);
    cr_assert_stdout_eq_str("2147483647");
}

Test(my_put_nbr, hard_positive_decimal_no_count)
{
    cr_redirect_stdout();
    cr_expect(__my_put_nbr(2147483647, DECIMAL_BASE, UNSIGNED | NO_COUNT_PRINTED_CHAR, STDOUT_FILENO));
    cr_assert_stdout_eq_str("2147483647");
}

Test(__my_put_nbr, hard_negative_decimal_no_count)
{
    cr_redirect_stdout();
    cr_expect(__my_put_nbr(-2147483648, DECIMAL_BASE, SIGNED | COUNT_PRINTED_CHAR, STDOUT_FILENO));
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_put_nbr_base, easy_positive_random_base_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr_base(10, "abcdefghij"), 2);
    cr_assert_stdout_eq_str("ba");
}

Test(my_put_nbr_base, unary_base)
{
    cr_expect_eq(my_put_nbr_base(10, "1"), 0);
}

Test(my_put_nbr_binary, easy_positive_binary_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr_binary(10), 4);
    cr_assert_stdout_eq_str("1010");
}

Test(my_put_nbr_octal, easy_positive_octal_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr_octal(10), 2);
    cr_assert_stdout_eq_str("12");
}

Test(my_put_nbr_lower_hex, easy_positive_lower_hex_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr_lower_hex(10), 1);
    cr_assert_stdout_eq_str("a");
}

Test(my_put_nbr_upper_hex, easy_positive_upper_hex_count)
{
    cr_redirect_stdout();
    cr_expect_eq(my_put_nbr_upper_hex(10), 1);
    cr_assert_stdout_eq_str("A");
}

Test(my_dput_nbr, easy_positive_decimal_fd_count)
{
    cr_redirect_stderr();
    my_dput_nbr(10, STDERR_FILENO);
    cr_assert_stderr_eq_str("10");
}

Test(my_dput_nbr_base, easy_positive_random_base_fd_count)
{
    cr_redirect_stderr();
    cr_expect_eq(my_dput_nbr_base(10, "abcdefghij", STDERR_FILENO), 2);
    cr_assert_stderr_eq_str("ba");
}

Test(my_dput_nbr_binary, easy_positive_binary_fd_count)
{
    cr_redirect_stderr();
    cr_expect_eq(my_dput_nbr_binary(10, STDERR_FILENO), 4);
    cr_assert_stderr_eq_str("1010");
}

Test(my_dput_nbr_octal, easy_positive_octal_fd_count)
{
    cr_redirect_stderr();
    cr_expect_eq(my_dput_nbr_octal(10, STDERR_FILENO), 2);
    cr_assert_stderr_eq_str("12");
}

Test(my_dput_nbr_lower_hex, easy_positive_lower_hex_fd_count)
{
    cr_redirect_stderr();
    cr_expect_eq(my_dput_nbr_lower_hex(10, STDERR_FILENO), 1);
    cr_assert_stderr_eq_str("a");
}

Test(my_dput_nbr_upper_hex, easy_positive_upper_hex_fd_count)
{
    cr_redirect_stderr();
    cr_expect_eq(my_dput_nbr_upper_hex(10, STDERR_FILENO), 1);
    cr_assert_stderr_eq_str("A");
}
