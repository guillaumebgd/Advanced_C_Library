/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Main header file of my advanced library functions.
*/

#ifndef MY_H_
#define MY_H_

///////////////////////////////////////////////////////////////

////////////////////
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
////////////////////

/////////////////////////////
#include "my_special_chars.h"
/////////////////////////////

///////////////////////

#define NONE (0)

///////////////////////

// Bases //

#define BINARY_BASE ("01")
#define OCTAL_BASE ("01234567")
#define DECIMAL_BASE ("0123456789")
#define HEXADECIMAL_LOWERCASE_BASE ("0123456789abcdef")
#define HEXADECIMAL_UPPERCASE_BASE ("0123456789ABCDEF")

///////////////////////

// Contraptions //

// Gets the absolute value of a variable.
#define ABS(x) ((x < 0) ? (-x) : (x))

///////////////////////

///////////////////////////////////////////////////////////////

////////////////////////
// Character matching //
////////////////////////

// Checks whether a given 'c' character is alphabetical (in range [a-z] or [A-Z]) or not.
bool my_is_alpha(const char c);

// Checks whether a given char is numerical (in range [0-9]) or not.
bool my_is_num(const char c);

// Checks whether a given char is alphabetical or numerical (in range [a-z] or [A-Z] or [0-9]) or not.
static inline bool my_is_alphanum(const char c)
{
    return (my_is_alpha(c) | my_is_num(c));
}

///////////////////////////////////////////////////////////////

/////////////////////
// String matching //
/////////////////////

///////////////////////

// Wildcards Flags //

#define WC_STR (1)
#define WC_CHAR (1 << 1)
#define WC_STR_CHAR (WC_STR | WC_CHAR)

/////////////////////////////

bool __my_match(const char *s1, const char *s2, const size_t _m);

// Checks whether 2 NULL-terminated strings are seemingly identical or not.
//
//- The string wildcard (by default '*', defined in 'include/my/my_special_chars.h:19')
//may be used inside of the 'first' argument.
static inline bool my_match(const char *first, const char *second)
{
    return (__my_match(first, second, WC_STR));
}

// Checks whether 2 NULL-terminated strings are seemingly identical or not.
//
//- The string wildcard (by default '*', defined in 'include/my/my_special_chars.h:19')
//may be used inside of the 'first' argument.
//- The character wildcard (by default '?', defined in 'include/my/my_special_chars.h:20')
//may be used inside of the 'first' argument.
static inline bool my_match_shell(const char *first, const char *second)
{
    return (__my_match(first, second, WC_STR_CHAR));
}

// Checks whether 2 NULL-terminated strings are entirely identical or not.
static inline bool my_str_eq_str(const char *first, const char *second)
{
    return (__my_match(first, second, NONE));
}

///////////////////////////////////////////////////////////////

///////////////////
// Mass matching //
///////////////////

bool __my_mass_eq(size_t nb_args, const size_t first, ...);

// Checks whether 'first' is equal to, at least, one argument after it.
#define my_mass_eq(nb_args, first, ...) \
                (__my_mass_eq(nb_args, (size_t)first, __VA_ARGS__))

// Checks whether a 'mask' string is entirely identical to, at least, one argument string after it.
bool my_mass_str_eq_str(size_t nb_args, const char *mask, ...);

///////////////////////////////////////////////////////////////

///////////////////
// Objects sizes //
///////////////////

///////////////////////

// Until what a counter index should stop counting. //

#define UNTIL_INDEX (1)
#define UNTIL_CHAR (1 << 1)

///////////////////////

ssize_t __my_strlen(const char *str, const ssize_t c, const size_t _m);

// Gets the size of a given NULL-terminated string.
static inline ssize_t my_strlen(const char *str)
{
    return (__my_strlen(str, 0, NONE));
}

// Gets the number of characters of a given NULL-terminated string
// until reaching 'n' iterations or reaching the termination.
static inline ssize_t my_strnlen(const char *str, const ssize_t n)
{
    if (n < 0)
        return (str ? -1 : 0);
    return (__my_strlen(str, n, UNTIL_INDEX));
}

// Gets the number of characters of a given NULL-terminated string
// before the first occurence of a 'c' character or reaching the termination.
static inline ssize_t my_strlen_char(const char *str, const char c)
{
    return (__my_strlen(str, (ssize_t)c, UNTIL_CHAR));
}

///////////////////////

#define UNSIGNED (1 << 2)
#define SIGNED (1 << 3)

///////////////////////

size_t __my_nbr_size(ssize_t __s_nb, const size_t _m);

// Gets the number of digits that composes an int.
static inline size_t my_int_size(const int nb)
{
    return (__my_nbr_size((ssize_t)nb, SIGNED));
}

// Gets the number of digits that composes a long int.
static inline size_t my_long_int_size(const long int nb)
{
    return (__my_nbr_size((ssize_t)nb, SIGNED));
}

// Gets the number of digits that composes a long long int.
static inline size_t my_long_long_int_size(const long long int nb)
{
    return (__my_nbr_size((ssize_t)nb, SIGNED));
}

// Gets the number of digits that composes a ssize_t.
static inline size_t my_ssize_t_size(const ssize_t nb)
{
    return (__my_nbr_size((ssize_t)nb, SIGNED));
}

// Gets the number of digits that composes an unsigned int.
static inline size_t my_uint_size(const unsigned int nb)
{
    return (__my_nbr_size((ssize_t)nb, UNSIGNED));
}

// Gets the number of digits that composes a long unsigned int.
static inline size_t my_long_uint_size(const long unsigned int nb)
{
    return (__my_nbr_size((ssize_t)nb, UNSIGNED));
}

// Gets the number of digits that composes a long long unsigned int.
static inline size_t my_long_long_uint_size(const long long unsigned int nb)
{
    return (__my_nbr_size((ssize_t)nb, UNSIGNED));
}

// Gets the number of digits that composes a size_t.
static inline size_t my_size_t_size(const size_t nb)
{
    return (__my_nbr_size((ssize_t)nb, UNSIGNED));
}

///////////////////////////////////////////////////////////////

///////////////////////
// Search in objects //
///////////////////////

///////////////////////

#define DONT_GET_CHAR_INDEX (1)
#define GET_CHAR_INDEX (1 << 1)

///////////////////////

ssize_t __my_str_contains(const char *str, const char list[], const size_t _m);

// Checks whether a 'c' character is inside of a NULL-terminated string or not.
static inline bool my_str_contains(const char *str, const char c)
{
    char list[2];
    ssize_t len = -1;

    if (str && c == '\0') {
        len = my_strlen(str);
        return (len < 0 ? false : (str[len]) == c);
    }
    list[0] = c;
    list[1] = '\0';
    return (__my_str_contains(str, list, DONT_GET_CHAR_INDEX));
}

// Checks whether a 'c' character is inside of a NULL-terminated string or not.
static inline ssize_t my_str_contains_index(const char *str, const char c)
{
    char list[2];

    list[0] = c;
    list[1] = '\0';
    return (__my_str_contains(str, list, GET_CHAR_INDEX));
}

// Checks whether at least a character from a 'list' string is inside of a NULL-terminated string or not.
static inline bool my_str_contains_list(const char *str, const char list[])
{
    return (__my_str_contains(str, list, DONT_GET_CHAR_INDEX));
}

///////////////////////////////////////////////////////////////

/////////////
// Fillers //
/////////////

// Puts 'n' 'c's in 'buffer' from its beginning.
void *my_memset(void *buffer, const int c, const size_t n);

///////////////////////////////////////////////////////////////

//////////////
// Printers //
//////////////

bool __my_putchar(const char c, const int fd);

// Prints a given character onto the STDOUT.
static inline bool my_putchar(const char c)
{
    return (__my_putchar(c, STDOUT_FILENO));
}

// Prints a given character onto the given file descriptor.
static inline bool my_dputchar(const char c, const int fd)
{
    return (__my_putchar(c, fd));
}

// Put Signed numbers //

///////////////////////

#define NO_COUNT_PRINTED_CHAR (1)
#define COUNT_PRINTED_CHAR (1 << 1)

///////////////////////

ssize_t __my_put_nbr(const ssize_t nb, const char base[], const size_t _m, const int fd);

// Prints a given signed onto the STDOUT.
static inline bool my_put_nbr(const ssize_t nb)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, STDOUT_FILENO));
}

// Prints a given signed onto the STDOUT, in binary base.
static inline bool my_put_nbr_binary(const ssize_t nb)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, STDOUT_FILENO));
}

// Prints a given signed onto the STDOUT, in octal base.
static inline bool my_put_nbr_octal(const ssize_t nb)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, STDOUT_FILENO));
}

// Prints a given signed onto the STDOUT, in lowercase hexadecimal base.
static inline bool my_put_nbr_lower_hex(const ssize_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, STDOUT_FILENO));
}

// Prints a given signed onto the STDOUT, in uppercase hexadecimal base.
static inline bool my_put_nbr_upper_hex(const ssize_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, STDOUT_FILENO));
}

// Prints a given signed onto the STDOUT, in a given base.
static inline bool my_put_nbr_base(const ssize_t nb, const char base[])
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | SIGNED, STDOUT_FILENO));
}

// Prints a given signed onto the given file descriptor.
static inline bool my_dput_nbr(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, fd));
}

// Prints a given signed onto the given file descriptor, in binary base.
static inline bool my_dput_nbr_binary(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, fd));
}

// Prints a given signed onto the given file descriptor, in octal base.
static inline bool my_dput_nbr_octal(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, fd));
}

// Prints a given signed onto the given file descriptor, in lowercase hexadecimal base.
static inline bool my_dput_nbr_lower_hex(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, fd));
}

// Prints a given signed onto the given file descriptor, in uppercase hexadecimal base.
static inline bool my_dput_nbr_upper_hex(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | SIGNED, fd));
}

// Prints a given signed onto the given file descriptor, in a given base.
static inline bool my_dput_nbr_base(const ssize_t nb, const char base[], const int fd)
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | SIGNED, fd));
}

// Put Unsigned numbers //

// Prints a given unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr(const size_t nb)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, STDOUT_FILENO));
}

// Prints a given unsigned onto the STDOUT, in binary base.
static inline bool my_put_unsigned_nbr_binary(const size_t nb)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, STDOUT_FILENO));
}

// Prints a given unsigned onto the STDOUT, in octal base.
static inline bool my_put_unsigned_nbr_octal(const size_t nb)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, STDOUT_FILENO));
}

// Prints a given unsigned onto the STDOUT, in lowercase hexadecimal base.
static inline bool my_put_unsigned_nbr_lower_hex(const size_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, STDOUT_FILENO));
}

// Prints a given unsigned onto the STDOUT, in uppercase hexadecimal base.
static inline bool my_put_unsigned_nbr_upper_hex(const size_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, STDOUT_FILENO));
}

// Prints a given unsigned onto the STDOUT, in a given base.
static inline bool my_put_unsigned_nbr_base(const size_t nb, const char base[])
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | UNSIGNED, STDOUT_FILENO));
}

// Prints a given unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, fd));
}

// Prints a given unsigned onto the given file descriptor, in binary base.
static inline bool my_dput_unsigned_nbr_binary(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, fd));
}

// Prints a given unsigned onto the given file descriptor, in octal base.
static inline bool my_dput_unsigned_nbr_octal(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, fd));
}

// Prints a given unsigned onto the given file descriptor, in lowercase hexadecimal base.
static inline bool my_dput_unsigned_nbr_lower_hex(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, fd));
}

// Prints a given unsigned onto the given file descriptor, in uppercase hexadecimal base.
static inline bool my_dput_unsigned_nbr_upper_hex(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | UNSIGNED, fd));
}

// Prints a given unsigned onto the given file descriptor, in a given base.
static inline bool my_dput_unsigned_nbr_base(const size_t nb, const char base[], const int fd)
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | UNSIGNED, fd));
}

//////////////////////////

//////////////////////////
// String manipulations //
//////////////////////////

void __my_strcpy(const char *template, char *dest, const ssize_t c, const size_t _m);

// Copies characters from 'template' to 'dest'.
static inline void my_strcpy(const char *template, char *dest)
{
    __my_strcpy(template, dest, 0, NONE);
}

// Copies 'n' characters from 'template' to 'dest'.
static inline void my_strncpy(const char *template, char *dest, const ssize_t n)
{
    if (n < 0)
        return;
    __my_strcpy(template, dest, n, UNTIL_INDEX);
}

// Copies characters from 'template' to 'dest' until reaching the 'c' char or the termination.
static inline void my_strcpy_char(const char *template, char *dest, const char c)
{
    __my_strcpy(template, dest, (ssize_t)c, UNTIL_CHAR);
}

char *__my_strdup(const char *template, const ssize_t c, const size_t _m);

// Allocates a new string and copies characters from 'template' to it.
static inline char *my_strdup(const char *template)
{
    return (__my_strdup(template, 0, NONE));
}

// Allocates new string and copies 'n' characters from 'template' to it.
static inline char *my_strndup(const char *template, const ssize_t n)
{
    if (n < 0)
        return (NULL);
    return (__my_strdup(template, n, UNTIL_INDEX));
}

// Allocates a new string and copies characters, until reaching the 'c' character
// or the termination, from 'template' to it.
static inline char *my_strdup_char(const char *template, const char c)
{
    return (__my_strdup(template, (ssize_t)c, UNTIL_CHAR));
}

///////////////////////

#define FREE_FIRST (1)
#define FREE_SECOND (2)
#define FREE_BOTH (FREE_FIRST | FREE_SECOND)

///////////////////////

// Allocates a new string that is the result of a concatenate of
// the 'first' and the 'second' strings.
//
// The 'free_opt' argument can be used to free the 'first' and/or the 'second' argument
// after the process using the following flags:
//
// - FREE_FIRST
// - FREE_SECOND
// - FREE_BOTH
//
// And if you don't want to free anything, use NONE.
char *my_strcat(char *first, char *second, const size_t free_opt);

//////////////////////////

/////////////////////
// File Management //
/////////////////////

// Gets the next line of a file.
char *get_next_line(const int fd);

// Checks whether a file has a given extension.
bool my_is_file_extension(const char *file, const char *extension);

///////////////////////

#define GET_FILE_NAME (1)
#define GET_FILE_PATH (1 << 1)

///////////////////////

char *__my_get_file_part(const char *file_with_path, const size_t _m);

// Gets the name of a file from a file destination string.
static inline char *my_get_file_name(const char *pathed_file)
{
    return (__my_get_file_part(pathed_file, GET_FILE_NAME));
}

// Gets the path from a file destination string.
static inline char *my_get_file_path(const char *pathed_file)
{
    return (__my_get_file_part(pathed_file, GET_FILE_PATH));
}

///////////////////////////////////////////////////////////////

#endif /* MY_H_ */
