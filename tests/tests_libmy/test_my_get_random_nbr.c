/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_get_random_nbr() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_get_random_nbr, easy_random_nbr)
{
    register size_t i = 0;
    ssize_t nb = 0;

    do {
        nb = my_get_random_nbr(1, 10);
        cr_assert_geq(nb, 1);
        cr_assert_leq(nb, 10);
        i += 1;
    } while (i < 200);
}

Test(my_get_random_nbr, hard_random_nbr)
{
    register size_t i = 0;
    ssize_t nb = 0;

    do {
        nb = my_get_random_nbr(-3, 10);
        cr_assert_geq(nb, -3);
        cr_assert_leq(nb, 10);
        i += 1;
    } while (i < 200);
}

Test(my_get_random_nbr, hard_random_nbr_pot_crash)
{
    register size_t i = 0;
    ssize_t nb = 0;

    do {
        nb = my_get_random_nbr(3, 3);
        cr_assert_geq(nb, 3);
        cr_assert_leq(nb, 3);
        i += 1;
    } while (i < 200);
}
