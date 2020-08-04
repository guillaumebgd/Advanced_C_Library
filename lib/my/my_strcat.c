/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Concatenates two strings.
*/

#include "my.h"

static void free_concatenated(char *first, char *second, const size_t free_opt)
{
    if ((free_opt & FREE_FIRST) && first)
        free(first);
    if ((free_opt & FREE_SECOND) && second)
        free(second);
}

char *my_strcat(char *first, char *second, const size_t free_opt)
{
    char *result = NULL;
    const ssize_t len_first = my_strlen(first);
    const ssize_t len_second = my_strlen(second);
    const ssize_t len_result = len_first + len_second;

    if (!first || !second) {
        result = my_strdup((first) ? first : second);
        goto end;
    }
    result = malloc(sizeof(char) * (len_result + 1));
    if (!result)
        goto end;
    my_strcpy(first, result);
    my_strcpy(second, &result[len_first]);
    result[len_result] = '\0';
    end:
    free_concatenated(first, second, free_opt);
    return (result);
}