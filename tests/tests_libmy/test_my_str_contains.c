/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_str_contains() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_contains, easy_find_true)
{
    cr_assert_eq(my_str_contains("Test", 't'), true);
}

Test(my_str_contains, easy_not_found_false)
{
    cr_assert_eq(my_str_contains("Test", 'a'), false);
}

Test(my_str_contains, null_string_false)
{
    cr_assert_eq(my_str_contains(NULL, 't'), false);
}

Test(my_str_contains, null_character_false)
{
    cr_assert_eq(my_str_contains("Test", -1), false);
}

Test(my_str_contains, null_char_true)
{
    cr_assert_eq(my_str_contains("Test", '\0'), true);
}

Test(my_str_contains, all_null_false)
{
    cr_assert_eq(my_str_contains(NULL, '\0'), false);
}
