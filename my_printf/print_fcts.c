/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include "my.h"
#include "nbr.h"

void print_nb(void *value)
{
    nbr_t *nbr = (nbr_t*) value;

    my_put_nbr(nbr->sign);
}

void print_char(void *value)
{
    my_putchar(*((char*) (value)));
}

void print_str(void *value)
{
    my_putstr((char*) (value));
}

void print_fullstr(void *value)
{
    my_put_fullstr((char*) (value));
}

void print_ptr(void *value)
{
    my_putstr("0x");
    my_putnbr_base((long) (value), "0123456789abcdef");
}