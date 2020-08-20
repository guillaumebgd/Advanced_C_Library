/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_convert_base() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_convert_base, easy_convertion)
{
    char expected[] = "1010";
    char *result = NULL;
    const char *nb = "10";

    result = my_convert_base(nb, DECIMAL_BASE, BINARY_BASE);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_convert_base, hard_convertion)
{
    char expected[] = "18EF1";
    char *result = NULL;
    const char *nb = "102129";

    result = my_convert_base(nb, DECIMAL_BASE, HEXADECIMAL_UPPERCASE_BASE);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_convert_base, multi_convertion)
{
    char expected[] = "A";
    char *result = NULL;
    const char *nb = "1010";

    result = my_convert_base(nb, BINARY_BASE, HEXADECIMAL_UPPERCASE_BASE);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}
