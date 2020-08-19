/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** My library functions.
*/

#ifndef MY_H_
#define MY_H_

///////////////////////////////////////////////////////////////

////////////////////
#include <stdbool.h>
////////////////////
#include <stddef.h>
////////////////////
#include <unistd.h>
////////////////////
#include <stdarg.h>
////////////////////
#include <stdio.h>
////////////////////
#include <fcntl.h>
////////////////////
#include <stdlib.h>
////////////////////

#define NONE (0)

#define BINARY_BASE ("01")
#define OCTAL_BASE ("01234567")
#define DECIMAL_BASE ("0123456789")
#define HEXADECIMAL_LOWERCASE_BASE ("0123456789abcdef")
#define HEXADECIMAL_UPPERCASE_BASE ("0123456789ABCDEF")

#define ABS(x) ((x < 0) ? (-x) : (x))

///////////////////////////////////////////////////////////////

////////////////////////
// Character matching //
////////////////////////

//Checks whether a given char is alphabetical (in range [a-z] or [A-Z]) or not.
//
//Returns (true) on success.
//Returns (false) otherwise.
bool my_is_alpha(const char c);

//Checks whether a given char is numerical (in range [0-9]) or not.
//
//Returns (true) on success.
//Returns (false) otherwise.
bool my_is_num(const char c);


//Checks whether a given char is alphabetical or numerical (in range [a-z] or [A-Z] or [0-9]) or not.
//
//Returns (true) on success.
//Returns (false) otherwise.
static inline bool my_is_alphanum(const char c)
{
    return (my_is_alpha(c) | my_is_num(c));
}

///////////////////////////////////////////////////////////////

/////////////////////
// String matching //
/////////////////////

/////////////////////////////
#include "my_special_chars.h"
/////////////////////////////

//Wildcards Flags

#define WC_STR (1)
#define WC_CHAR (1 << 1)
#define WC_STR_CHAR (WC_STR | WC_CHAR)

/////////////////////////////

bool __my_match(const char *s1, const char *s2, const size_t _m);

//Checks whether 2 NULL-terminated strings are seemingly identical or not.
//
//- The string wildcard (by default '*', defined in 'include/my/my_special_chars.h:19')
//may be used inside of the 'first' argument.
static inline bool my_match(const char *first, const char *second)
{
    return (__my_match(first, second, WC_STR));
}

//Checks whether 2 NULL-terminated strings are seemingly identical or not.
//
//- The string wildcard (by default '*', defined in 'include/my/my_special_chars.h:19')
//may be used inside of the 'first' argument.
//- The character wildcard (by default '?', defined in 'include/my/my_special_chars.h:20')
//may be used inside of the 'first' argument.
static inline bool my_match_shell(const char *first, const char *second)
{
    return (__my_match(first, second, WC_STR_CHAR));
}

//Checks whether 2 NULL-terminated strings are entirely identical or not.
static inline bool my_str_eq_str(const char *first, const char *second)
{
    return (__my_match(first, second, NONE));
}

///////////////////////////////////////////////////////////////

///////////////////////

#define UNTIL_INDEX (1)
#define UNTIL_CHAR (1 << 1)

///////////////////////////
// Objects sizes related //
///////////////////////////

ssize_t __my_strlen(const char *str, const ssize_t c, const size_t _m);

//Gets the size of a given NULL-terminated string.
//
//-> Returns -1 if the given string is NULL.
//-> Returns 0 if the given string only contains a '\0'.
static inline ssize_t my_strlen(const char *str)
{
    return (__my_strlen(str, 0, NONE));
}

static inline ssize_t my_strnlen(const char *str, const ssize_t limit)
{
    if (limit < 0)
        return (0);
    return (__my_strlen(str, limit, UNTIL_INDEX));
}

static inline ssize_t my_strlen_char(const char *str, const char c)
{
    return (__my_strlen(str, (ssize_t)c, UNTIL_CHAR));
}

///////////////////////////////////////////////////////////////

///////////////////////
// Search in strings //
///////////////////////

#define DONT_GET_CHAR_INDEX (0)
#define GET_CHAR_INDEX (1)

ssize_t __my_str_contains(const char *str, const char list[], const size_t _m);

//Checks whether a 'c' character is inside a 'str' string or not.
//
//Returns (true) if 'c' is in 'str'.
//Returns (false) if 'c' is not in 'str'.
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

//Returns an index to a given character in a given string.
//
//If not found, returns -1.
static inline ssize_t my_str_contains_index(const char *str, const char c)
{
    char list[2];

    list[0] = c;
    list[1] = '\0';
    return (__my_str_contains(str, list, GET_CHAR_INDEX));
}

//Returns whether atleast one character in a given list is in a given string.
static inline bool my_str_contains_list(const char *str, const char list[])
{
    return (__my_str_contains(str, list, DONT_GET_CHAR_INDEX));
}

///////////////////////////////////////////////////////////////

/////////////
// Fillers //
/////////////

//Puts 'nb' 'c's in 'buffer' from its beginning.
void *my_memset(void *buffer, const int c, const size_t nb);

/////////////////////////
// Objects Comparisons //
/////////////////////////

bool __my_mass_eq(size_t nb_args, const size_t first, ...);

//Returns if first matches with any args from va_args.
//
//nb -> nb of va_args.
#define my_mass_eq(nb_args, first, ...) \
                    (__my_mass_eq(nb_args, (size_t)first, __VA_ARGS__))

//Returns if mask matches with any args from va_args.
//
//nb -> nb of va_args.
bool my_mass_str_eq_str(size_t nb_args, const char *mask, ...);

///////////////////////////////////////////////////////////////

//////////////
// Printers //
//////////////

bool __my_putchar(const char c, const int fd);

//Prints a given character onto the STDOUT.
static inline bool my_putchar(const char c)
{
    return (__my_putchar(c, STDOUT_FILENO));
}

//Prints a given character onto the the given file descriptor.
static inline bool my_dputchar(const char c, const int fd)
{
    return (__my_putchar(c, fd));
}

//////////////////////////

//////////////////////////
// String manipulations //
//////////////////////////

void __my_strcpy(const char *template, char *dest, const ssize_t c, const size_t _m);

//Copies characters from 'template' to 'dest'.
static inline void my_strcpy(const char *template, char *dest)
{
    __my_strcpy(template, dest, 0, NONE);
}

//Copies 'n' characters from 'template' to 'dest'.
static inline void my_strncpy(const char *template, char *dest, const ssize_t n)
{
    if (n < 0)
        return;
    __my_strcpy(template, dest, n, UNTIL_INDEX);
}

//Copies characters from 'template' to 'dest' until reaching the 'c' char or '\0'.
static inline void my_strcpy_char(const char *template, char *dest, const char c)
{
    __my_strcpy(template, dest, (ssize_t)c, UNTIL_CHAR);
}

char *__my_strdup(const char *template, const ssize_t c, const size_t _m);

//Allocates and returns a new string and copies characters from 'template' to it.
static inline char *my_strdup(const char *template)
{
    return (__my_strdup(template, 0, NONE));
}

//Allocates and returns a new string and 'n' copies characters from 'template' to it.
static inline char *my_strndup(const char *template, const ssize_t n)
{
    if (n < 0)
        return (NULL);
    return (__my_strdup(template, n, UNTIL_INDEX));
}

//Allocates and returns a new string and copies characters, until reaching the 'c' character
//or '\0', from 'template' to it.
static inline char *my_strdup_char(const char *template, const char c)
{
    return (__my_strdup(template, (ssize_t)c, UNTIL_CHAR));
}

#define FREE_FIRST (1)
#define FREE_SECOND (2)
#define FREE_BOTH (FREE_FIRST | FREE_SECOND)

//Concatenates the 'second' string to the 'first' one.
//
//Given flags declared above this function in 'my.h' can be used in 'free_opt'
//in order to free, if you want, 'first' or/and 'second'.
char *my_strcat(char *first, char *second, const size_t free_opt);

//////////////////////////

////////////////////////
// Put Signed numbers //
////////////////////////

#define NO_COUNT_PRINTED_CHAR (0)
#define COUNT_PRINTED_CHAR (1 << 1)
#define PUT_UNSIGNED (1 << 2)
#define PUT_SIGNED (1 << 3)

ssize_t __my_put_nbr(const ssize_t nb, const char base[], const size_t _m, const int fd);

//Prints a given signed onto the STDOUT.
static inline bool my_put_nbr(const ssize_t nb)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, STDOUT_FILENO));
}

//Prints a given binary signed onto the STDOUT.
static inline bool my_put_nbr_binary(const ssize_t nb)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, STDOUT_FILENO));
}

//Prints a given octal signed onto the STDOUT.
static inline bool my_put_nbr_octal(const ssize_t nb)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal signed onto the STDOUT.
static inline bool my_put_nbr_lower_hex(const ssize_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal signed onto the STDOUT.
static inline bool my_put_nbr_upper_hex(const ssize_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, STDOUT_FILENO));
}

//Prints a given signed onto the STDOUT according to its given base.
static inline bool my_put_nbr_base(const ssize_t nb, const char base[])
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, STDOUT_FILENO));
}

//Prints a given signed onto the given file descriptor.
static inline bool my_dput_nbr(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, fd));
}

//Prints a given binary signed onto the given file descriptor.
static inline bool my_dput_nbr_binary(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, fd));
}

//Prints a given octal signed onto the given file descriptor.
static inline bool my_dput_nbr_octal(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, fd));
}

//Prints a given lowercase hexadecimal signed onto the given file descriptor.
static inline bool my_dput_nbr_lower_hex(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, fd));
}

//Prints a given lowercase hexadecimal signed onto the given file descriptor.
static inline bool my_dput_nbr_upper_hex(const ssize_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, fd));
}

//Prints a given signed onto the given file descriptor according to its given base.
static inline bool my_dput_nbr_base(const ssize_t nb, const char base[], const int fd)
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | PUT_SIGNED, fd));
}

//////////////////////////

//////////////////////////
// Put Unsigned numbers //
//////////////////////////

//Prints a given unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr(const size_t nb)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, STDOUT_FILENO));
}

//Prints a given binary unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_binary(const size_t nb)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, STDOUT_FILENO));
}

//Prints a given octal unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_octal(const size_t nb)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_lower_hex(const size_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, STDOUT_FILENO));
}

//Prints a given lowercase hexadecimal unsigned onto the STDOUT.
static inline bool my_put_unsigned_nbr_upper_hex(const size_t nb)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, STDOUT_FILENO));
}

//Prints a given unsigned onto the STDOUT according to its given base.
static inline bool my_put_unsigned_nbr_base(const size_t nb, const char base[])
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, STDOUT_FILENO));
}

//Prints a given unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, DECIMAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, fd));
}

//Prints a given binary unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_binary(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, BINARY_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, fd));
}

//Prints a given octal unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_octal(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, OCTAL_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, fd));
}

//Prints a given lowercase hexadecimal unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_lower_hex(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_LOWERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, fd));
}

//Prints a given lowercase hexadecimal unsigned onto the given file descriptor.
static inline bool my_dput_unsigned_nbr_upper_hex(const size_t nb, const int fd)
{
    return (__my_put_nbr(nb, HEXADECIMAL_UPPERCASE_BASE, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, fd));
}

//Prints a given unsigned onto the given file descriptor according to its given base.
static inline bool my_dput_unsigned_nbr_base(const size_t nb, const char base[], const int fd)
{
    return (__my_put_nbr(nb, base, NO_COUNT_PRINTED_CHAR | PUT_UNSIGNED, fd));
}

//////////////////////////

/////////////////////
// File Management //
/////////////////////

//Gets the next line of a file and returns it.
char *get_next_line(const int fd);

//Checks whether a file has the given extension.
bool my_is_file_extension(const char *file, const char *extension);

#define GET_FILE_NAME (1)
#define GET_FILE_PATH (1 << 1)

char *__my_get_file_part(const char *file_with_path, const size_t _m);

//Gets from a string, containing or not a path to a file, the name of the file
//without the path part.
static inline char *my_get_file_name(const char *pathed_file)
{
    return (__my_get_file_part(pathed_file, GET_FILE_NAME));
}

//Gets from a string, containing a path to a file, the path.
static inline char *my_get_file_path(const char *pathed_file)
{
    return (__my_get_file_part(pathed_file, GET_FILE_PATH));
}

//////////////////////////////////

///////////////////////////////////////////////////////////////

#endif /* MY_H_ */
