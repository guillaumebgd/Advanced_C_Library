/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_match() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_match, first_null_no_match)
{
    cr_assert_eq(my_match(NULL, "not_similar"), false);
}

Test(my_match, first_null_second_null_match)
{
    cr_assert_eq(my_match(NULL, NULL), true);
}

Test(my_match, second_null_no_match)
{
    cr_assert_eq(my_match("test", NULL), false);
}

Test(my_match, one_any_str_second_null_match)
{
    cr_assert_eq(my_match("*", NULL), true);
}

Test(my_match, several_any_str_second_null_match)
{
    cr_assert_eq(my_match("****", NULL), true);
}

Test(my_match, one_any_char_second_null_no_match)
{
    cr_assert_eq(my_match("?", NULL), false);
}

Test(my_match, several_any_char_second_null_no_match)
{
    cr_assert_eq(my_match("??", NULL), false);
}

Test(my_match, first_empty_no_match)
{
    cr_assert_eq(my_match("", "not_similar"), false);
}

Test(my_match, first_empty_second_empty_match)
{
    cr_assert_eq(my_match("", ""), true);
}

Test(my_match, second_empty_no_match)
{
    cr_assert_eq(my_match("test", ""), false);
}

Test(my_match, one_any_str_second_empty_match)
{
    cr_assert_eq(my_match("*", ""), true);
}

Test(my_match, several_any_str_second_empty_match)
{
    cr_assert_eq(my_match("****", ""), true);
}

Test(my_match, one_any_char_second_empty_no_match)
{
    cr_assert_eq(my_match("?", ""), false);
}

Test(my_match, several_any_char_second_empty_no_match)
{
    cr_assert_eq(my_match("??", ""), false);
}

Test(my_match, no_wildcard_match)
{
    cr_assert_eq(my_match("similar", "similar"), true);
}

Test(my_match, no_wildcard_no_match)
{
    cr_assert_eq(my_match("not_similar", "accurate"), false);
}

Test(my_match, one_any_str_wildcard_match)
{
    cr_assert_eq(my_match("*", "similar"), true);
}

Test(my_match, several_any_str_wildcard_match)
{
    cr_assert_eq(my_match("***", "similar"), true);
}

Test(my_match, one_any_char_wild_card_no_match)
{
    cr_assert_eq(my_match("?", "a"), false);
}

Test(my_match, several_any_char_wild_card_no_match)
{
    cr_assert_eq(my_match("???", "src"), false);
}

Test(my_match, mix_any_str_any_char_no_match)
{
    cr_assert_eq(my_match("*e?t*", "tests"), false);
}
