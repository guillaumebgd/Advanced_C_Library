/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Tests the my_match_shell() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_match_shell, no_wildcard_that_match)
{
    cr_assert_eq(my_match_shell("similar", "similar"), true);
}

Test(my_match_shell, no_wildcard_that_dont_match)
{
    cr_assert_eq(my_match_shell("not_similar", "accurate"), false);
}

Test(my_match_shell, one_any_str_wildcard)
{
    cr_assert_eq(my_match_shell("*", "similar"), true);
}
