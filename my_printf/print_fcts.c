/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include "my.h"
#include "nbr.h"
#include "flags.h"

void print_nb(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;

    my_put_nbr(nbr->sign);
}

void print_char(void *value, int flags, int fwidth)
{
    my_putchar(*((char*) (value)));
}

void print_str(void *value, int flags, int fwidth)
{
    my_putstr((char*) (value));
}

void print_fullstr(void *value, int flags, int fwidth)
{
    my_put_fullstr((char*) (value));
}

void print_ptr(void *value, int flags, int fwidth)
{
    my_putstr("0x");
    my_putnbr_base((long) (value), "0123456789abcdef");
}