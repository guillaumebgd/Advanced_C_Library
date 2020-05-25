/*
** EPITECH PROJECT, 2019
** GuillaumeBgd - my_libraries
** File description:
** checks if a string containing wild cards matches with another one.
*/

#include "my.h"

static bool check_for_null_except(const char *first, const char *second)
{
    register size_t index = 0;

    if (first == second)
        return (true);
    if (first) {
        for (; first[index] && first[index] == WC_ANY_STR; index += 1);
        return (index > 0) ? (first[index] ? false : true) : false;
    }
    return (false);
}

static bool get_second_anchor(const char anchor, char **tmp)
{
    ssize_t size = my_strlen(*tmp);

    if (size < 0)
        return (0);
    *tmp += size;
    for (; (**tmp) != anchor && size > 0; (*tmp) -= 1)
        size -= 1;
    return ((**tmp) == anchor);
}

bool my_match_shell(const char *first, const char *second)
{
    char *anchor = (char *)first;
    char *tmp = (char *)second;

    if (!first || !second)
        return (check_for_null_except(first, second));
    if ((*first) == (*second))
        return (!(*first) && !(*second)) ? true : my_match_shell(first + 1, second + 1);
    if ((*anchor) == WC_ANY_CHAR)
        return (my_match_shell(first + 1, second + 1));
    if ((*anchor) == WC_ANY_STR) {
        while ((*anchor == WC_ANY_STR || *anchor == WC_ANY_STR) && *anchor)
            anchor += 1;
        if (!get_second_anchor(*anchor, &tmp))
            return (false);
        return (my_match_shell(anchor, tmp));
    }
    return (false);
}
