/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Tests the my_is_num() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_is_num, easy_test_true)
{
    cr_assert_eq(my_is_num('1'), true);
}

Test(my_is_num, edgy_test_true)
{
    cr_assert_eq(my_is_num('9'), true);
}

Test(my_is_num, easy_test_false)
{
    cr_assert_eq(my_is_num('z'), false);
}
