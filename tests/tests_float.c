/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_float
*/

#include <criterion/criterion.h>
#include "printf_get_fcts.h"

Test(printf_get_float, test_float)
{
    cr_assert_str_eq(printf_get_float(10, 0, 0), "10.000000");
    cr_assert_str_eq(printf_get_float(10.5, 0, 0), "10.500000");
    cr_assert_str_eq(printf_get_float(-10, 0, 0), "-10.000000");
    cr_assert_str_eq(printf_get_float(-10.5, 0, 0), "-10.500000");
    cr_assert_str_eq(printf_get_float(8379287633.82374623, 0, 0), "8379287633.823746");
    cr_assert_str_eq(printf_get_float(-28393922.28739873, 0, 0), "-28393922.287398");
}

Test(printf_get_float, test_float_precision)
{
    cr_assert_str_eq(printf_get_float(10, 0, 1), "10.0");
    cr_assert_str_eq(printf_get_float(10.5, 0, 1), "10.5");
    cr_assert_str_eq(printf_get_float(10.5, 0, 3), "10.500");
    cr_assert_str_eq(printf_get_float(-10.5, 0, 3), "-10.500");
    cr_assert_str_eq(printf_get_float(8379287633.82374623, 0, 5), "8379287633.82374");
    cr_assert_str_eq(printf_get_float(-28393922.28739873, 0, 5), "-28393922.28739");
}