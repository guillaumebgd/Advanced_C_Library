# Advanced C Library

A single-handled C library that bases itself on C standard library, but given more tools and error handlers.
The Library will see new features throughout the project and not just upgrades.

***

## Goal of the Project

It has for main goal to maintain my C Programming abilities up-to-date, however, as a public project, it could show how far you can have fun with basic functions in C
whether in optimization or in generalization.

***

## Table of Contents

Some commentaries about those functions are to be found in headers of this project.

```C
bool my_mass_eq(size_t nb_args, first, ...);
```
- Checks if the <code>first</code> argument matches with any following. Precise the number of arguments you try to match with <code>first</code> in the <code>nb_args</code> argument.

Returns 1 if it matches something, otherwise 0.<br></br>
-> Note: the arguments, apart from <code>nb_args</code> which is a <code>size_t</code>, can be anything and that's why the types of the following arguments aren't shown in the prototype of the function.
<br></br>
```C
bool my_is_alpha(const char c);
```
- Checks if a given <code>c</code> character is alphabetical.

Returns 1 if the character <code>c</code> is alphabetical ([a-z] or [A-Z]), otherwise 0.
<br></br>
```C
bool my_is_num(const char c);
```
- Checks if a given <code>c</code> character is numerical.

Returns 1 if the character <code>c</code> is numerical ([0-9]), otherwise 0.
<br></br>
```C
bool my_is_alphanum(const char c);
```
- Checks if a given <code>c</code> character is alphabetical or numerical.

Returns 1 if the character <code>c</code> is alphabetical or numerical ([a-z] or [A-Z] or [0-9]), otherwise 0.
<br></br>
```C
bool my_match(const char *first, const char *second)
```
- Checks if two [NULL-terminated strings](https://en.wikipedia.org/wiki/Null-terminated_string) match or not.
- The string [wildcard](https://en.wikipedia.org/wiki/Wildcard_character) (by default <code>*</code>, defined in <code>"include/my/my_special_chars.h":19</code>) may be used in the <code>first</code> argument.

Returns 1 if they match, otherwise 0.
<br></br>
```C
bool my_match_shell(const char *first, const char *second)
```
- Checks if two [NULL-terminated strings](https://en.wikipedia.org/wiki/Null-terminated_string) match or not.
- The string [wildcard](https://en.wikipedia.org/wiki/Wildcard_character) (by default <code>*</code>, defined in <code>"include/my/my_special_chars.h":19</code>) may be used inside of the <code>first</code> argument.
- The character [wildcard](https://en.wikipedia.org/wiki/Wildcard_character) (by default <code>?</code>, defined in <code>"include/my/my_special_chars.h":20</code>) may be used inside of the <code>first</code> argument.

*It gets its name from the matching patterns a [shell](https://en.wikipedia.org/wiki/Shell_(computing)) can handle.*

Returns 1 if they match, otherwise 0.
<br></br>
```C
bool my_str_eq_str(const char *first, const char *second)
```
- Checks if two [NULL-terminated strings](https://en.wikipedia.org/wiki/Null-terminated_string) match or not.

Returns 1 if they match, otherwise 0.
<br></br>
```C
bool my_mass_str_eq_str(size_t nb_args, const char *mask, ...);
```
- Checks if the <code>mask</code> argument string matches with any following. Precise the number of arguments you try to match with <code>mask</code> in the <code>nb_args</code> argument.

Returns 1 if it matches something, otherwise 0.<br></br>
<br></br>

***

## To come in the near future

```C
int my_put_double(const double nb);
```
- Prints a double (see [C Data types](https://en.wikipedia.org/wiki/C_data_types)).
<br></br>
```C
int my_printf(const char *input, ...);
```
- Mimics the <code>printf</code> function.
<br></br>
```C
char *get_next_line(const int fd);
```
- Gets a new line in a file.
- Derivatives of the function could include a precision of which line you want or the first that matches a certain string with wildcards.
<br></br>
