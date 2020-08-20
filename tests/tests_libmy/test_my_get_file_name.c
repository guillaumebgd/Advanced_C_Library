/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_get_file_name() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_get_file_name, easy_file_name)
{
    char expected[] = "my_file.txt";
    char *result = NULL;

    result = my_get_file_name("/bin/users/gbogard/Desktop/my_file.txt");
    cr_expect_str_eq(expected, result);
    if (result)
        free(result);
}

Test(my_get_file_name, zero_given)
{
    char *result = NULL;

    result = my_get_file_name("");
    cr_expect_str_eq(result, "");
    if (result)
        free(result);
}

Test(my_get_file_name, null_given)
{
    char *result = NULL;

    result = my_get_file_name(NULL);
    cr_expect(result == NULL);
    if (result)
        free(result);
}
