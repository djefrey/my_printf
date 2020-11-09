/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include "my.h"
#include "nbr.h"
#include "flags.h"

void print_unnb(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;

    my_put_unnbr(nbr->unsign);
}

void print_octal(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;

    if (flags & FLAG_HASHTAG)
        my_putstr("0");
    my_putnbr_base(nbr->unsign, "01234567");
}

void print_binary(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;

    if (flags & FLAG_HASHTAG)
        my_putstr("b");
    my_putunnbr_base(nbr->unsign, "01");
}

void print_hexa(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;

    if (flags & FLAG_HASHTAG)
        my_putstr("0x");
    my_putunnbr_base(nbr->unsign, "0123456789abcdef");
}

void print_uphexa(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;

    if (flags & FLAG_HASHTAG)
        my_putstr("0X");
    my_putunnbr_base(nbr->unsign, "0123456789ABCDEF");
}