/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Tests the my_mass_str_eq_str() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_mass_str_eq_str, easy_test_match)
{
    cr_assert_eq(my_mass_str_eq_str(1, "test", "test"), true);
}

Test(my_mass_str_eq_str, hard_test_match)
{
    cr_assert_eq(my_mass_str_eq_str(3, "test", NULL, "", "test"), true);
}

Test(my_mass_str_eq_str, smaller_nb_args_than_real_nb_args_no_match)
{
    cr_assert_eq(my_mass_str_eq_str(2, "test", NULL, "", "test"), false);
}
