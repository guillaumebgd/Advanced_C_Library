/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
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
