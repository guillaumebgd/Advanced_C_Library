/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_strdup() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strdup, simple_dup)
{
    char *expected = "Test";
    char *result = NULL;

    result = my_strdup(expected);
    cr_expect_str_eq(result, expected);
    cr_expect_neq(expected, result);
    if (result)
        free(result);
}

Test(my_strdup, zero_given)
{
    char *expected = "";
    char *result = NULL;

    result = my_strdup(expected);
    cr_expect_str_eq(result, expected);
    cr_expect_neq(expected, result);
    if (result)
        free(result);
}

Test(my_strdup, null_given)
{
    char *result = NULL;

    result = my_strdup(NULL);
    cr_expect(result == NULL);
    if (result)
        free(result);
}

Test(my_strndup, normal_ndup)
{
    char *expected = "Tes";
    char *template = "Tester";
    char *result = NULL;

    result = my_strndup(template, 3);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}

Test(my_strdup_char, normal_dup_until_char)
{
    char *expected = "Teste";
    char *template = "Tester";
    char *result = NULL;

    result = my_strdup_char(template, 'r');
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}
