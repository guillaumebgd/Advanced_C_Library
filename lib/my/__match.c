/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Checks if a string containing wildcards or not matches with another one.
*/

#include "my.h"

static bool check_for_null_except(const char *s1, const char *s2,
                                const size_t _m)
{
    register size_t i = 0;

    if (s1 == s2)
        return (1);
    if ((_m & WC_STR) && s1) {
        for (; s1[i] && s1[i] == WC_ANY_STR; i += 1);
        return (i > 0) ? (s1[i] ? 0 : 1) : 0;
    }
    return (0);
}

static bool get_second_anchor(const char s1_t_char, char **s2_t_addr)
{
    ssize_t size = my_strlen(*s2_t_addr);

    if (size < 0)
        return (0);
    *s2_t_addr += size;
    for (; **s2_t_addr != s1_t_char && size > 0; *s2_t_addr -= 1)
        size -= 1;
    return (**s2_t_addr == s1_t_char);
}

bool __match(const char *s1, const char *s2, const size_t _m)
{
    char *s1_t = (char *)s1;
    char *s2_t = (char *)s2;

    if (!s1 || !s2)
        return (check_for_null_except(s1, s2, _m));
    if ((*s1) == (*s2))
        return (!(*s1) && !(*s2)) ? 1 : __match(s1 + 1, s2 + 1, _m);
    if ((_m & WC_CHAR) && *s1 == WC_ANY_CHAR)
        return (!(*s2)) ? 0 : __match(s1 + 1, s2 + 1, _m);
    if ((_m & WC_STR) && *s1_t == WC_ANY_STR) {
        while (((((_m & WC_CHAR) && *s1_t == WC_ANY_CHAR)) || *s1_t == WC_ANY_STR) && *s1_t)
            s1_t += 1;
        if (!get_second_anchor(*s1_t, &s2_t))
            return (0);
        return (__match(s1_t, s2_t, _m));
    }
    return (0);
}
