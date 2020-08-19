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

***

```C
bool my_mass_eq(size_t nb_args, first, ...);
```

Checks whether the <code>first</code> argument matches with any following or not.<br>

* The arguments, apart from <code>size_t nb_args</code>, can be anything and that's why the types of the following arguments aren't shown in the prototype above.<br>

***

```C
bool my_is_alpha(const char c);
```

Checks whether a given <code>c</code> character is alphabetical (in range [a-z] or [A-Z]) or not.<br>

***

```C
bool my_is_num(const char c);
```

Checks whether a given <code>c</code> character is numerical (in range [0-9]) or not.<br>

***

```C
bool my_is_alphanum(const char c);
```

Checks whether a given <code>c</code> character is alphabetical or numerical (in range [a-z] or [A-Z] or [0-9]) or not.<br>

***

```C
bool my_match(const char *first, const char *second)
```

Checks whether 2 [NULL-terminated strings](https://en.wikipedia.org/wiki/Null-terminated_string) are seemingly identical or not.<br>

* The string [wildcard](https://en.wikipedia.org/wiki/Wildcard_character) (by default <code>*</code>, defined in <code>"include/my/my_special_chars.h":19</code>) may be used inside of the <code>const char *first</code> argument.<br>

***

```C
bool my_match_shell(const char *first, const char *second)
```

Checks whether 2 [NULL-terminated strings](https://en.wikipedia.org/wiki/Null-terminated_string) are seemingly identical or not.<br>

* The string [wildcard](https://en.wikipedia.org/wiki/Wildcard_character) (by default <code>*</code>, defined in <code>"include/my/my_special_chars.h":19</code>) may be used inside of the <code>first</code> argument.
* The character [wildcard](https://en.wikipedia.org/wiki/Wildcard_character) (by default <code>?</code>, defined in <code>"include/my/my_special_chars.h":20</code>) may be used inside of the <code>const char *first</code> argument.

*It gets its name <code>my_match_shell</code> from the matching patterns a [shell](https://en.wikipedia.org/wiki/Shell_(computing)) can handle in commands.*<br>

***

```C
bool my_str_eq_str(const char *first, const char *second)
```
Checks whether 2 [NULL-terminated strings](https://en.wikipedia.org/wiki/Null-terminated_string) are entirely identical or not.<br>

***

```C
bool my_mass_str_eq_str(size_t nb_args, const char *mask, ...);
```

Checks whether the <code>const char *mask</code> argument is entirely identical with at least one following string.<br>

***

## To come in the near future

```C
int my_printf(const char *input, ...);
```
- Mimics the <code>printf</code> function.
<br>
