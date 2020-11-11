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

void print_unnb(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr(nbr->unsign);
    int len = my_strlen(str);

    print_zeros_or_spaces(fwidth, len, flags);
    my_putstr(str);
    print_right_spaces(fwidth, len, flags);
    free(str);
}

void print_octal(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "01234567");
    int len = my_strlen(str) + (flags & FLAG_HASHTAG);

    print_zeros_or_spaces(fwidth, len, flags);
    if (flags & FLAG_HASHTAG)
        my_putchar('0');
    my_putstr(str);
    print_right_spaces(fwidth, len, flags);
    free(str);
}

void print_binary(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "01");
    char len = my_strlen(str) + (flags & FLAG_HASHTAG);

    print_left_spaces(fwidth, len, flags);
    if (flags & FLAG_HASHTAG)
        my_putchar('b');
    print_zeros(fwidth, len, flags);
    my_putstr(str);
    print_right_spaces(fwidth, len, flags);
    free(str);
}

void print_hexa(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "0123456789abcdef");
    int len = my_strlen(str) + (flags & FLAG_HASHTAG) * 2;

    print_left_spaces(fwidth, len, flags);
    if (flags & FLAG_HASHTAG)
        my_putstr("0x");
    print_zeros(fwidth, len, flags);
    my_putstr(str);
    print_right_spaces(fwidth, len, flags);
    free(str);
}

void print_uphexa(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "0123456789ABCDEF");
    int len = my_strlen(str) + (flags & FLAG_HASHTAG) * 2;

    print_left_spaces(fwidth, len, flags);
    if (flags & FLAG_HASHTAG)
        my_putstr("0X");
    print_zeros(fwidth, len, flags);
    my_putstr(str);
    print_right_spaces(fwidth, len, flags);
    free(str);
}