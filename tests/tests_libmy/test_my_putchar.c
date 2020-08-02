/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_putchar() function.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_putchar, simple_decimal_print)
{
    cr_redirect_stdout();
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_putchar, couldnt_print)
{
    cr_redirect_stdout();
    close(STDOUT_FILENO);
    cr_expect_eq(my_putchar('c'), false);
    cr_assert_stdout_neq_str("c");
}
