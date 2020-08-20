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
    char *result = get_next_line(-1);

    cr_expect(result == NULL);
    if (result)
        free(result);
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

Test(get_next_line, check_for_last_line)
{
    char *result = NULL;
    char *expectations[] = {"Test", NULL};
    const int fd = open("../../tests/tests_libmy/tests_files/gnl_check_for_last_line", O_RDONLY);

    for (register size_t index = 0; index < 2; index += 1) {
        result = get_next_line(fd);
        if (my_str_eq_str(result, expectations[index]))
            cr_expect(1);
        else
            cr_expect(0);
        if (result)
            free(result);
    }
    close(fd);
}

Test(get_next_line, get_multiple_lines)
{
    char *result = NULL;
    char *expectations[] = {"12345678901234567", "890123", "456789012"};
    const int fd = open("../../tests/tests_libmy/tests_files/gnl_get_multiple_lines", O_RDONLY);

    for (register size_t index = 0; index < 3; index += 1) {
        result = get_next_line(fd);
        if (my_str_eq_str(result, expectations[index]))
            cr_expect(1);
        else
            cr_expect(0);
        if (result)
            free(result);
    }
    close(fd);
}

Test(get_next_line, last_line_return)
{
    char *result = NULL;
    char *expectations[] = {"Yes", "", NULL};
    const int fd = open("../../tests/tests_libmy/tests_files/gnl_last_line_return", O_RDONLY);

    for (register size_t index = 0; index < 3; index += 1) {
        result = get_next_line(fd);
        if (my_str_eq_str(result, expectations[index]))
            cr_expect(1);
        else
            cr_expect(0);
        if (result)
            free(result);
    }
    close(fd);
}

Test(get_next_line, empty_file)
{
    char *result = NULL;
    char *expectations[] = {NULL};
    const int fd = open("../../tests/tests_libmy/tests_files/gnl_empty_file", O_RDONLY);

    for (register size_t index = 0; index < 1; index += 1) {
        result = get_next_line(fd);
        if (my_str_eq_str(result, expectations[index]))
            cr_expect(1);
        else
            cr_expect(0);
        if (result)
            free(result);
    }
    close(fd);
}
