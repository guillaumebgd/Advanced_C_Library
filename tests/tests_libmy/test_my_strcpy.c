/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_strcpy() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strcpy, simple_copy)
{
    char template[] = "Iamnice";
    char buffer[8];

    my_strcpy(template, buffer);
    cr_assert_str_eq(template, buffer);
}

Test(my_strcpy, null_template)
{
    char template[] = "Iamnice";
    char buffer[8];

    memset(buffer, '\0', 8);
    my_strcpy(NULL, buffer);
    cr_expect(buffer[0] == '\0');
    cr_expect(buffer[1] == '\0');
    cr_expect(buffer[2] == '\0');
    cr_expect(buffer[3] == '\0');
    cr_expect(buffer[4] == '\0');
    cr_expect(buffer[5] == '\0');
    cr_expect(buffer[6] == '\0');
    cr_expect(buffer[7] == '\0');
}

Test(my_strncpy, normal_n_copy)
{
    char expected[] = "Iam";
    char template[] = "Iamnice";
    char buffer[4];

    my_strncpy(template, buffer, 3);
    cr_assert_str_eq(expected, buffer);
}

Test(my_strncpy, over_n_copy)
{
    char expected[] = "Iamnice";
    char template[] = "Iamnice";
    char buffer[20];

    my_strncpy(template, buffer, 30);
    cr_assert_str_eq(expected, buffer);
}

Test(my_strcpy_char, normal_copy_until_char)
{
    char expected[] = "Iam";
    char template[] = "Iamnice";
    char buffer[10];

    my_strcpy_char(template, buffer, 'n');
    cr_assert_str_eq(expected, buffer);
}

Test(my_strcpy_char, cant_find_copy_until_char)
{
    char expected[] = "Iamnice";
    char template[] = "Iamnice";
    char buffer[8];

    my_strcpy_char(template, buffer, 'w');
    cr_assert_str_eq(expected, buffer);
}
