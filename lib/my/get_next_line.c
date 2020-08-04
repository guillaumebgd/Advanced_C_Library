/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Gets the next line of a file.
*/

#include "my.h"

static void read_new_line(char **new_line, const int fd)
{
    bool done = false;
    char buffer[33];
    ssize_t size = 0;

    while (!done && !my_str_contains(*new_line, '\n')) {
        my_memset(buffer, '\0', 33);
        size = read(fd, buffer, 32);
        if (size <= 0 || size != 32)
            done = true;
        if (size == 0)
            return;
        (*new_line) = my_strcat((*new_line), buffer, FREE_FIRST);
    }
}

static bool reassign_string_pointers(char **stock, char **new_line)
{
    char *tmp = NULL;
    ssize_t index = -1;

    index = my_str_contains_index(*new_line, '\n');
    if (index > -1) {
        tmp = my_strndup(*new_line, index);
        if ((*new_line)[index + 1])
            (*stock) = my_strdup(&(*new_line)[index + 1]);
        if (*new_line)
            free(*new_line);
        *new_line = tmp;
        return (true);
    }
    return (false);
}

static char *get_new_line(char **stock, const int fd)
{
    char *new_line = NULL;

    if (*stock) {
        new_line = (*stock);
        *stock = NULL;
        if (reassign_string_pointers(stock, &new_line))
            return (new_line);
    }
    read_new_line(&new_line, fd);
    reassign_string_pointers(stock, &new_line);
    return (new_line);
}

char *get_next_line(const int fd)
{
    static char *stock = NULL;
    char *line = NULL;

    if (fd <= -1)
        return (NULL);
    line = get_new_line(&stock, fd);
    return (line);
}
