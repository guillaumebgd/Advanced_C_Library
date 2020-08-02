/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_is_alphanumnum() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_is_alphanum, easy_test_true)
{
    cr_assert_eq(my_is_alphanum('a'), true);
}

Test(my_is_alphanum, edgy_test_true)
{
    cr_assert_eq(my_is_alphanum('1'), true);
}

Test(my_is_alphanum, easy_test_false)
{
    cr_assert_eq(my_is_alphanum(':'), false);
}
