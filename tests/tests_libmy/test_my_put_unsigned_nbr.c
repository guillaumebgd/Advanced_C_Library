/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_put_unsigned_nbr() function.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_put_unsigned_nbr, simple_decimal_print)
{
    cr_redirect_stdout();
    my_put_unsigned_nbr(10);
    cr_assert_stdout_eq_str("10");
}

Test(my_put_unsigned_nbr_base, simple_base_print)
{
    cr_redirect_stdout();
    my_put_unsigned_nbr_base(10, "abcdefghij");
    cr_assert_stdout_eq_str("ba");
}

Test(my_put_unsigned_nbr_binary, simple_binary_print)
{
    cr_redirect_stdout();
    my_put_unsigned_nbr_binary(10);
    cr_assert_stdout_eq_str("1010");
}

Test(my_put_unsigned_nbr_octal, simple_octal_print)
{
    cr_redirect_stdout();
    my_put_unsigned_nbr_octal(10);
    cr_assert_stdout_eq_str("12");
}

Test(my_put_unsigned_nbr_lower_hex, simple_lower_hexa_print)
{
    cr_redirect_stdout();
    my_put_unsigned_nbr_lower_hex(10);
    cr_assert_stdout_eq_str("a");
}

Test(my_put_unsigned_nbr_upper_hex, simple_upper_hexa_print)
{
    cr_redirect_stdout();
    my_put_unsigned_nbr_upper_hex(10);
    cr_assert_stdout_eq_str("A");
}

Test(my_dput_unsigned_nbr, simple_err_decimal_print)
{
    cr_redirect_stderr();
    my_dput_unsigned_nbr(10, STDERR_FILENO);
    cr_assert_stderr_eq_str("10");
}

Test(my_dput_unsigned_nbr_base, simple_base_print)
{
    cr_redirect_stderr();
    my_dput_unsigned_nbr_base(10, "abcdefghij", STDERR_FILENO);
    cr_assert_stderr_eq_str("ba");
}

Test(my_dput_unsigned_nbr_binary, simple_binary_print)
{
    cr_redirect_stderr();
    my_dput_unsigned_nbr_binary(10, STDERR_FILENO);
    cr_assert_stderr_eq_str("1010");
}

Test(my_dput_unsigned_nbr_octal, simple_octal_print)
{
    cr_redirect_stderr();
    my_dput_unsigned_nbr_octal(10, STDERR_FILENO);
    cr_assert_stderr_eq_str("12");
}

Test(my_dput_unsigned_nbr_lower_hex, simple_lower_hexa_print)
{
    cr_redirect_stderr();
    my_dput_unsigned_nbr_lower_hex(10, STDERR_FILENO);
    cr_assert_stderr_eq_str("a");
}

Test(my_dput_unsigned_nbr_upper_hex, simple_upper_hexa_print)
{
    cr_redirect_stderr();
    my_dput_unsigned_nbr_upper_hex(10, STDERR_FILENO);
    cr_assert_stderr_eq_str("A");
}