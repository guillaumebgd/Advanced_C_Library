/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** Tests the my_put_double() function.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_put_double, simple_decimal_print)
{
    const double nb = 19.12;

    cr_redirect_stdout();
    my_put_double(nb);
    cr_assert_stdout_eq("19.12");
}
