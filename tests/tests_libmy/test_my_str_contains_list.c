/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_str_contains_list() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_contains_list, easy_find_single_char_true)
{
    cr_assert_eq(my_str_contains_list("Test", "t"), true);
}

Test(my_str_contains_list, easy_find_several_chars_true)
{
    cr_assert_eq(my_str_contains_list("Test", "abct"), true);
}

Test(my_str_contains_list, easy_find_single_char_false)
{
    cr_assert_eq(my_str_contains_list("Test", "a"), false);
}

Test(my_str_contains_list, easy_find_several_chars_false)
{
    cr_assert_eq(my_str_contains_list("Test", "abc"), false);
}

Test(my_str_contains_list, null_str_false)
{
    cr_assert_eq(my_str_contains_list(NULL, "abc"), false);
}

Test(my_str_contains_list, null_list_false)
{
    cr_assert_eq(my_str_contains_list("Test", NULL), false);
}

Test(my_str_contains_list, all_null_false)
{
    cr_assert_eq(my_str_contains_list(NULL, NULL), false);
}
