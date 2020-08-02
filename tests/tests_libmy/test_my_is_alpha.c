/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_is_alpha() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_is_alpha, easy_test_true)
{
    cr_assert_eq(my_is_alpha('c'), true);
}

Test(my_is_alpha, edgy_test_true)
{
    cr_assert_eq(my_is_alpha('a'), true);
}

Test(my_is_alpha, easy_test_false)
{
    cr_assert_eq(my_is_alpha('1'), false);
}
