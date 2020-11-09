/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include "my.h"
#include "nbr.h"
#include "flags.h"
#include "printf_get_nbr.h"

void print_nb(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_nbr(nbr->sign, flags);
    int len = my_strlen(str);

    if (!(flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    my_putstr(str);
    if ((flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
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
    char *str = printf_get_nbr_base((long) (value), "0123456789abcdef", 0);

    my_putstr("0x");
    my_putstr(str);
}