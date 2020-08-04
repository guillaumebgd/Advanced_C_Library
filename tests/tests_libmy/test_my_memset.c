/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_memset() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_memset, easy_memset)
{
    char buffer[32];
    char expected[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    buffer[31] = '\0';
    my_memset(buffer, 'a', 31);
    cr_assert_str_eq(buffer, expected);
}
