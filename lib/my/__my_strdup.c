/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Copies characters from a string onto another that is being malloc'd.
*/

#include "my.h"

char *__my_strdup(const char *template, const ssize_t c, const size_t _m)
{
    char *dest = NULL;
    const ssize_t len_template = __my_strlen(template, c, _m);

    if (len_template < 0)
        return (NULL);
    dest = malloc(sizeof(char) * (len_template + 1));
    if (!dest)
        return (NULL);
    __my_strcpy(template, dest, c, _m);
    return (dest);
}