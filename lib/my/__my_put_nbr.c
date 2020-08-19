/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Puts an unsigned number on a file descriptor.
*/

#include "my.h"

static ssize_t __my_div_mod_op(const ssize_t __nb, const ssize_t len_base, const size_t _m, const bool __op)
{
    if (_m & UNSIGNED) {
        if (__op == 0)
            return ((size_t)__nb / ABS(len_base));
        return ((size_t)__nb % ABS(len_base));
    } else if (__op == 0) {
        return (__nb / len_base);
    }
    return (__nb % len_base);
}

static void __my_update_count(ssize_t *__count, const ssize_t __tmp)
{
    if (__tmp >= 0)
        (*__count) += __tmp;
}

static ssize_t __my_put_nbr_c(const ssize_t nb, const char base[], const size_t _m, const int fd)
{
    const ssize_t len_base = my_strlen(base);
    ssize_t count = 0;
    ssize_t tmp = 0;

    if ((_m & SIGNED) && nb < 0) {
        tmp = my_dputchar('-', fd);
        __my_update_count(&count, tmp);
        tmp = __my_put_nbr_c(nb / len_base, base, _m, fd);
        __my_update_count(&count, tmp);
    }
    if (((_m & SIGNED) && nb >= len_base) || ((_m & UNSIGNED) && (size_t)nb >= ABS(len_base))) {
        tmp = __my_put_nbr_c(__my_div_mod_op(nb, len_base, _m, 0), base, _m, fd);
        __my_update_count(&count, tmp);
        tmp = __my_put_nbr_c(__my_div_mod_op(nb, len_base, _m, 1), base, _m, fd);
        __my_update_count(&count, tmp);
    } else {
        tmp = my_dputchar(base[nb], fd);
        __my_update_count(&count, tmp);
    }
    return (count);
}

static bool __my_put_nbr_no_c(const ssize_t nb, const char base[], const size_t _m, const int fd)
{
    const ssize_t len_base = my_strlen(base);
    bool is_wrote = true;

    if (nb < 0) {
        if (!my_dputchar('-', fd)
            || !__my_put_nbr_no_c(__my_div_mod_op(nb, len_base, _m, 0), base, _m, fd)) {
            is_wrote = false;
        }
    }
    if (nb >= len_base) {
        if (!__my_put_nbr_no_c(nb / len_base, base, _m, fd)
            || !__my_put_nbr_no_c(__my_div_mod_op(nb, len_base, _m, 1), base, _m, fd)) {
            is_wrote = false;
        }
    } else {
        if (!my_dputchar(base[nb], fd)) {
            is_wrote = false;
        }
    }
    return (is_wrote);
}

ssize_t __my_put_nbr(const ssize_t nb, const char base[], const size_t _m, const int fd)
{
    if (_m & COUNT_PRINTED_CHAR)
        return (__my_put_nbr_c(nb, base, _m, fd));
    return (__my_put_nbr_no_c(nb, base, _m, fd));
}
