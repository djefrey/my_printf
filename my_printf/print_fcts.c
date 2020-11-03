/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include "my.h"

void print_int(void *value)
{
    my_put_nbr(*((int*) (value)));
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
    // ?
}