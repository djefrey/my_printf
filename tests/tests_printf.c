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
    my_printf("%ld/%ld", 9223372036854775807, 9223372036854775808);
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

Test(my_printf, print_ptr, .init = redirect_all_std)
{
    int *a = 0x112233acdef;

    my_printf("%p", a);
    cr_assert_stdout_eq_str("0x112233acdef");
}

Test(my_printf, print_octal, .init = redirect_all_std)
{
    my_printf("%o", 15);
    cr_assert_stdout_eq_str("17");
}

Test(my_printf, print_octal_hashtag, .init = redirect_all_std)
{
    my_printf("%#o", 15);
    cr_assert_stdout_eq_str("017");
}

Test(my_printf, print_binary, .init = redirect_all_std)
{
    my_printf("%lb %lb", 903092393692837, 82387632377);
    cr_assert_stdout_eq_str("11001101010101101110010101010100110100111010100101 1001100101110101011111000000011111001");
}

Test(my_printf, print_hexa, .init = redirect_all_std)
{
    my_printf("%lx %lX", 140725262749228, 83729387928372836);
    cr_assert_stdout_eq_str("7ffd274c0e2c 129776F48BB4664");
}

Test(my_printf, print_unsigned_char, .init = redirect_all_std)
{
    my_printf("%hhu %hhu", 255, 256);
    cr_assert_stdout_eq_str("255 0");
}

Test(my_printf, print_unsigned_short, .init = redirect_all_std)
{
    my_printf("%hu %hu", 65535, 65536);
    cr_assert_stdout_eq_str("65535 0");
}

Test(my_printf, print_unsigned_longlong, .init = redirect_all_std)
{
    my_printf("%llu %llu", 18446744073709551615, 18446744073709551616);
    cr_assert_stdout_eq_str("18446744073709551615 0");
}

Test(my_printf, print_percent_flag, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, print_no_flag, .init = redirect_all_std)
{
    my_printf("astek%%42moulinette");
    cr_assert_stdout_eq_str("astek%42moulinette");
}

Test(my_printf, print_unknown_flag, .init = redirect_all_std)
{
    my_printf("%m ");
    cr_assert_stdout_eq_str("%m ");
}

Test(my_printf, print_flag_hastag_octal, .init = redirect_all_std)
{
    my_printf("%#o", 15);
    cr_assert_stdout_eq_str("017");
}

Test(my_printf, print_flag_hastag_hexa, .init = redirect_all_std)
{
    my_printf("%#x", 15);
    cr_assert_stdout_eq_str("0xf");
}

Test(my_printf, print_flag_hastag_hexa_up, .init = redirect_all_std)
{
    my_printf("%#X", 15);
    cr_assert_stdout_eq_str("0XF");
}

Test(my_printf, print_flag_plus, .init = redirect_all_std)
{
    my_printf("%+d", 15);
    cr_assert_stdout_eq_str("+15");
}

Test(my_printf, print_uns_flag_plus, .init = redirect_all_std)
{
    my_printf("%+u", 15);
    cr_assert_stdout_eq_str("15");
}

Test(my_printf, print_neg_flag_zero, .init = redirect_all_std)
{
    my_printf("%0+5d", -15);
    cr_assert_stdout_eq_str("-0015");
}

Test(my_printf, print_flag_plus_zero, .init = redirect_all_std)
{
    my_printf("%0+5d", 15);
    cr_assert_stdout_eq_str("+0015");
}

Test(my_printf, print_flag_plus_spaces, .init = redirect_all_std)
{
    my_printf("%+5d", 15);
    cr_assert_stdout_eq_str("  +15");
}

Test(my_printf, print_uns_flag_plus_spaces, .init = redirect_all_std)
{
    my_printf("%+5u", 15);
    cr_assert_stdout_eq_str("   15");
}

Test(my_printf, print_flag_plus_spaces_minus, .init = redirect_all_std)
{
    my_printf("%0-+5d", 15);
    cr_assert_stdout_eq_str("+15   ");
}

Test(my_printf, print_flag_blank, .init = redirect_all_std)
{
    my_printf("% d", 15);
    cr_assert_stdout_eq_str(" 15");
}

Test(my_printf, print_uns_flag_blank, .init = redirect_all_std)
{
    my_printf("% u", 15);
    cr_assert_stdout_eq_str("15");
}

Test(my_printf, print_override_blank_sign, .init = redirect_all_std)
{
    my_printf("% +d", 15);
    cr_assert_stdout_eq_str("+15");
}

Test(my_printf, print_flags_in_disorder, .init = redirect_all_std)
{
    my_printf("%0#+10d", 50);
    cr_assert_stdout_eq_str("+000000050");
}

// ----- //

Test(my_printf, print_octal_field_width, .init = redirect_all_std)
{
    my_printf("%5o", 15);
    cr_assert_stdout_eq_str("   17");
}

Test(my_printf, print_octal_field_width_too_small, .init = redirect_all_std)
{
    my_printf("%1o", 15);
    cr_assert_stdout_eq_str("17");
}

Test(my_printf, print_octal_minus, .init = redirect_all_std)
{
    my_printf("%-5o", 15);
    cr_assert_stdout_eq_str("17   ");
}

Test(my_printf, print_octal_minus_too_small, .init = redirect_all_std)
{
    my_printf("%-1o", 15);
    cr_assert_stdout_eq_str("17");
}

Test(my_printf, print_octal_zero, .init = redirect_all_std)
{
    my_printf("%05o", 15);
    cr_assert_stdout_eq_str("00017");
}

Test(my_printf, print_octal_hastag, .init = redirect_all_std)
{
    my_printf("%#05o", 15);
    cr_assert_stdout_eq_str("00017");
}

// ----- //

Test(my_printf, print_hexa_field_width, .init = redirect_all_std)
{
    my_printf("%5x", 255);
    cr_assert_stdout_eq_str("   ff");
}

Test(my_printf, print_hexa_field_width_to_small, .init = redirect_all_std)
{
    my_printf("%1x", 255);
    cr_assert_stdout_eq_str("ff");
}

Test(my_printf, print_hexa_minus, .init = redirect_all_std)
{
    my_printf("%-5x", 255);
    cr_assert_stdout_eq_str("ff   ");
}

Test(my_printf, print_hexa_minus_too_small, .init = redirect_all_std)
{
    my_printf("%-1x", 255);
    cr_assert_stdout_eq_str("ff");
}

Test(my_printf, print_hexa_zero, .init = redirect_all_std)
{
    my_printf("%05x", 255);
    cr_assert_stdout_eq_str("000ff");
}

Test(my_printf, print_hexa_hastag, .init = redirect_all_std)
{
    my_printf("%#05x", 255);
    cr_assert_stdout_eq_str("0x0ff");
}

// ----- //

Test(my_printf, print_uphexa_field_width, .init = redirect_all_std)
{
    my_printf("%5X", 255);
    cr_assert_stdout_eq_str("   FF");
}

Test(my_printf, print_uphexa_field_width_too_small, .init = redirect_all_std)
{
    my_printf("%1X", 255);
    cr_assert_stdout_eq_str("FF");
}

Test(my_printf, print_uphexa_minus, .init = redirect_all_std)
{
    my_printf("%-5X", 255);
    cr_assert_stdout_eq_str("FF   ");
}

Test(my_printf, print_uphexa_minus_too_small, .init = redirect_all_std)
{
    my_printf("%-1X", 255);
    cr_assert_stdout_eq_str("FF");
}

Test(my_printf, print_uphexa_zero, .init = redirect_all_std)
{
    my_printf("%05X", 255);
    cr_assert_stdout_eq_str("000FF");
}

Test(my_printf, print_uphexa_hastag, .init = redirect_all_std)
{
    my_printf("%#05X", 255);
    cr_assert_stdout_eq_str("0X0FF");
}

// ----- //

Test(my_printf, print_bin_field_width, .init = redirect_all_std)
{
    my_printf("%5b", 5);
    cr_assert_stdout_eq_str("  101");
}

Test(my_printf, print_bin_field_width_too_small, .init = redirect_all_std)
{
    my_printf("%1b", 5);
    cr_assert_stdout_eq_str("101");
}

Test(my_printf, print_bin_minus, .init = redirect_all_std)
{
    my_printf("%-5b", 5);
    cr_assert_stdout_eq_str("101  ");
}

Test(my_printf, print_bin_minus_too_small, .init = redirect_all_std)
{
    my_printf("%-1b", 5);
    cr_assert_stdout_eq_str("101");
}

Test(my_printf, print_bin_zero, .init = redirect_all_std)
{
    my_printf("%05b", 5);
    cr_assert_stdout_eq_str("00101");
}

Test(my_printf, print_bin_hastag, .init = redirect_all_std)
{
    my_printf("%#05b", 5);
    cr_assert_stdout_eq_str("b0101");
}