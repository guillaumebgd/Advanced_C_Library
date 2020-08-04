/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_str_contains_index() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_contains_index, easy_find_true)
{
    cr_assert_eq(my_str_contains_index("Test", 't'), 3);
}

Test(my_str_contains_index, easy_not_found_false)
{
    cr_assert_eq(my_str_contains_index("Test", 'a'), -1);
}

Test(my_str_contains_index, null_string_false)
{
    cr_assert_eq(my_str_contains_index(NULL, 't'), -1);
}

Test(my_str_contains_index, null_character_false)
{
    cr_assert_eq(my_str_contains_index("Test", '\0'), -1);
}

Test(my_str_contains_index, all_null_false)
{
    cr_assert_eq(my_str_contains_index(NULL, '\0'), -1);
}
