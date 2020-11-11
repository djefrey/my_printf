/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_bases
*/

#include <criterion/criterion.h>
#include "printf_get_fcts.h"
#include "flags.h"

Test(printf_get_nbr_base, test_base_pos)
{
    cr_assert_str_eq(printf_get_nbr_base(5, "01", 0), "101");
    cr_assert_str_eq(printf_get_nbr_base(42, "01", 0), "101010");
    cr_assert_str_eq(printf_get_nbr_base(736237, "01", 0), "10110011101111101101");
    cr_assert_str_eq(printf_get_nbr_base(87236872368292, "01", 0), "10011110101011101101010110010011111000010100100");

    cr_assert_str_eq(printf_get_nbr_base(5, "0123456789", 0), "5");
    cr_assert_str_eq(printf_get_nbr_base(42, "0123456789", 0), "42");
    cr_assert_str_eq(printf_get_nbr_base(736237, "0123456789", 0), "736237");
    cr_assert_str_eq(printf_get_nbr_base(87236872368292, "0123456789", 0), "87236872368292");

    cr_assert_str_eq(printf_get_nbr_base(5, "0123456789abcdef", 0), "5");
    cr_assert_str_eq(printf_get_nbr_base(42, "0123456789abcdef", 0), "2a");
    cr_assert_str_eq(printf_get_nbr_base(736237, "0123456789abcdef", 0), "b3bed");
    cr_assert_str_eq(printf_get_nbr_base(87236872368292, "0123456789ABCDEF", 0), "4F576AC9F0A4");
}

Test(printf_get_nbr_base, test_base_pos_flag)
{
    cr_assert_str_eq(printf_get_nbr_base(5, "01", FLAG_SIGN), "+101");
    cr_assert_str_eq(printf_get_nbr_base(42, "01", FLAG_BLANK), " 101010");

    cr_assert_str_eq(printf_get_nbr_base(5, "0123456789", FLAG_SIGN), "+5");
    cr_assert_str_eq(printf_get_nbr_base(42, "0123456789", FLAG_BLANK), " 42");

    cr_assert_str_eq(printf_get_nbr_base(5, "0123456789abcdef", FLAG_SIGN), "+5");
    cr_assert_str_eq(printf_get_nbr_base(42, "0123456789abcdef", FLAG_BLANK), " 2a");
}

Test(printf_get_nbr_base, test_base_neg)
{
    cr_assert_str_eq(printf_get_nbr_base(-5, "01", 0), "-101");
    cr_assert_str_eq(printf_get_nbr_base(-42, "01", 0), "-101010");
    cr_assert_str_eq(printf_get_nbr_base(-736237, "01", 0), "-10110011101111101101");
    cr_assert_str_eq(printf_get_nbr_base(-87236872368292, "01", 0), "-10011110101011101101010110010011111000010100100");

    cr_assert_str_eq(printf_get_nbr_base(-5, "0123456789", 0), "-5");
    cr_assert_str_eq(printf_get_nbr_base(-42, "0123456789", 0), "-42");
    cr_assert_str_eq(printf_get_nbr_base(-736237, "0123456789", 0), "-736237");
    cr_assert_str_eq(printf_get_nbr_base(-87236872368292, "0123456789", 0), "-87236872368292");

    cr_assert_str_eq(printf_get_nbr_base(-5, "0123456789abcdef", 0), "-5");
    cr_assert_str_eq(printf_get_nbr_base(-42, "0123456789abcdef", 0), "-2a");
    cr_assert_str_eq(printf_get_nbr_base(-736237, "0123456789abcdef", 0), "-b3bed");
    cr_assert_str_eq(printf_get_nbr_base(-87236872368292, "0123456789ABCDEF", 0), "-4F576AC9F0A4");
}

Test(printf_get_unbr_base, test_unsigned_base)
{
    cr_assert_str_eq(printf_get_unbr_base(5, "01"), "101");
    cr_assert_str_eq(printf_get_unbr_base(42, "01"), "101010");
    cr_assert_str_eq(printf_get_unbr_base(736237, "01"), "10110011101111101101");
    cr_assert_str_eq(printf_get_unbr_base(87236872368292, "01"), "10011110101011101101010110010011111000010100100");

    cr_assert_str_eq(printf_get_unbr_base(5, "0123456789"), "5");
    cr_assert_str_eq(printf_get_unbr_base(42, "0123456789"), "42");
    cr_assert_str_eq(printf_get_unbr_base(736237, "0123456789"), "736237");
    cr_assert_str_eq(printf_get_unbr_base(87236872368292, "0123456789"), "87236872368292");

    cr_assert_str_eq(printf_get_unbr_base(5, "0123456789abcdef"), "5");
    cr_assert_str_eq(printf_get_unbr_base(42, "0123456789abcdef"), "2a");
    cr_assert_str_eq(printf_get_unbr_base(736237, "0123456789abcdef"), "b3bed");
    cr_assert_str_eq(printf_get_unbr_base(87236872368292, "0123456789ABCDEF"), "4F576AC9F0A4");
}