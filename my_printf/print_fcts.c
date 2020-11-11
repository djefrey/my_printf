/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include <stdlib.h>
#include "my.h"
#include "nbr.h"
#include "flags.h"
#include "printf_get_fcts.h"
#include "print_field_width.h"

void print_nb(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_nbr(nbr->sign, flags);
    int len = my_strlen(str);
    int offset = 0;

    if (flags & FLAG_ZERO && (str[0] == '+' || str[0] == '-')) {
        my_putchar(str[0]);
        offset = 1;
    }
    print_zeros_or_spaces(fwidth, len, flags);
    my_putstr(str + offset);
    print_right_spaces(fwidth, len, flags);
    free(str);
}

void print_char(void *value, int flags, int fwidth)
{
    print_left_spaces(fwidth, 1, flags);
    my_putchar(*((char*) (value)));
    print_right_spaces(fwidth, 1, flags);
}

void print_str(void *value, int flags, int fwidth)
{
    char *str = (char*) (value);
    int len = my_strlen(str);

    print_left_spaces(fwidth, len, flags);
    my_putstr(str);
    print_right_spaces(fwidth, len, flags);
}

void print_fullstr(void *value, int flags, int fwidth)
{
    char *str = printf_get_fullstr((char*) value);
    int len = my_strlen(str);

    print_left_spaces(fwidth, len, flags);
    my_putstr(str);
    print_right_spaces(fwidth, len, flags);
}

void print_ptr(void *value, int flags, int fwidth)
{
    char *str = printf_get_unbr_base((long) (value), "0123456789abcdef");
    int len = my_strlen(str) + 2;
    int offset = 0;

    print_left_spaces(fwidth, len, flags);
    if (*str == '+' || *str == ' ') {
        my_putchar(*str);
        offset = 1;
    }
    my_putstr("0x");
    print_zeros(fwidth, len, flags);
    my_putstr(str + offset);
    print_right_spaces(fwidth, len, flags);
    free(str);
}