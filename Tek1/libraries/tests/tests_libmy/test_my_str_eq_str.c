/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Tests the my_str_eq_str() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_eq_str, classic_strings_match)
{
    cr_assert_eq(my_str_eq_str("test", "test"), true);
}

Test(my_str_eq_str, first_null_no_match)
{
    cr_assert_eq(my_str_eq_str(NULL, "test"), false);
}

Test(my_str_eq_str, first_null_second_null_match)
{
    cr_assert_eq(my_str_eq_str(NULL, NULL), true);
}

Test(my_str_eq_str, second_null_no_match)
{
    cr_assert_eq(my_str_eq_str("test", NULL), false);
}
