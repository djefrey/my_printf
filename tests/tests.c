/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** test file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_str, .init = redirect_all_std)
{
    my_printf("Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(my_printf, simple_str_newline, .init = redirect_all_std)
{
    my_printf("Hello\nWorld");
    cr_assert_stdout_eq_str("Hello\nWorld");
}

Test(my_printf, no_flag, .init = redirect_all_std)
{
    my_printf("30% en moins");
    cr_assert_stdout_eq_str("30% en moins");
}

Test(my_printf, print_shorts, .init = redirect_all_std)
{
    my_printf("%hd/%hd", (short) (32767), (short) (32768));
    cr_assert_stdout_eq_str("32767/-32768");
}

Test(my_printf, print_int, .init = redirect_all_std)
{
    my_printf("I'm %i", 18);
    cr_assert_stdout_eq_str("I'm 18");
}

Test(my_printf, print_ints, .init = redirect_all_std)
{
    my_printf("I'm %i and my sister is %i", 18, 17);
    cr_assert_stdout_eq_str("I'm 18 and my sister is 17");
}

Test(my_printf, print_longs, .init = redirect_all_std)
{
    my_printf("%ld/%ld", (long) (9223372036854775807), (long) (9223372036854775808));
    cr_assert_stdout_eq_str("9223372036854775807/-9223372036854775808");
}

Test(my_printf, print_char, .init = redirect_all_std)
{
    my_printf("I got an %c", 'A');
    cr_assert_stdout_eq_str("I got an A");
}

Test(my_printf, print_chars, .init = redirect_all_std)
{
    my_printf("Hey, %c%c%c !", 's', 'l', 't');
    cr_assert_stdout_eq_str("Hey, slt !");
}

Test(my_printf, print_str, .init = redirect_all_std)
{
    my_printf("Hey, %s !", "slt");
    cr_assert_stdout_eq_str("Hey, slt !");
}

Test(my_printf, print_strs, .init = redirect_all_std)
{
    my_printf("%s à tous, je %s dire donc %s %s", "Bonjour", "sais pas quoi", "je", "rempli");
    cr_assert_stdout_eq_str("Bonjour à tous, je sais pas quoi dire donc je rempli");
}

Test(my_printf, print_fullstr, .init = redirect_all_std)
{
    char str[] = "42";

    str[0] = 4;
    my_printf("Le nombre est %S", str);
    cr_assert_stdout_eq_str("Le nombre est \\0042");
}

Test(my_printf, print_fullstrduo, .init = redirect_all_std)
{
    char str[] = "42";

    str[0] = 4;
    str[1] = 2;
    my_printf("Le nombre est %S", str);
    cr_assert_stdout_eq_str("Le nombre est \\004\\002");
}

Test(my_printf, print_fullstr_len2, .init = redirect_all_std)
{
    char str[] = " ";

    str[0] = 15;
    my_printf("%S", str);
    cr_assert_stdout_eq_str("\\015");
}

Test(my_printf, print_binary, .init = redirect_all_std)
{
    my_printf("%b %b", 903092393692837, 82387632377);
    cr_assert_stdout_eq_str("11001101010101101110010101010100110100111010100101 1001100101110101011111000000011111001");
}

Test(my_printf, print_hexa, .init = redirect_all_std)
{
    my_printf("%x %x", 140725262749228, -83729387928372836);
    cr_assert_stdout_eq_str("7ffd274c0e2c -129776f48bb4664");
}