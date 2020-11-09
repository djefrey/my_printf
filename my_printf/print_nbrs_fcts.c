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

void print_unnb(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr(nbr->unsign, flags);
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
    free(str);
}

void print_octal(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "01234567", flags);
    int len = my_strlen(str) + (flags & FLAG_HASHTAG);

    if (!(flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    if (flags & FLAG_HASHTAG)
        my_putstr("0");
    my_putstr(str);
    if ((flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    free(str);
}

void print_binary(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "01", flags);
    char len = my_strlen(str) + (flags & FLAG_HASHTAG);

    if (flags & FLAG_HASHTAG)
        my_putstr("b");
    if (!(flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    my_putstr(str);
    if ((flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    free(str);
}

void print_hexa(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "0123456789abcdef", flags);
    int len = my_strlen(str) + (flags & FLAG_HASHTAG) * 2;

    if (flags & FLAG_HASHTAG)
        my_putstr("0x");
    if (!(flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    my_putstr(str);
    if ((flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    free(str);
}

void print_uphexa(void *value, int flags, int fwidth)
{
    nbr_t *nbr = (nbr_t*) value;
    char *str = printf_get_unbr_base(nbr->unsign, "0123456789ABCDEF", flags);
    int len = my_strlen(str) + (flags & FLAG_HASHTAG) * 2;

    if (flags & FLAG_HASHTAG)
        my_putstr("0X");
    if (!(flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    my_putstr(str);
    if ((flags & FLAG_MINUS) && fwidth - len > 0) {
        for (int i = 0; i < fwidth - len; i++)
            my_putchar(flags & FLAG_ZERO ? '0' : ' ');
    }
    free(str);
}