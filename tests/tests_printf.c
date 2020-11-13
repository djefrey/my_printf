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
    int len = my_printf("Hello");
    cr_assert_stdout_eq_str("Hello");
    cr_assert_eq(len, 5);
}

Test(my_printf, simple_str_newline, .init = redirect_all_std)
{
    int len = my_printf("Hello\nWorld");
    cr_assert_stdout_eq_str("Hello\nWorld");
    cr_assert_eq(len, 11);
}

Test(my_printf, print_shorts, .init = redirect_all_std)
{
    int len = my_printf("%hd/%hd", (short) (32767), (short) (32768));
    cr_assert_stdout_eq_str("32767/-32768");
    cr_assert_eq(len, 12);
}

Test(my_printf, print_int, .init = redirect_all_std)
{
    int len = my_printf("I'm %i", 18);
    cr_assert_stdout_eq_str("I'm 18");
    cr_assert_eq(len, 6);
}

Test(my_printf, print_ints, .init = redirect_all_std)
{
    int len = my_printf("I'm %i and my sister is %i", 18, 17);
    cr_assert_stdout_eq_str("I'm 18 and my sister is 17");
    cr_assert_eq(len, 26);
}

Test(my_printf, print_longs, .init = redirect_all_std)
{
    int len = my_printf("%ld/%ld", 9223372036854775807, 9223372036854775808);
    cr_assert_stdout_eq_str("9223372036854775807/-9223372036854775808");
    cr_assert_eq(len, 40);
}

Test(my_printf, print_char, .init = redirect_all_std)
{
    int len = my_printf("I got an %c", 'A');
    cr_assert_stdout_eq_str("I got an A");
    cr_assert_eq(len, 10);
}

Test(my_printf, print_chars, .init = redirect_all_std)
{
    int len = my_printf("Hey, %c%c%c !", 's', 'l', 't');
    cr_assert_stdout_eq_str("Hey, slt !");
    cr_assert_eq(len, 10);
}

Test(my_printf, print_str, .init = redirect_all_std)
{
    int len = my_printf("Hey, %s !", "slt");
    cr_assert_stdout_eq_str("Hey, slt !");
    cr_assert_eq(len, 10);
}

Test(my_printf, print_strs, .init = redirect_all_std)
{
    int len = my_printf("%s a tous, je %s dire donc %s %s", "Bonjour", "sais pas quoi", "je", "rempli");
    cr_assert_stdout_eq_str("Bonjour a tous, je sais pas quoi dire donc je rempli");
    cr_assert_eq(len, 52);
}

Test(my_printf, print_fullstr_small, .init = redirect_all_std)
{
    char str[] = "42";

    str[0] = 4;
    int len = my_printf("Le nombre est %S", str);
    cr_assert_stdout_eq_str("Le nombre est \\0042");
    cr_assert_eq(len, 19);
}

Test(my_printf, print_fullstr_bug, .init = redirect_all_std)
{
    char str[] = "Del x";

    str[4] = 127;
    int len = my_printf("Faut bien test %S", str);
    cr_assert_stdout_eq_str("Faut bien test Del \\177");
    cr_assert_eq(len, 23);
}

Test(my_printf, print_fullstrduo, .init = redirect_all_std)
{
    char str[] = "42";

    str[0] = 4;
    str[1] = 2;
    int len = my_printf("Le nombre est %S", str);
    cr_assert_stdout_eq_str("Le nombre est \\004\\002");
    cr_assert_eq(len, 22);
}

Test(my_printf, print_ptr, .init = redirect_all_std)
{
    int *a = 0x112233acdef;

    int len = my_printf("%p", a);
    cr_assert_stdout_eq_str("0x112233acdef");
    cr_assert_eq(len, 13);
}

Test(my_printf, print_int_flags, .init = redirect_all_std)
{
    int len = my_printf("%+05d", 50);
    cr_assert_stdout_eq_str("+0050");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_ptr_w_flags, .init = redirect_all_std)
{
    int *a = 0x112233acdef;

    int len = my_printf("%+015p", a);
    cr_assert_stdout_eq_str("0x00112233acdef");
    cr_assert_eq(len, 15);
}

Test(my_printf, print_octal, .init = redirect_all_std)
{
    int len = my_printf("%o", 15);
    cr_assert_stdout_eq_str("17");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_octal_hashtag, .init = redirect_all_std)
{
    int len = my_printf("%#o", 15);
    cr_assert_stdout_eq_str("017");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_binary, .init = redirect_all_std)
{
    int len = my_printf("%lb %lb", 903092393692837, 82387632377);
    cr_assert_stdout_eq_str("11001101010101101110010101010100110100111010100101 1001100101110101011111000000011111001");
    cr_assert_eq(len, 88);
}

Test(my_printf, print_hexa, .init = redirect_all_std)
{
    int len = my_printf("%lx %lX", 140725262749228, 83729387928372836);
    cr_assert_stdout_eq_str("7ffd274c0e2c 129776F48BB4664");
    cr_assert_eq(len, 28);
}

Test(my_printf, print_unsigned_char, .init = redirect_all_std)
{
    int len = my_printf("%hhu %hhu", 255, 256);
    cr_assert_stdout_eq_str("255 0");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_unsigned_short, .init = redirect_all_std)
{
    int len = my_printf("%hu %hu", 65535, 65536);
    cr_assert_stdout_eq_str("65535 0");
    cr_assert_eq(len, 7);
}

Test(my_printf, print_unsigned_longlong, .init = redirect_all_std)
{
    int len = my_printf("%llu %llu", 18446744073709551615, 18446744073709551616);
    cr_assert_stdout_eq_str("18446744073709551615 0");
    cr_assert_eq(len, 22);
}

Test(my_printf, print_percent_flag, .init = redirect_all_std)
{
    int len = my_printf("%%");
    cr_assert_stdout_eq_str("%");
    cr_assert_eq(len, 1);
}

Test(my_printf, print_no_flag, .init = redirect_all_std)
{
    int len = my_printf("astek%%42moulinette");
    cr_assert_stdout_eq_str("astek%42moulinette");
    cr_assert_eq(len, 18);
}

Test(my_printf, print_unknown_flag, .init = redirect_all_std)
{
    int len = my_printf("%m ");
    cr_assert_stdout_eq_str("%m ");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_flag_hastag_octal, .init = redirect_all_std)
{
    int len = my_printf("%#o", 15);
    cr_assert_stdout_eq_str("017");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_flag_hastag_hexa, .init = redirect_all_std)
{
    int len = my_printf("%#x", 15);
    cr_assert_stdout_eq_str("0xf");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_flag_hastag_hexa_up, .init = redirect_all_std)
{
    int len = my_printf("%#X", 15);
    cr_assert_stdout_eq_str("0XF");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_flag_plus, .init = redirect_all_std)
{
    int len = my_printf("%+d", 15);
    cr_assert_stdout_eq_str("+15");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_uns_flag_plus, .init = redirect_all_std)
{
    int len = my_printf("%+u", 15);
    cr_assert_stdout_eq_str("15");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_neg_flag_zero, .init = redirect_all_std)
{
    int len = my_printf("%0+5d", -15);
    cr_assert_stdout_eq_str("-0015");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_flag_plus_zero, .init = redirect_all_std)
{
    int len = my_printf("%0+5d", 15);
    cr_assert_stdout_eq_str("+0015");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_flag_plus_spaces, .init = redirect_all_std)
{
    int len = my_printf("%+5d", 15);
    cr_assert_stdout_eq_str("  +15");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_uns_flag_plus_spaces, .init = redirect_all_std)
{
    int len = my_printf("%+5u", 15);
    cr_assert_stdout_eq_str("   15");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_flag_plus_spaces_minus, .init = redirect_all_std)
{
    int len = my_printf("%0-+5d", 15);
    cr_assert_stdout_eq_str("+15  ");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_flag_blank, .init = redirect_all_std)
{
    int len = my_printf("% d", 15);
    cr_assert_stdout_eq_str(" 15");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_uns_flag_blank, .init = redirect_all_std)
{
    int len = my_printf("% u", 15);
    cr_assert_stdout_eq_str("15");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_override_blank_sign, .init = redirect_all_std)
{
    int len = my_printf("% +d", 15);
    cr_assert_stdout_eq_str("+15");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_flags_in_disorder, .init = redirect_all_std)
{
    int len = my_printf("%0#+10d", 50);
    cr_assert_stdout_eq_str("+000000050");
    cr_assert_eq(len, 10);
}

Test(my_printf, flag_n, .init = redirect_all_std)
{
    int test1 = 0;
    int test2 = 0;
    int len = my_printf("Hey!%n%s%n",  &test1, "Test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", &test2);
    cr_assert_stdout_eq_str("Hey!Test!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    cr_assert_eq(test1, 4);
    cr_assert_eq(test2, 107);
}

Test(my_printf, flag_n_with_other_flags, .init = redirect_all_std)
{
    int test1 = 0;

    int len = my_printf("Test %+#015X%n", 0X60ABC42,&test1);
    cr_assert_stdout_eq_str("Test 0X00000060ABC42");
    cr_assert_eq(test1, 20);
}

Test(my_printf, print_int_precision, .init = redirect_all_std)
{
    int len = my_printf("I'm %.2i", 18000);
    cr_assert_stdout_eq_str("I'm 18000");
    cr_assert_eq(len, 9);
}

Test(my_printf, print_int_precision_smaller, .init = redirect_all_std)
{
    int len = my_printf("I'm %.5i", 18);
    cr_assert_stdout_eq_str("I'm 00018");
    cr_assert_eq(len, 9);
}

Test(my_printf, print_str_precision, .init = redirect_all_std)
{
    int len = my_printf("Hey, %.2s !", "slt");
    cr_assert_stdout_eq_str("Hey, sl !");
    cr_assert_eq(len, 9);
}

Test(my_printf, print_str_precision_bigger, .init = redirect_all_std)
{
    int len = my_printf("Hey, %.5s !", "slt");
    cr_assert_stdout_eq_str("Hey, slt !");
    cr_assert_eq(len, 10);
}

Test(my_printf, print_bin_precision, .init = redirect_all_std)
{
    int len = my_printf("%-15.12b", 1565454);
    cr_assert_stdout_eq_str("101111110001100001110");
    cr_assert_eq(len, 21);
}

Test(my_printf, print_hex_precision, .init = redirect_all_std)
{
    int len = my_printf("%-6.3x", 0x54321);
    cr_assert_stdout_eq_str("54321  ");
    cr_assert_eq(len, 6);
}

Test(my_printf, print_hex_precision_exceed, .init = redirect_all_std)
{
    int len = my_printf("%-6.3d", 0x80000000);
    cr_assert_stdout_eq_str("-2147483648");
    cr_assert_eq(len, 11);
}

// ----- //

Test(my_printf, print_octal_field_width, .init = redirect_all_std)
{
    int len = my_printf("%5o", 15);
    cr_assert_stdout_eq_str("   17");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_octal_field_width_precision, .init = redirect_all_std)
{
    int len = my_printf("%5.3o", 15);
    cr_assert_stdout_eq_str("  017");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_octal_field_width_too_small, .init = redirect_all_std)
{
    int len = my_printf("%1o", 15);
    cr_assert_stdout_eq_str("17");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_octal_minus, .init = redirect_all_std)
{
    int len = my_printf("%-5o", 15);
    cr_assert_stdout_eq_str("17   ");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_octal_minus_too_small, .init = redirect_all_std)
{
    int len = my_printf("%-1o", 15);
    cr_assert_stdout_eq_str("17");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_octal_zero, .init = redirect_all_std)
{
    int len = my_printf("%05o", 15);
    cr_assert_stdout_eq_str("00017");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_octal_hastag, .init = redirect_all_std)
{
    int len = my_printf("%#05o", 15);
    cr_assert_stdout_eq_str("00017");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_octal_hastag_precision, .init = redirect_all_std)
{
    int len = my_printf("%#05.10o", 15);
    cr_assert_stdout_eq_str("0000000017");
    cr_assert_eq(len, 10);
}

// ----- //

Test(my_printf, print_hexa_field_width, .init = redirect_all_std)
{
    int len = my_printf("%5x", 255);
    cr_assert_stdout_eq_str("   ff");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_hexa_field_width_precision, .init = redirect_all_std)
{
    int len = my_printf("%5.3x", 255);
    cr_assert_stdout_eq_str("  0ff");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_hexa_field_width_to_small, .init = redirect_all_std)
{
    int len = my_printf("%1x", 255);
    cr_assert_stdout_eq_str("ff");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_hexa_minus, .init = redirect_all_std)
{
    int len = my_printf("%-5x", 255);
    cr_assert_stdout_eq_str("ff   ");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_hexa_minus_too_small, .init = redirect_all_std)
{
    int len = my_printf("%-1x", 255);
    cr_assert_stdout_eq_str("ff");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_hexa_zero, .init = redirect_all_std)
{
    int len = my_printf("%05x", 255);
    cr_assert_stdout_eq_str("000ff");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_hexa_hastag, .init = redirect_all_std)
{
    int len = my_printf("%#05x", 255);
    cr_assert_stdout_eq_str("0x0ff");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_hexa_hastag_precision, .init = redirect_all_std)
{
    int len = my_printf("%#05.10x", 255);
    cr_assert_stdout_eq_str("0x000000ff");
    cr_assert_eq(len, 10);
}

// ----- //

Test(my_printf, print_uphexa_field_width, .init = redirect_all_std)
{
    int len = my_printf("%5X", 255);
    cr_assert_stdout_eq_str("   FF");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_uphexa_field_width_precision, .init = redirect_all_std)
{
    int len = my_printf("%5.3X", 255);
    cr_assert_stdout_eq_str("  0FF");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_uphexa_field_width_too_small, .init = redirect_all_std)
{
    int len = my_printf("%1X", 255);
    cr_assert_stdout_eq_str("FF");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_uphexa_minus, .init = redirect_all_std)
{
    int len = my_printf("%-5X", 255);
    cr_assert_stdout_eq_str("FF   ");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_uphexa_minus_too_small, .init = redirect_all_std)
{
    int len = my_printf("%-1X", 255);
    cr_assert_stdout_eq_str("FF");
    cr_assert_eq(len, 2);
}

Test(my_printf, print_uphexa_zero, .init = redirect_all_std)
{
    int len = my_printf("%05X", 255);
    cr_assert_stdout_eq_str("000FF");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_uphexa_hastag, .init = redirect_all_std)
{
    int len = my_printf("%#05X", 255);
    cr_assert_stdout_eq_str("0X0FF");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_uphexa_hastag_precision, .init = redirect_all_std)
{
    int len = my_printf("%#05.10X", 255);
    cr_assert_stdout_eq_str("0X000000FF");
    cr_assert_eq(len, 10);
}

// ----- //

Test(my_printf, print_bin_field_width, .init = redirect_all_std)
{
    int len = my_printf("%5b", 5);
    cr_assert_stdout_eq_str("  101");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_bin_field_width_precision, .init = redirect_all_std)
{
    int len = my_printf("%.5b", 5);
    cr_assert_stdout_eq_str("00101");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_bin_field_width_too_small, .init = redirect_all_std)
{
    int len = my_printf("%1b", 5);
    cr_assert_stdout_eq_str("101");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_bin_minus, .init = redirect_all_std)
{
    int len = my_printf("%-5b", 5);
    cr_assert_stdout_eq_str("101  ");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_bin_minus_too_small, .init = redirect_all_std)
{
    int len = my_printf("%-1b", 5);
    cr_assert_stdout_eq_str("101");
    cr_assert_eq(len, 3);
}

Test(my_printf, print_bin_zero, .init = redirect_all_std)
{
    int len = my_printf("%05b", 5);
    cr_assert_stdout_eq_str("00101");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_bin_hastag, .init = redirect_all_std)
{
    int len = my_printf("%#05b", 5);
    cr_assert_stdout_eq_str("b0101");
    cr_assert_eq(len, 5);
}

Test(my_printf, print_bin_hastag_precision, .init = redirect_all_std)
{
    int len = my_printf("%#05.10b", 5);
    cr_assert_stdout_eq_str("b000000101");
    cr_assert_eq(len, 10);
}

// ------------- //

Test(my_printf, print_float, .init = redirect_all_std)
{
    int len = my_printf("%f", 150.5);
    cr_assert_stdout_eq_str("150.500000");
    cr_assert_eq(len, 10);
}

Test(my_printf, print_float_float_null, .init = redirect_all_std)
{
    int len = my_printf("%f", 150.0);
    cr_assert_stdout_eq_str("150.000000");
    cr_assert_eq(len, 10);
}

Test(my_printf, print_float_neg, .init = redirect_all_std)
{
    int len = my_printf("%f", -150.5);
    cr_assert_stdout_eq_str("-150.500000");
    cr_assert_eq(len, 11);
}

Test(my_printf, print_float_field_width, .init = redirect_all_std)
{
    int len = my_printf("%15f", 150.5);
    cr_assert_stdout_eq_str("     150.500000");
    cr_assert_eq(len, 15);
}

Test(my_printf, print_float_field_width_neg, .init = redirect_all_std)
{
    int len = my_printf("%-15f", 150.5);
    cr_assert_stdout_eq_str("150.500000     ");
    cr_assert_eq(len, 15);
}

Test(my_printf, print_float_field_width_zero, .init = redirect_all_std)
{
    int len = my_printf("%015f", 150.5);
    cr_assert_stdout_eq_str("00000150.500000");
    cr_assert_eq(len, 15);
}

Test(my_printf, print_float_precision, .init = redirect_all_std)
{
    int len = my_printf("%10.2f", 150.237262);
    cr_assert_stdout_eq_str("    150.23");
    cr_assert_eq(len, 10);
}