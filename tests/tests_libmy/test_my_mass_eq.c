/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_mass_eq() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_str_eq_str, easy_test_match)
{
    cr_assert_eq(my_mass_eq(1, 1, 1), true);
}

Test(my_str_eq_str, easy_test_no_match)
{
    cr_assert_eq(my_mass_eq(1, 1, 2), false);
}

Test(my_str_eq_str, hard_test_match)
{
    cr_assert_eq(my_mass_eq(2, 0b1, 0b1000, 1 << 0), true);
}

Test(my_str_eq_str, hard_test_no_match)
{
    cr_assert_eq(my_mass_eq(2, 0b1, 0b1000, 1 << 1), false);
}
