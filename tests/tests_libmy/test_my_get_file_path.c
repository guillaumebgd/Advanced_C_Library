/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_get_file_path() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_get_file_path, easy_path)
{
    char expected[] = "/bin/users/gbogard/Desktop/";
    char *result = NULL;

    result = my_get_file_path("/bin/users/gbogard/Desktop/my_file.txt");
    cr_expect_str_eq(expected, result);
    if (result)
        free(result);
}
