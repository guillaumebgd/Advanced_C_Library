/*
** Personnal C Library
** GuillaumeBgd - Advanced_C_Library
** File description:
** Tests the my_is_file_extension() function.
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_is_file_extension, file_has_extension)
{
    cr_assert(my_is_file_extension("server.bat", ".bat") == true);
}

Test(my_is_file_extension, file_hasnt_extension)
{
    cr_assert(my_is_file_extension("server.bat", ".exe") == false);
}

Test(my_is_file_extension, file_with_path_has_extension)
{
    cr_assert(my_is_file_extension("C:\\Desktop\\server.bat", ".bat") == true);
}

Test(my_is_file_extension, null_file)
{
    cr_assert(my_is_file_extension(NULL, ".bat") == false);
}

Test(my_is_file_extension, null_extension)
{
    cr_assert(my_is_file_extension("server.bat", NULL) == false);
}


Test(my_is_file_extension, null_file_null_extension)
{
    cr_assert(my_is_file_extension(NULL, NULL) == false);
}
