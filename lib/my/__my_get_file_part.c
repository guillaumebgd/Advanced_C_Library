/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** Gets info from a given file whether with its indicated path or not.
*/

#include "my.h"

char *__my_get_file_part(const char *file_with_path, const size_t _m)
{
    register ssize_t index = 0;

    if (!file_with_path)
        return (NULL);
    index = my_strlen(file_with_path) - 1;
    for (; index >= 0 && file_with_path[index] != '/'; index -= 1);
    if (_m & GET_FILE_NAME)
        return (my_strdup(&file_with_path[(size_t)(index + 1)]));
    if (_m & GET_FILE_PATH)
        return (my_strndup(file_with_path, (size_t)(index + 1)));
    return (NULL);
}
