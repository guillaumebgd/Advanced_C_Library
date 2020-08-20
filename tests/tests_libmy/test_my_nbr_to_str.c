/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_nbr_to_str() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_nbr_to_str, easy_positive_int_to_str)
{
    char expected[] = "102";
    char *result = my_nbr_to_str(102);

    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_nbr_to_str, easy_negative_int_to_str)
{
    char expected[] = "-158";
    char *result = my_nbr_to_str(-158);

    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_nbr_to_str, hard_zero_int_to_str)
{
    char expected[] = "0";
    char *result = my_nbr_to_str(0);

    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_nbr_to_str, hard_max_int_to_str)
{
    char expected[] = "2147483647";
    char *result = my_nbr_to_str(2147483647);

    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_nbr_to_str, hard_min_int_to_str)
{
    char expected[] = "-2147483648";
    char *result = my_nbr_to_str(-2147483648);

    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}
