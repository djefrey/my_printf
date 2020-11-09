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
    int offset = 0;

    if (flags & FLAG_ZERO && (str[0] == '+' || str[0] == '-')) {
        my_putchar(str[0]);
        offset = 1;
    }
    if (!(flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    my_putstr(str + offset);
    if ((flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    free(str);
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
    char *str = (char*) value;
    char c;
    char *nbr_str;
    int len;

    for (int i = 0; str[i]; i++) {
        c = str[i];
        if (c >= 32)
            my_putchar(c);
        else {
            my_putchar('\\');
            nbr_str = printf_get_unbr_base(c, "01234567", 0);
            len = my_strlen(nbr_str);
            for (int i = 3; i - len > 0; i--)
                my_putchar('0');
            my_putstr(nbr_str);
            free(nbr_str);
        }
    }
}

void print_ptr(void *value, int flags, int fwidth)
{
    char *str = printf_get_nbr_base((long) (value), "0123456789abcdef", 0);

    my_putstr("0x");
    my_putstr(str);
    free(str);
}