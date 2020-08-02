/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Tests the my_match_shell() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_match_shell, first_null_no_match)
{
    cr_assert_eq(my_match_shell(NULL, "not_similar"), false);
}

Test(my_match_shell, first_null_second_null_match)
{
    cr_assert_eq(my_match_shell(NULL, NULL), true);
}

Test(my_match_shell, second_null_no_match)
{
    cr_assert_eq(my_match_shell("test", NULL), false);
}

Test(my_match_shell, one_any_str_second_null_match)
{
    cr_assert_eq(my_match_shell("*", NULL), true);
}

Test(my_match_shell, several_any_str_second_null_match)
{
    cr_assert_eq(my_match_shell("****", NULL), true);
}

Test(my_match_shell, one_any_char_second_null_no_match)
{
    cr_assert_eq(my_match_shell("?", NULL), false);
}

Test(my_match_shell, several_any_char_second_null_no_match)
{
    cr_assert_eq(my_match_shell("??", NULL), false);
}

Test(my_match_shell, first_empty_no_match)
{
    cr_assert_eq(my_match_shell("", "not_similar"), false);
}

Test(my_match_shell, first_empty_second_empty_match)
{
    cr_assert_eq(my_match_shell("", ""), true);
}

Test(my_match_shell, second_empty_no_match)
{
    cr_assert_eq(my_match_shell("test", ""), false);
}

Test(my_match_shell, one_any_str_second_empty_match)
{
    cr_assert_eq(my_match_shell("*", ""), true);
}

Test(my_match_shell, several_any_str_second_empty_match)
{
    cr_assert_eq(my_match_shell("****", ""), true);
}

Test(my_match_shell, one_any_char_second_empty_no_match)
{
    cr_assert_eq(my_match_shell("?", ""), false);
}

Test(my_match_shell, several_any_char_second_empty_no_match)
{
    cr_assert_eq(my_match_shell("??", ""), false);
}

Test(my_match_shell, no_wildcard_match)
{
    cr_assert_eq(my_match_shell("similar", "similar"), true);
}

Test(my_match_shell, no_wildcard_no_match)
{
    cr_assert_eq(my_match_shell("not_similar", "accurate"), false);
}

Test(my_match_shell, one_any_str_wildcard_match)
{
    cr_assert_eq(my_match_shell("*", "similar"), true);
}

Test(my_match_shell, several_any_str_wildcard_match)
{
    cr_assert_eq(my_match_shell("***", "similar"), true);
}

Test(my_match_shell, one_any_char_wild_card_match)
{
    cr_assert_eq(my_match_shell("?", "a"), true);
}

Test(my_match_shell, one_any_char_wild_card_no_match)
{
    cr_assert_eq(my_match_shell("?", "la"), false);
}

Test(my_match_shell, several_any_char_wild_card_match)
{
    cr_assert_eq(my_match_shell("???", "src"), true);
}

Test(my_match_shell, several_any_char_wild_card_no_match)
{
    cr_assert_eq(my_match_shell("???", "tests"), false);
}

Test(my_match_shell, mix_any_str_any_char_match)
{
    cr_assert_eq(my_match_shell("*e?t*", "tests"), true);
}

Test(my_match_shell, mix_any_str_any_char_no_match)
{
    cr_assert_eq(my_match_shell("*e?t*p", "tests"), false);
}
