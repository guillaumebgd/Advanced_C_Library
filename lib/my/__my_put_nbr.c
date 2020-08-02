/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Puts an unsigned number on a file descriptor.
*/

#include "my.h"

static ssize_t __my_put_nbr_c(const ssize_t nb, const char base[], const size_t _m, const int fd)
{
    const ssize_t len_base = my_strlen(base);
    ssize_t count = 0;

    if (nb < 0) {
        count += my_dputchar('-', fd);
        count += __my_put_nbr_c(nb / len_base, base, _m, fd);
    }
    if (nb >= len_base) {
        count += __my_put_nbr_c(nb / len_base, base, _m, fd);
        count += __my_put_nbr_c(nb % len_base, base, _m, fd);
    } else
        count += my_dputchar(base[nb], fd);
    return (count);
}

static bool __my_put_nbr_no_c(const ssize_t nb, const char base[], const size_t _m, const int fd)
{
    const ssize_t len_base = my_strlen(base);
    bool is_wrote = true;

    if (nb < 0) {
        if (!my_dputchar('-', fd)
            || __my_put_nbr_no_c(nb / len_base, base, _m, fd)) {
            is_wrote = false;
        }
    }
    if (nb >= len_base) {
        if (!__my_put_nbr_no_c(nb / len_base, base, _m, fd)
            || !__my_put_nbr_no_c(nb % len_base, base, _m, fd)) {
            is_wrote = false;
        }
    } else {
        if (!my_dputchar(base[nb], fd))
            is_wrote = false;
    }
    return (is_wrote);
}

ssize_t __my_put_nbr(const ssize_t nb, const char base[], const size_t _m, const int fd)
{
    if (_m & COUNT_PRINTED_CHAR)
        return (__my_put_nbr_c(nb, base, _m, fd));
    return (__my_put_nbr_no_c(nb, base, _m, fd));
}
