/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Checks whether a given string representing a file has a given extension.
*/

#include "my.h"

bool my_is_file_extension(const char *file, const char *extension)
{
    const ssize_t len_file = my_strlen(file);
    const ssize_t len_ext = my_strlen(extension);

    if (len_file < len_ext || !extension)
        return (false);
    return (my_str_eq_str(&file[len_file - len_ext], extension));
}
