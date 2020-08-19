/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the get_next_line() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(get_next_line, wrong_file_descriptor_null)
{
    cr_assert_eq(get_next_line(-1), NULL);
}

Test(get_next_line, basic_normal_file_easy_line_true)
{
    char *result = NULL;
    char expected[] = "/*";
    const int fd = open("__my_putchar.c", O_RDONLY);

    result = get_next_line(fd);
    close(fd);
    cr_expect_str_eq(result, expected);
    if (result)
        free(result);
}
