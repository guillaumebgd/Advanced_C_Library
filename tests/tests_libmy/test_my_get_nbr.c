/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_get_nbr() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_get_nbr, valid_easy_get_nbr)
{
    const ssize_t nb = my_get_nbr("-10");

    cr_assert_eq(nb, -10);
}

Test(my_get_unsigned_nbr, valid_easy_get_unsigned_nbr)
{
    const ssize_t nb = my_get_nbr("10");

    cr_assert_eq(nb, 10);
}

Test(my_get_nbr, valid_hard_get_nbr)
{
    const ssize_t nb = my_get_nbr("+-++---10");

    cr_assert_eq(nb, 10);
}

Test(my_get_nbr, invalid_easy_get_nbr)
{
    const ssize_t nb = my_get_nbr("a10");

    cr_assert_eq(nb, 0);
}

Test(my_get_nbr, invalid_hard_get_nbr)
{
    const ssize_t nb = my_get_nbr("++--a10");

    cr_assert_eq(nb, 0);
}

Test(__my_get_nbr, one_neg_sign_true)
{
    const ssize_t nb = __my_get_nbr("-109", DECIMAL_BASE, ONE_NEG_SIGN | SIGNED);

    cr_assert_eq(nb, -109);
}

Test(__my_get_nbr, one_neg_sign_false)
{
    const ssize_t nb = __my_get_nbr("--109", DECIMAL_BASE, ONE_NEG_SIGN | SIGNED);

    cr_assert_eq(nb, 0);
}

Test(__my_get_nbr, one_pos_sign_false)
{
    const ssize_t nb = __my_get_nbr("+109", DECIMAL_BASE, ONE_NEG_SIGN | SIGNED);

    cr_assert_eq(nb, 0);
}

Test(__my_get_nbr, unary_base)
{
    const ssize_t nb = __my_get_nbr("10", "1", ONE_NEG_SIGN | SIGNED);

    cr_assert_eq(nb, 0);
}

Test(__my_get_nbr, null_pointer_given)
{
    const ssize_t nb = __my_get_nbr(NULL, DECIMAL_BASE, ONE_NEG_SIGN | SIGNED);

    cr_assert_eq(nb, 0);
}
