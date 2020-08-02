/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_strlen() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strlen, classic_string)
{
    cr_assert_eq(my_strlen("Four"), 4);
}

Test(my_strlen, empty_string)
{
    cr_assert_eq(my_strlen(""), 0);
}

Test(my_strlen, null_sent)
{
    cr_assert_eq(my_strlen(NULL), -1);
}
