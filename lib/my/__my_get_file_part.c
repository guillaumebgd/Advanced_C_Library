/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Gets parts from a file destination string.
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
    return (my_strndup(file_with_path, (size_t)(index + 1)));
}
