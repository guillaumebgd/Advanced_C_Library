/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_strcat() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strcat, easy_concat)
{
    char *first = my_strdup("steam");
    char *second = my_strdup("engine");
    char *result = NULL;
    char expected[] = "steamengine";

    result = my_strcat(first, second, FREE_BOTH);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}
